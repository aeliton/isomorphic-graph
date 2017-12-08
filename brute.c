#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VERT 13

void read(char *g) {
    int v;
    for (int i = 0; i<10; i++) {
        while (scanf("%d", &v) == 1) {
            *(g + i * 10 + v) = 1;
        }
        if (getchar() == '.')
            break;
    }
}

void print(char *g) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", *(g + i * 10 + j));
        }
        puts("");
    }
}

int verify(char *g1, char *g2, char *solution) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (*(g1 + i * 10 + j) != *(g2 + (solution[i]) * 10 + (solution[j]))) {
                return 0;
            }
        }
    }

    return 1;
}

int brute(char *g1, char *g2, char* symbols, char *map, int size, int available) {
    // for each vertice in g2, try to map it to g1:0 
    if (available == 0) {
        return verify(g1, g2, map);
    }

    for (int i = 0; i < size; i++) {
        if (symbols[i] != ' ') {
            char sym = symbols[i];
            symbols[i] = ' ';
            map[size - available] = sym;
            if (brute(g1, g2, symbols, map, size, available - 1)) {
                symbols[i] = sym;
                return 1;
            }
            symbols[i] = sym;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    char g1[MAX_VERT][MAX_VERT];
    char g2[MAX_VERT][MAX_VERT];

    char symbols[MAX_VERT];
    char map[MAX_VERT];

    memset(&g1, 0, sizeof(g1));
    memset(&g2, 0, sizeof(g2));
    memset(&symbols, 0, MAX_VERT);
    memset(&map, 0, MAX_VERT);

    read((char*) &g1);
    read((char*) &g2);

    for (int i = 0; i < 10; i++) {
        symbols[i] = i;
    }

    if (brute((char*) g1, (char*) g2, symbols, map, 10, 10)) {
        for (int i = 0; i < 10; i++) {
            printf("%d -> %d\n", i, map[i]);
        }
    } else {
        printf("not isomorphic\n");
    }

    return 0;
}
