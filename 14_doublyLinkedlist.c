#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;
node *head;

void create() {
    int choice;
    head = NULL;
    node *newnode, *temp;

    while (choice)
    {
        newnode = (node*)malloc(sizeof(node));
        
        printf("Enter data : ");
        scanf("%d", &newnode->data);
    
        newnode->prev = NULL;
        newnode->next = NULL;
    
        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Enter choice : ");
        scanf("%d", &choice);
    }
}

void insertBegin() {
    node *ptr, *temp;
    temp = head;
    ptr = (node*)malloc(sizeof(node));
    printf("\nEnter data : ");
    scanf("%d", &ptr->data);

    ptr->next = NULL;
    ptr->prev = NULL;

    if(head == NULL) {
        head = ptr;
    } else {
        head = ptr;
        ptr->next = temp;
        temp->prev = ptr; 
    }
}

void insertEnd() {
    node *ptr, *temp = head;
    ptr = (node*)malloc(sizeof(node));
    printf("\nEnter data : ");
    scanf("%d", &ptr->data);

    ptr->next = NULL;
    ptr->prev = NULL;

    if(head == NULL) {
        head = ptr;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void insertMid() {
    int pos, i;
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    node *ptr, *temp = head;
    ptr = (node *)malloc(sizeof(node));
    printf("Enter data : ");
    scanf("%d", &ptr->data);

    ptr->next = NULL;
    ptr->prev = NULL;

    if(pos == 1) {
        head = ptr;
        ptr->next = temp;
        temp->prev = ptr;
    } else {
        for(i = 1; i < pos-1 && temp != NULL; i++) {
            temp = temp->next;
        } 
        ptr->next = temp->next;
        temp->next->prev = ptr;
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void display() {
    node *temp = head;
    printf("\nList content : ");
    while (temp != NULL)
    {   
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    printf("\n");
}

int main() {
    create();
    display();
    
    insertBegin();
    display();
    
    insertBegin();
    display();

    insertEnd();
    display();    

    insertMid();
    display();
    return 0;
}