#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront(int x)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is full.\n");
        return;
    }   
    else if(front == -1 && rear == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        front = MAX-1;
    }
    else {
        front--;
    }
    deque[front] = x;
    printf("Inserted %d at the front.\n", x); 
}

void insertRear(int x)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is full.\n");
        return;
    }
    else if(front == -1 && rear == -1) {
        front = rear = 0;
    } 
    else if(rear == MAX - 1) {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = x;
    printf("Inserted %d at the rear.\n", x);
}

void deleteFront()
{
    if(front == -1 && rear == -1) {
        printf("Deque is Empty.");
    } 
    else if(front == rear) { // only 1 elem in deque
        printf("Deleted %d from the front.\n", deque[front]);
        front = rear = -1;
    }
    else if(front == MAX - 1) {
        printf("Deleted %d from the front.\n", deque[front]);
        front = 0;
    }
    else {
        printf("Deleted %d from the front.\n", deque[front]);
        front++;
    }
}

void deleteRear()
{
 if(front == -1 && rear == -1) {
        printf("Deque is Empty.");
    } 
    else if(front == rear) { // only 1 elem in deque
        printf("Deleted %d from the rear.\n", deque[rear]);
        front = rear = -1;
    }
    else if(rear == 0) {
        printf("Deleted %d from the rear.\n", deque[rear]);
        rear = MAX-1;
    }
    else {
        printf("Deleted %d from the rear.\n", deque[rear]);
        rear--;
    }
}

void displayDeque()
{
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i+1)%MAX;
    }
    printf("%d", deque[rear]);
    printf("\n");    
}

int main()
{
    insertRear(5);
    displayDeque();

    insertFront(15);
    displayDeque();

    insertRear(25);
    displayDeque();

    deleteFront();
    displayDeque();

    deleteRear();
    displayDeque();

    return 0;
}