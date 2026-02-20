#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row, column;
    printf("Enter row and column = ");
    scanf("%d %d", &row, &column);
    int *arr[row]; // array of pointers
    int *arr1[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * column);
        arr1[i] = (int *)malloc(sizeof(int) * column);
    }
    printf("Enter element of first matrix = \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", (arr[i] + j));
        }
        printf("\n");
    }
    printf("Enter element of second matrix = \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", (arr1[i] + j));
        }
        printf("\n");
    }

    printf("Sum of matrix is :-\n");
    int result[row][column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[i][j] = (*(arr[i] + j)) + (*(arr1[i] + j));
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}