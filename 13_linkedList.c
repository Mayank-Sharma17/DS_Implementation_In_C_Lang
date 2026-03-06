#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *head = NULL;

NODE *getnode() {
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    printf("Enter data : ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    return ptr;
}

void createList(int n) {
    NODE *ptr, *temp;
    for(int i=0; i<n; i++) {
        ptr = getnode();
        if(head == NULL) {
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
}

void insertBegin() {
    printf("\nInsert at begin\n");
    NODE *ptr;
    ptr = getnode();
    if(head == NULL) {
        head = ptr;
    } else {
        ptr->next = head;
        head = ptr;
    }
}

void insertEnd() {
    printf("\nInsert at End\n");
    NODE *ptr, *temp;
    ptr = getnode();
    if(head == NULL) {
        head = ptr;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void insertSpec() {
    int pos, i;
    NODE *ptr, *temp;
    printf("\nEnter position of new node : ");
    scanf("%d", &pos);
    if (pos == 1) {
        insertBegin();
        return;
    }

    temp = head;
    for(i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }
    ptr = getnode();
    ptr->next = temp->next;
    temp->next = ptr;
}

void deleteFirst() {
    NODE *temp;
    if(head == NULL) {
        printf("\nNo node exists\n");
        return;
    }
    temp = head;
    head = temp->next;
    free(temp);
}

void deleteLast() {
    NODE *temp, *prev;
    if(head == NULL) {
        printf("\nNo node exists\n");
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteSpec() {
    int pos, i;
    NODE *temp, *prev;
    if(head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    if(pos == 1) {
        deleteFirst();
        return;
    }
    temp = head;
    for(i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}


void traverseList() {
    NODE *temp;
    temp = head;
    printf("\nList content : ");
    if(head == NULL) {
        printf("List is Empty.\n");
    } else {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("\nEnter number of nodes you want to insert : ");
    scanf("%d", &n);
    
    createList(n);
    traverseList();

    insertBegin();
    traverseList();

    insertEnd();
    traverseList();

    insertSpec();
    traverseList();

    deleteFirst();
    traverseList();

    deleteLast();
    traverseList();

    deleteSpec();
    traverseList();
    return 0;
}