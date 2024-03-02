#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node *link;
} nodeType, *LIST;

void initList(LIST *L);
void insertFirst(LIST *L, int data);
void insertLast(LIST *L, int data);
void insertSorted(LIST *L, int data);
void deleteFirst(LIST *L);
void deleteLast(LIST *L);
void display(LIST L);

int main(){
    LIST shannen;

    initList(&shannen);
    insertSorted(&shannen, 2);
    insertSorted(&shannen, 5);
    insertSorted(&shannen, 30);
    insertSorted(&shannen, 21);
    insertSorted(&shannen, 3);

    display(shannen);

    deleteFirst(&shannen);
    deleteLast(&shannen);

    display(shannen);

    return 0;
}

void initList(LIST *L){
    *L = NULL;
}

void insertFirst(LIST *L, int data){
    LIST newNode = (LIST)malloc(sizeof(nodeType));
    if(newNode != NULL){
        newNode->elem = data;
        newNode->link = *L;
        *L = newNode;
    }
}

void insertLast(LIST *L, int data){
    LIST *trav;

    for(trav = L; *trav != NULL; trav = &(*trav)->link){}

    LIST newNode = (LIST)malloc(sizeof(nodeType));
    if(newNode != NULL){
        newNode->elem = data;
        newNode->link = NULL;
        *trav = newNode;
    }
}

void deleteFirst(LIST *L){
    LIST temp;

    temp = *L;
    *L = temp->link;
    free(temp);
}

void deleteLast(LIST *L){
    LIST temp, *trav;

    for(trav = L; (*trav)->link != NULL; trav = &(*trav)->link){}

    temp = *trav;
    *trav = NULL;
    free(temp);
}

void display(LIST L){
    LIST trav;

    for(trav = L; trav != NULL; trav = trav->link){
        printf("%d ", trav->elem);
    }
    printf("\n");
}

void insertSorted(LIST *L, int data){
    LIST *trav;

    for(trav = L; *trav != NULL && (*trav)->elem < data; trav = &(*trav)->link){}

    LIST newNode = (LIST)malloc(sizeof(nodeType));
    if(newNode != NULL){
        newNode->elem = data;
        newNode->link = *trav;
        *trav = newNode;
    }
}