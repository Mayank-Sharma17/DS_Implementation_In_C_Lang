#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void insert(int x) {
   if(rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    } else if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
        printf("Element %d is inserted\n", x);
    } else {
        rear++;
        queue[rear] = x;
        printf("Element %d is inserted\n", x);
    }
}

void delete() {
    int elem;
    if(front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        elem = queue[front];
        front++;
        if(front > rear) {
            front = rear = -1;
        }
        printf("element %d is deleted\n", elem);
    }
}

void peek() {
    if(front == -1 && rear == -1) {
        printf("Queue is Empty\n");
        return;
    } else {
        printf("elem is %d\n", queue[front]);
    }
}

void display() {
    int i;
    if(front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        for(int i=front; i <= rear; i++) {
            printf("%d ", queue[i]);   
        }
        printf("\n");
    }
}

int main() {
    while (1)
    {   
        printf("------------------------\n");
        printf("1. insert in the queue\n");
        printf("2. delete in the queue\n");
        printf("3. peek in the queue\n");
        printf("4. Display in the queue\n");
        printf("5. Exit in the queue\n");
        printf("------------------------\n");
        int choice;
        printf("Enter the choice : ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1: {
            int x;
            printf("Enter element : ");
            scanf("%d",&x);
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
            break;
        }
    }
    
    return 0;
}