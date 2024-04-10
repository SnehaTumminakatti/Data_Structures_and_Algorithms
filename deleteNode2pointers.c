#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) if(!((p) = malloc(s))){ fprintf(stderr,"Insufficient memory");}
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
}listNode;
void deleteNode(listPointer first,listPointer trail){
    listPointer temp;
    MALLOC(temp,sizeof(*temp));
    temp=trail->link;
    trail->link=temp->link;
    free(temp);
}
int main(){
    listPointer first,second,third;
    MALLOC(first,sizeof(*first));
    MALLOC(second,sizeof(*second));
    MALLOC(third,sizeof(*second));

    first->data=20;
    second->data=30;
    first->link=second;
    second->link=third;
    third->data=40;
    third->link=NULL;
    deleteNode(first,second);
    for(;first;first=first->link){
        printf("%d",first->data);
    }
    
}