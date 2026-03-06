#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int arr[MAX];
int topA = -1;
int topB = MAX;

void pushA(int x) {
    if (topA + 1 == topB) {
        printf("Stack Overflow\n");
        return;
    }
    arr[++topA] = x;
    printf("Inserted %d into Stack A\n", x);
}
void popA() {
    if (topA == -1) {
        printf("Stack A Underflow\n");
        return;
    }
    printf("Deleted %d from Stack A\n", arr[topA--]);
}
void peekA() {
    if (topA == -1) {
        printf("Stack A is Empty\n");
        return;
    }
    printf("Top of Stack A: %d\n", arr[topA]);
}
void displayA() {
    if (topA == -1) {
        printf("Stack A is Empty\n");
        return;
    }

    printf("Stack A elements: ");
    for (int i = topA; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");
}


void pushB(int x) {
    if (topA + 1 == topB) {
        printf("Stack Overflow\n");
        return;
    }
    arr[--topB] = x;
    printf("Inserted %d into Stack B\n", x);
}
void popB() {
    if (topB == MAX) {
        printf("Stack B Underflow\n");
        return;
    }
    printf("Deleted %d from Stack B\n", arr[topB++]);
}
void peekB() {
    if (topB == MAX) {
        printf("Stack B is Empty\n");
        return;
    }
    printf("Top of Stack B: %d\n", arr[topB]);
}
void displayB() {
    if (topB == MAX) {
        printf("Stack B is Empty\n");
        return;
    }

    printf("Stack B elements: ");
    for (int i = topB; i < MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n----------------------\n");
        printf("1. Push in Stack A\n");
        printf("2. Push in Stack B\n");
        printf("3. Pop from Stack A\n");
        printf("4. Pop from Stack B\n");
        printf("5. Peek Stack A\n");
        printf("6. Peek Stack B\n");
        printf("7. Display Stack A\n");
        printf("8. Display Stack B\n");
        printf("9. Exit\n");
        printf("----------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                pushA(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                pushB(value);
                break;

            case 3:
                popA();
                break;

            case 4:
                popB();
                break;

            case 5:
                peekA();
                break;

            case 6:
                peekB();
                break;

            case 7:
                displayA();
                break;

            case 8:
                displayB();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}