#include <stdio.h>
#include <stdlib.h>

// create a array at run time
int* create(int elems) {
    int *arr = (int*)malloc(elems*sizeof(int));
    for(int i=0; i<elems; i++) {
        scanf("%d", arr+i);
    }
    return arr;
}

// insert an element in a given position 
int* insert(int *arr, int elems, int newelem, int pos) {
    arr = (int*)realloc(arr, (elems + 1) * sizeof(int));
    for(int i = elems; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = newelem;
    return arr;

}

// delete element from the array
int* delete(int *arr, int elems, int pos) {
    for(int i = pos; i < elems - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr = (int*)realloc(arr, (elems - 1) * sizeof(int));
    return arr;
}

void display(int *arr, int elems) {
    for(int i=0; i<elems; i++) {
        printf("%d ", *(arr+i));
    }
}

int main() {
    int elems, newelem, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &elems);

    int *ptrarr = create(elems);
    display(ptrarr, elems);

    printf("\nEnter the new element you want to insert: ");
    scanf("%d", &newelem);
    printf("Enter the index you want to insert: ");
    scanf("%d", &pos);
    ptrarr = insert(ptrarr, elems, newelem, pos);
    elems++;                      
    display(ptrarr, elems);

    printf("\nEnter the index of the element you want to delete: ");
    scanf("%d", &pos);
    ptrarr = delete(ptrarr, elems, pos);
    elems--;                       
    display(ptrarr, elems);

    free(ptrarr);
    return 0;
}