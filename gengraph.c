#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define USAGE fprintf(stderr, "Usage:\n\t %s -n NUM_VERTICES -e NUM_EDGES \
        NUM_GRAPHS\n", argv[0])

int picky_rand(char limit, char ignore) {
    int r = ignore;
    while (r == ignore) {
        r = rand() % limit;
    }
    return r;
}

char*
generate(char *graph, int vertices, int isomorph)
{
    graph[0] = vertices;
    for (int i = 0, pos = 1; i < vertices; i++, pos += graph[pos]) {
        graph[pos] = picky_rand(vertices, 0);
        for (int j = 1; j <= graph[pos]; j++) {
            graph[pos+j] = picky_rand(vertices, j);
        }
    }
}

void
print(char *graph) {
    int j;
    for (int i = 0, pos = 1; i < graph[0]; i++, pos += graph[pos]) {
        for (j = 1; j < graph[pos]; j++) {
            printf("%d ", graph[pos + j]);
        }
        printf("%d%c", graph[pos + j], (i == graph[0] - 1 ? '.' : ';'));
    }
}

int
main(int argc, char *argv[])
{
    int n, e, num_g, i;
    char c;

    n = e = num_g = i = -1;

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
    generate((char*) &graph, n, i);
    print((char*) &graph);

    return 0;
}
