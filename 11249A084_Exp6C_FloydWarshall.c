#include <stdio.h>

#define N 3

void floyds(int b[N][N]) {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (b[i][k] && b[k][j] && i != j)
                    if (b[i][k] + b[k][j] < b[i][j] || b[i][j] == 0)
                        b[i][j] = b[i][k] + b[k][j];

    printf("Shortest distances between all pairs:\n\n");
    printf("     ");
    for (int i = 0; i < N; i++)
        printf("%c    ", 'A' + i);
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < N; j++) {
            if (b[i][j] == 0 && i != j)
                printf("INF  ");
            else
                printf("%-5d", b[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int b[N][N] = {
        { 0, 10,  0},
        { 0,  0, 15},
        {12,  0,  0}
    };
    floyds(b);
    return 0;
}
