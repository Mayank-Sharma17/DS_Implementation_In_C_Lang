#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check multiplication condition
    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    // DMA: array of pointers
    int *A[r1], *B[r2], *C[r1];

    for (int i = 0; i < r1; i++)
        A[i] = (int *)malloc(sizeof(int) * c1);

    for (int i = 0; i < r2; i++)
        B[i] = (int *)malloc(sizeof(int) * c2);

    for (int i = 0; i < r1; i++)
        C[i] = (int *)malloc(sizeof(int) * c2);

    // Input matrix A
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", A[i] + j);
        }
    }

    // Input matrix B
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", B[i] + j);
        }
    }

    // Initialize result matrix with 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(C[i] + j) = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < r1; i++) { // fix row
        for (int j = 0; j < c2; j++) { // fix column
            for (int k = 0; k < c1; k++) { // walk through the row i and col j
                *(C[i] + j) += (*(A[i] + k)) * (*(B[k] + j));
            }
        }
    }

    // Print result
    printf("Resultant matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", *(C[i] + j));
        }
        printf("\n");
    }

    return 0;
}
