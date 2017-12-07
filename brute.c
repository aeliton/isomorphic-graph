#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

char g1[10][10];
char g2[10][10];

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
            if (*(g1 + i * 10 + j) != *(g2 + (solution[i] - '0') * 10 + (solution[j] - '0'))) {
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
    read((char*) &g1);
    read((char*) &g2);
    /*print((char*) &g1);
    print((char*) &g2);*/

    char symbols[11];
    char map[11];

    memset(&symbols, 0, sizeof(symbols));
    memset(&map, 0, sizeof(map));

    for (int i = 0; i < 10; i++) {
        symbols[i] = '0' + i;
    }

    if (brute((char*) g1, (char*) g2, symbols, map, 10, 10)) {
        for (int i = 0; i < 10; i++) {
            printf("%d -> %d\n", i, map[i] - '0');
        }
    } else {
        printf("not isomorphic\n");
    }

    return 0;
}
