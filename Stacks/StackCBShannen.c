//I AM A SIMP FOR SHANNEN
#include <stdio.h>
#include <stdbool.h>
#define MAX 5

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
void push(CLIST *CL, VHeap *VH, int data);
void pop(CLIST *CL, VHeap *VH);
bool isEmpty(CLIST CL);
bool isFull(VHeap VH);
int top(CLIST CL, VHeap VH);
void display(CLIST CL, VHeap VH);

int main(){
    CLIST shannen;
    VHeap nazareno;
    initCList(&shannen);
    initVHeap(&nazareno);

    push(&shannen, &nazareno, 10);
    push(&shannen, &nazareno, 20);
    push(&shannen, &nazareno, 30);
    push(&shannen, &nazareno, 40);
    push(&shannen, &nazareno, 50);
    push(&shannen, &nazareno, 60);
    display(shannen, nazareno);

    pop(&shannen, &nazareno);
    pop(&shannen, &nazareno);
    pop(&shannen, &nazareno);
    pop(&shannen, &nazareno);
    pop(&shannen, &nazareno);
    pop(&shannen, &nazareno);
    display(shannen, nazareno);

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

void push(CLIST *CL, VHeap *VH, int data){
    int ndx = allocSpace(VH);

    if(ndx != -1){
        VH->Node[ndx].elem = data;
        VH->Node[ndx].link = *CL;
        *CL = ndx;
    } else{
        printf("Cannot push the element.\n");
    }
}

void pop(CLIST *CL, VHeap *VH){
    CLIST temp;

    if(*CL != -1){
        temp = *CL;
        *CL = VH->Node[temp].link;
        deallocSpace(VH, temp);
    } else{
        printf("Cannot delete an Empty Stack.\n");
    }
}

bool isEmpty(CLIST CL){
    return (CL == - 1) ? 1 : 0;
}

bool isFull(VHeap VH){
    return (VH.avail != -1) ? 1 : 0;
}

int top(CLIST CL, VHeap VH){
    return VH.Node[CL].elem;
}

void display(CLIST CL, VHeap VH){
    CLIST tempCL;
    VHeap tempVH;
    initCList(&tempCL);
    initVHeap(&tempVH);

    while(!isEmpty(CL)){
        push(&tempCL, &tempVH, top(CL, VH));
        pop(&CL, &VH);
    }

    while(!isEmpty(tempCL)){
        printf("%d ", top(tempCL, tempVH));
        push(&CL, &VH, top(tempCL, tempVH));
        pop(&tempCL, &tempVH);
    }
    printf("\n");
}