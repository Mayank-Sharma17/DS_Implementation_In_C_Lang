#include <stdio.h>
int main() {
    // 1D Array
    int a[5];
    int i = 2;
    int *ba1 = &a[0];

    printf("1D Array:\n");
    printf("Calculated Address = %u\n", ba1 + i);
    printf("Actual Address     = %u\n\n", &a[i]);

    // 2D Array
    int b[3][4];
    int r = 1, c = 2;
    int *ba2 = &b[0][0];
    int cols = 4;

    printf("2D Array:\n");
    printf("Calculated Address = %u\n",
           ba2 + (r * cols + c));
    printf("Actual Address     = %u\n\n",
           &b[r][c]);

    // 3D Array
    int d[2][3][4];
    int x = 1, y = 1, z = 2;
    int *ba3 = &d[0][0][0];
    int n2 = 3, n3 = 4;

    printf("3D Array:\n");
    printf("Calculated Address = %u\n",
           ba3 + (x * n2 * n3 + y * n3 + z));
    printf("Actual Address     = %u\n",
           &d[x][y][z]);

    return 0;
}
