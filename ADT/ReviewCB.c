#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int elem;
    int link;
} nodeType;

typedef struct{
    nodeType Node[MAX];
    int avail;
} VHeap;

typedef int CList;

void initCList(CList *CL);
void initVHeap(VHeap *VH);
void populateList(VHeap *VH, CList *CL);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int ndx);
void insertFirst(VHeap *VH, CList *CL, int data);
void insertLast(VHeap* VH, CList *CL, int data);
void deleteFirst(VHeap *VH, CList *CL);
void deleteLast(VHeap *VH, CList *CL);
void displayList(VHeap VH, CList CL);

int main(){
    CList jasper;
    VHeap shannen;

    initCList(&jasper);
    initVHeap(&shannen);

    insertFirst(&shannen, &jasper, 21);
    displayList(shannen, jasper);

    insertFirst(&shannen, &jasper, 12);
    insertLast(&shannen, &jasper, 143);
    displayList(shannen, jasper);

    insertLast(&shannen, &jasper, 321);
    displayList(shannen, jasper);

    deleteFirst(&shannen, &jasper);
    displayList(shannen, jasper);

    deleteLast(&shannen, &jasper);
    displayList(shannen, jasper);

    return 0;
}

void initCList(CList *CL){
    *CL = -1;
}

void initVHeap(VHeap *VH){
    VH->avail = MAX - 1;
    int x;

    for(x = VH->avail; x >= 0; x--){
        VH->Node[x].link = x - 1;
    }
}

int allocSpace(VHeap *VH){
    int retVal = VH->avail;

    if(retVal != -1){
        VH->avail = VH->Node[retVal].link;
    }
    return retVal;
}

void deallocSpace(VHeap *VH, int ndx){
    if(ndx >= 0 && ndx < MAX){
        VH->Node[ndx].link = VH->avail;
        VH->avail = ndx;
    }
}

void displayList(VHeap VH, CList CL){
    int x;

    for(x = CL; x != -1; x = VH.Node[x].link){
        printf("%d ", VH.Node[x].elem);
    }
    printf("\n\n");
}

void insertFirst(VHeap *VH, CList *CL, int data){
    int ndx = allocSpace(VH);
    if(ndx != -1){
        VH->Node[ndx].elem = data;
        VH->Node[ndx].link = *CL;
        *CL = ndx;
    }
}

void insertLast(VHeap *VH, CList *CL, int data){
    int ndx = allocSpace(VH);
    if(ndx != -1){
        VH->Node[ndx].elem = data;
        VH->Node[ndx].link = -1;
        if(*CL == -1){
            *CL = ndx;
        } else{
            CList *trav;
            for(trav = CL; *trav != -1; trav = &(VH->Node[*trav].link)){}
            *trav = ndx;
        }
    }
}

void deleteFirst(VHeap *VH, CList *CL){
    int ndx;

    ndx = *CL;
    *CL = VH->Node[ndx].link;

    deallocSpace(VH, ndx);
}

void deleteLast(VHeap *VH, CList *CL){
    int ndx;

    CList *trav;
    for(trav = CL; *trav != -1 && VH->Node[*trav].link != -1; trav = &(VH->Node[*trav].link)){}

    ndx = *trav;
    *trav = -1;

    deallocSpace(VH, ndx);
}