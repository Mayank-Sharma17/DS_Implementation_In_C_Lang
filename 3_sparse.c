#include <stdio.h>

int main() {
    int A[7][6] = {
        {0,1,0,0,0,0},
        {0,0,0,0,0,0},
        {-2,0,0,1,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,-3,0,0,0,0},
        {0,0,0,0,0,1}
    };

    int B[10][3], k = 1;
    B[0][0] = 7;
    B[0][1] = 6;
    B[0][2] = 5;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            if (A[i][j] != 0) {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }

    printf("Sparse Matrix:\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", B[i][0], B[i][1], B[i][2]);
    }

    return 0;
}