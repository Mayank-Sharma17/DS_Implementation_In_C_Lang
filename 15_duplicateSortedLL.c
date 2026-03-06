#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL, *temp;

void create()
{
    node *ptr;
    ptr = malloc(sizeof(node));

    printf("\nEnter data : ");
    scanf("%d", &ptr->data);

    ptr->next = NULL;
    if (head == NULL)
    {
        head = temp = ptr;
    }
    else
    {
        temp->next = ptr;
        temp = ptr;
    }
}

void display()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nlist content : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void deleteDup()
{
    node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            node *del = temp->next;
            temp->next = del->next;
            free(del);
        }
        else
        {
            temp = temp->next;
        }
    }
}

int main()
{
    while (1)
    {
        printf("\n------------------");
        printf("\n1. create");
        printf("\n2. display");
        printf("\n3. delete duplicate");
        printf("\n4. exit");
        printf("\n------------------");
        int choice;
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            deleteDup();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}