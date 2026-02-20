#include <stdio.h>
#include <stdlib.h>
int TOP = -1;

void push(int stack[], int size)
{
    if (TOP == size - 1)
    {
        printf("Overflow\n");
        return;
    }
    int elem;
    printf("Enter the element : ");
    scanf("%d", &elem);
    TOP++;
    stack[TOP] = elem;
    printf("puhsed %d in stack at %d\n", elem, TOP);
}

void pop(int arr[])
{
    if (TOP == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("%d is deleted!\n", arr[TOP]);
    TOP--;
}

void peek(int arr[])
{
    if (TOP < 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("%d\n", arr[TOP]);
}

void display(int arr[], int size)
{
    int temp = TOP;
    if (temp < 0)
    {
        printf("Underflow\n");
        return;
    }
    while (temp >= 0)
    {
        printf("%d ", arr[temp]);
        temp--;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array = ");
    scanf("%d", &n);
    int arr[n];

    while (1)
    {
        int choice, elem;
        printf("--------------------------\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("5. exit\n");
        printf("--------------------------\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            push(arr, n);
            break;
        }
        case 2:
        {
            pop(arr);
            break;
        }
        case 3:
        {
            peek(arr);
            break;
        }
        case 4:
        {
            display(arr, n);
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
            break;
        }
    }

    return 0;
}