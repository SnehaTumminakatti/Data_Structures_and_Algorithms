#include<stdio.h>
#include<stdlib.h>
// typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    struct listNode *link;
}listNode;

void deleteNode(struct listNode *prevNode,struct listNode *dnode){
    prevNode->link=dnode->link;
    free(dnode);
}
int main(){
    struct listNode *first,*second,*third,*temp;
    int n;

    first=(listNode*)malloc(sizeof(listNode));
    second=(listNode*)malloc(sizeof(listNode));
    third=(listNode*)malloc(sizeof(listNode));
    third->data=40;
    third->link=NULL;
    first->data=20;
    second->data=30;
    first->link=second;
    second->link=third;
    deleteNode(first,second);
    for(;first;first=first->link){
        printf("%d",first->data);
    }

}