#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) if(!((p) = malloc(s))){ fprintf(stderr,"Insufficient memory");}
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
}listNode;
                                                                
void insertNode(listPointer *first,listPointer x){
    listPointer temp;
    MALLOC(temp,sizeof(*temp));
    temp->data=10;
    if(*first){
        temp->link=x->link;
        x->link=temp;
    }else{
        temp->link=NULL;
        *first=temp;
    }

    
}

int main(){
    listPointer first,second;
    int n;
    // first=(listNode*)malloc(sizeof(listNode));
    // second=(listNode*)malloc(sizeof(listNode));
    MALLOC(first,sizeof(*first));
    MALLOC(second,sizeof(*second));
    first->data=20;
    second->data=30;
    first->link=second;
    second->link=NULL;
    insertNode(&first,second);
    for(;first;first=first->link){
        printf("%d",first->data);
    }
}