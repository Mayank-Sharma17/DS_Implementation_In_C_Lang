#include <stdio.h>
int main() {
    int P1[5] = {5, -3, 0, 0, 1};
    int P2[5] = {2, 5, -1, -1, 1};
    int sum[5], diff[5];

    for (int i = 0; i < 5; i++) {
        sum[i] = P1[i] + P2[i];
        diff[i] = P1[i] - P2[i];
    }

    printf("Sum coefficients:\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", sum[i]);

    printf("\nDifference coefficients:\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", diff[i]);

    return 0;
}