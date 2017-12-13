#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>

#define USAGE fprintf(stderr, "Usage:\n\t %s -n NUM_VERTICES -e NUM_EDGES \
        NUM_GRAPHS\n", argv[0])

int
picky_rand(char limit, char ignore) {
    int r = ignore;
    while (r == ignore) {
        r = rand() % limit;
    }
    return r;
}

char*
picky_rand_set(char *set, char amount, char limit, char ignore) {
    char used[CHAR_MAX];
    int i, r;
    memset(&used, 0, sizeof(used));

    for (i = 0, r; i < amount; i++) {
        r = rand() % limit;
        while (used[r] || r == ignore) r = (r + 1) % limit;
        set[i] = r;
        used[r] = 1;
    }
    set[i] = -1;

    return set;
}

char*
generate(char *graph, int vertices)
{
    graph[0] = vertices;
    for (int i = 0, pos = 1; i < vertices; i++, pos += graph[pos] + 1) {
        graph[pos] = picky_rand(vertices, 0);
        char set[CHAR_MAX];
        picky_rand_set((char*) &set, graph[pos], vertices, i);

        for (int j = 0; set[j] > -1; j++) {
            graph[pos + j + 1] = set[j];
        }
    }
}

char *
isomorph(char *iso, char *graph) {
    char map[CHAR_MAX];
    char used[CHAR_MAX];
    char vertex_pos[CHAR_MAX];

    for (int i = 0, pos = 1; i < graph[0]; i++, pos += graph[pos] + 1) {
        vertex_pos[i] = pos;
    }

    memset(&used, 0, sizeof(used));
    picky_rand_set((char*) &map, graph[0], graph[0], -1);
    for (int i = 0; i < graph[0]; i++) {
        if (!used[i] && used[map[i]]) {
            map[i] = i;
        } else {
            used[i] = 1;
            used[map[i]] = 1;
            map[map[i]] = i;
        }
    }

    iso[0] = graph[0];
    int j;
    for (int i = 0, pos = 1; i < graph[0]; i++, pos += iso[pos] + 1) {
        iso[pos] = graph[vertex_pos[map[i]]];
        for (j = 1; j <= iso[pos]; j++) {
            iso[pos + j] = map[graph[vertex_pos[map[i]] + j]];
        }
    }

    return iso;
}

void
print(char *graph) {
    int j;
    for (int i = 0, pos = 1; i < graph[0]; i++, pos += graph[pos] + 1) {
        for (j = 1; j < graph[pos]; j++) {
            printf("%d ", graph[pos + j]);
        }
        printf("%d%c", graph[pos + j], (i == graph[0] - 1 ? '.' : ';'));
    }
    printf("\n");
}

int
main(int argc, char *argv[])
{
    int n, e, num_g, gen_isomorphic;
    char c;

    n = e = num_g = gen_isomorphic = 0;

    while ((c = getopt(argc, argv, "n:e:i")) != -1) {
        switch(c) {
            case 'n':
                if (!sscanf(optarg, "%d", &n)) {
                    fprintf(stderr, "Invalid option for '%c': %s\n", c, optarg);
                    opterr++;
                }
                break;
            case 'e':
                if (!sscanf(optarg, "%d", &e)) {
                    fprintf(stderr, "Invalid option for '%c': %s\n", c, optarg);
                    opterr++;
                }
                break;
            case 'i':
                gen_isomorphic = 1;
            case '?':
                fprintf(stderr, "Unrecognized option: '-%c'\n", optopt);
                break;
        }
    }

    if (optind == argc || !sscanf(argv[optind], "%d", &num_g)) {
        USAGE;
        exit(1);
    }

    srand(time(NULL));

    char graph[256];
    char iso[256];

    for (int i = 0; i < num_g; i++) {
        memset(&graph, -1, sizeof(graph));
        generate((char*) &graph, n);

        print((char*) &graph);
        if (gen_isomorphic) {
            print(isomorph((char*) &iso, (char*) &graph));
        }
        putchar('\n');
    }

    return 0;
}
