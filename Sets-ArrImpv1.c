#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int SET[MAX];

SET *Union(SET A, SET B);
SET *Intersection(SET A, SET B);
SET *Difference(SET A, SET B);
void initSet(SET *A);
void insert(SET *A, int ndx);
void delete(SET *A, int ndx);
void display(SET A);
void populateA(SET *A);
void populateB(SET *B);
int isMember(SET A, int ndx);

int main(){
    SET A, B;
    initSet(&A);
    initSet(&B);

    populateA(&A);
    populateB(&B);
    display(A);
    display(B);

    SET *C = Intersection(A, B);
    display(*C);
    printf("Is a Member?: %d", isMember(*C, 4));
    free(*C);

    return 0;
}

SET *Union(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET));
    
    if(C != NULL){
        int x;
        for(x = 0; x < MAX; x++){
            if(A[x] || B[x]){
                (*C)[x] = 1;
            } else{
                (*C)[x] = 0;
            }
        }
    }
    return C;
}

SET *Intersection(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET));
    
    if(C != NULL){
        int x;
        for(x = 0; x < MAX; x++){
            if(A[x] && B[x]){
                (*C)[x] = 1;
            } else{
                (*C)[x] = 0;
            }
        }
    }
    return C;
}

SET *Difference(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET));
    
    if(C != NULL){
        int x;
        for(x = 0; x < MAX; x++){
            if(A[x] == 1 && A[x] != B[x]){
                (*C)[x] = 1;
            } else{
                (*C)[x] = 0;
            }
        }
    }
    return C;
}

void initSet(SET *A){
    int x;
    for(x = 0; x < MAX; x++){
        (*A)[x] = 0;
    }
}

void insert(SET *A, int ndx){
    if(ndx < MAX && ndx >= 0){
        (*A)[ndx] = 1;
    }
}

void delete(SET *A, int ndx){
    if(ndx < MAX && ndx >= 0){
        (*A)[ndx] = 0;
    }
}

void display(SET A){
    int x;
    printf("\n");
    for(x = 0; x < MAX; x++){
        printf("%d ", A[x]);
    }
    printf("\n");
}

void populateA(SET *A){
    insert(A, 4);
    insert(A, 2);
    insert(A, 1);
}

void populateB(SET *B){
    insert(B, 4);
    insert(B, 3);
    insert(B, 0);
}

int isMember(SET A, int ndx){
    return A[ndx] == 1 ? 1 : 0;
}