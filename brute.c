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

int verify() {
    return 0;
}

int brute(char* symbols, char *map, int size, int available) {
    // for each vertice in g2, try to map it to g1:0 
    if (available == 0) {
        printf("[%s] [%s]\n", symbols, map);
        verify();
        return 0;
    }

    for (int i = 0; i < size; i++) {
        if (symbols[i] != ' ') {
            char sym = symbols[i];
            symbols[i] = ' ';
            map[size - available] = sym;
            brute(symbols, map, size, available - 1);
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

    brute(symbols, map, 10, 10);

    // print graphs function
    // generate signature for g1
    // generate signature each vertice of g2 and compare with g1 signature
    // -> match: print the correpondece
    // -> not match: print not isomorphic
    
    return 0;
}
