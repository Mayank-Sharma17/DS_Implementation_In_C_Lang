#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int x) {
    if((rear+1)%MAX == front) {
        printf("Queue is Full\n");
    }
    else if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
        printf("Element %d is inserted\n", x);
    }
    else {
        rear = (rear+1)%MAX;
        queue[rear] = x;
        printf("Element %d is inserted\n", x);
    }
}

void delete() {
    if(front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    }
    else if(front == rear) {
        printf("Element %d is deleted\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Element %d is deleted\n", queue[front]);
        front = (front+1)%MAX;
    }
}

void peek() {
    if(front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

void display() {
    if(front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    }
    int i=front;
    while (i != rear) {
        printf("%d ", queue[front]);
        i = (i+1)%MAX;
    }
    printf("%d", queue[i]); // remaining 1 elem
    printf("\n");
}

int main() {
    while(1) {

        printf("\n------------------------\n");
        printf("1. Insert in the queue\n");
        printf("2. Delete from the queue\n");
        printf("3. Peek in the queue\n");
        printf("4. Display the queue\n");
        printf("5. Exit\n");
        printf("------------------------\n");

        int choice;
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: {
                int x;
                printf("Enter element : ");
                scanf("%d", &x);
                insert(x);
                break;
            }

            case 2:
                delete();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
