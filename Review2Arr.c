#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int count;
} LIST;

void initArrList(LIST *A);
void insertFirst(LIST *A, int data);
void insertLast(LIST *A, int data);
void deleteFirst(LIST *A);
void deleteLast(LIST *A);
void displayList(LIST A);

int main(){
    LIST myList;
    initArrList(&myList);

    insertFirst(&myList, 10);
    insertFirst(&myList, 20);
    insertLast(&myList, 5);
    displayList(myList);

    return 0;
}

void initArrList(LIST *A){
    A->count = 0;
}

void insertFirst(LIST *A, int data){
    int x;

    if(A->count != MAX){
        for(x = A->count; x > 0; x--){
            A->data[x] = A->data[x - 1];
        }
        A->data[x] = data;
        A->count++;
    }
}

void insertLast(LIST *A, int data){
    if(A->count != MAX){
        A->data[A->count] = data;
        A->count++;
    }
}

void deleteFirst(LIST *A){
    if(A->count > 0){
        int x;
        A->count--;
        for(x = 0; x < A->count; x++){
            A->data[x] = A->data[x + 1];
        }
    }
}

void deleteLast(LIST *A){
    if(A->count > 0){
        A->count--;
    }
}

void displayList(LIST A){
    int x;
    for(x = 0; x < A.count; x++){
        printf("%d ", A.data[x]);
    }
    printf("\n\n");
}