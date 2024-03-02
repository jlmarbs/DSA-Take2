//I LOVE SHANNEN!!!!
#include <stdio.h>
#define MAX 10

typedef struct{
    int elem;
    int link;
} nodeType;

typedef struct{
    nodeType Node[MAX];
    int avail;
} VHeap;

typedef int CLIST;

void initVHeap(VHeap *VH);
void initCList(CLIST *CL);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int ndx);
void insertFirst(CLIST *CL, VHeap *VH, int data);
void insertLast(CLIST *CL, VHeap *VH, int data);
void insertSorted(CLIST *CL, VHeap *VH, int data);
void deleteFirst(CLIST *CL, VHeap *VH);
void deleteLast(CLIST *CL, VHeap *VH);
void display(CLIST CL, VHeap VH);

int main(){

    CLIST C;
    VHeap V;

    initVHeap(&V);
    initCList(&C);

    insertSorted(&C, &V, 10);
    insertSorted(&C, &V, 20);
    insertSorted(&C, &V, 30);
    insertSorted(&C, &V, 25);
    insertSorted(&C, &V, 40);
    insertSorted(&C, &V, 50);

    display(C, V);

    deleteFirst(&C, &V);
    deleteLast(&C, &V);

    display(C, V);

    return 0;
}

void initVHeap(VHeap *VH){
    int x;
    VH->avail = 0;

    for(x = 0; x < MAX - 1; x++){
        VH->Node[x].link = x + 1;
    }
    VH->Node[x].link = -1;
}

void initCList(CLIST *CL){
    *CL = -1;
}

int allocSpace(VHeap *VH){
    int retval = VH->avail;

    if(retval != -1){
        VH->avail = VH->Node[retval].link;
    }
    return retval;
}

void deallocSpace(VHeap *VH, int ndx){
    if(ndx >= 0 && ndx < MAX){
        VH->Node[ndx].link = VH->avail;
        VH->avail = ndx;
    }
}

void insertFirst(CLIST *CL, VHeap *VH, int data){
    int ndx = allocSpace(VH);
    if(ndx != -1){
        VH->Node[ndx].elem = data;
        VH->Node[ndx].link = *CL;
        *CL = ndx;
    }
}

void insertSorted(CLIST *CL, VHeap *VH, int data){

    int ndx = allocSpace(VH);
    if(ndx != -1){
        VH->Node[ndx].elem = data;

        CLIST *trav;
        for(trav = CL; *trav != -1 && VH->Node[*trav].elem < data; trav = &(VH->Node[*trav].link)){}

        VH->Node[ndx].link = *trav;
        *trav = ndx;
    }
}

void insertLast(CLIST *CL, VHeap *VH, int data){
    int ndx = allocSpace(VH);
    if(ndx != -1){
        VH->Node[ndx].elem = data;
        VH->Node[ndx].link = -1;
        if(*CL == -1){
            *CL = ndx;
        } else{
            CLIST *trav;
            
            for(trav = CL; *trav != -1; trav = &(VH->Node[*trav].link)){}
            *trav = ndx;
        }
    }
}

void display(CLIST CL, VHeap VH){
    CLIST trav;

    for(trav = CL; trav != -1; trav = VH.Node[trav].link){
        printf("%d ", VH.Node[trav].elem);
    }
    printf("\n");
}

void deleteFirst(CLIST *CL, VHeap *VH){
    CLIST temp;

    temp = *CL;
    *CL = VH->Node[temp].link;
    deallocSpace(VH, temp);
}

void deleteLast(CLIST *CL, VHeap *VH){
    CLIST temp, *trav;

    for(trav = CL; VH->Node[*trav].link != -1; trav = &(VH->Node[*trav].link)){}

    temp = *trav;
    *trav = -1;
    deallocSpace(VH, temp);
}