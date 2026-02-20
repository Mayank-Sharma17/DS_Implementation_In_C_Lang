#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr[n];   // array of pointers

    // Allocate memory and input values
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(sizeof(int));

        printf("Enter value %d: ", i + 1);
        scanf("%d", arr[i]);   // arr[i] is already an address
    }

    // Print values
    printf("You entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *arr[i]);   // dereference to get value
    }

    return 0;
}
