#include <stdio.h>
#include <string.h>

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

int main(int argc, char *argv[])
{
    read((char*)&g1);
    read((char*)&g2);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", g1[i][j]);
        }
        puts("");
    }
    puts("");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", g2[i][j]);
        }
        puts("");
    }

    // print graphs function
    // generate signature for g1
    // generate signature each vertice of g2 and compare with g1 signature
    // -> match: print the correpondece
    // -> not match: print not isomorphic
    
    return 0;
}
