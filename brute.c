#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_VERT 13

typedef struct graph {
    int n;
    char adj[MAX_VERT][MAX_VERT];
} graph_t;

void read(graph_t *g) {
    int v;

    memset(g, 0, sizeof(graph_t));
    for (; ;) {
        while (scanf("%d", &v) == 1) {
            g->adj[g->n][v] = 1;
        }
        ++(g->n);
        if (getchar() == '.')
            break;
    }
}

void print(graph_t g) {
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            printf("%d ", g.adj[i][j]);
        }
        puts("");
    }
}

int verify(graph_t g1, graph_t g2, char *solution) {
    for (int i = 0; i < g1.n; i++) {
        for (int j = 0; j < g1.n; j++) {
            if (g1.adj[i][j] != g2.adj[solution[i]][solution[j]]) {
                return 0;
            }
        }
    }
    return 1;
}

int brute(graph_t g1, graph_t g2, char *symbols, char *mapping, int available) {
    if (available == 0) {
        return verify(g1, g2, mapping);
    }
    for (int i = 0; i < g1.n; i++) {
        if (symbols[i] < 0) {
            continue;
        }
        char sym = symbols[i];
        symbols[i] = -1;
        mapping[g1.n- available] = sym;
        if (brute(g1, g2, symbols, mapping, available - 1)) {
            symbols[i] = sym;
            return 1;
        }
        symbols[i] = sym;
    }
    return 0;
}

int isomorphic(graph_t g1, graph_t g2, char *mapping) {
    if (g1.n != g2.n) {
        return 0;
    }
    char symbols[MAX_VERT];
    for (int i = 0; i < MAX_VERT; i++) {
        symbols[i] = i;
    }
    return brute(g1, g2, symbols, mapping, g1.n);
}

int main(int argc, char *argv[])
{
    char mapping[MAX_VERT];
    graph_t g1;
    graph_t g2;
    struct rusage before;
    struct rusage after;

    memset(&mapping, 0, MAX_VERT);

    read(&g1);
    read(&g2);

    getrusage(RUSAGE_SELF, &before);
    int is_isomorphic = isomorphic(g1, g2, mapping);
    getrusage(RUSAGE_SELF, &after);

    if (is_isomorphic) {
        printf("%3s -> %3s\n", "G1", "G2");
        for (int i = 0; i < g1.n; i++) {
            printf("%3d -> %3d\n", i, mapping[i]);
        }
    } else {
        printf("not isomorphic\n");
    }
    long elapsed = after.ru_utime.tv_sec - before.ru_utime.tv_sec * 1000000L;
    elapsed =+ (after.ru_utime.tv_usec - before.ru_utime.tv_usec);
    printf("CPU time: %lf\n", elapsed/(double)1000000.0);

    return 0;
}
