#include<stdio.h>
#include<stdlib.h>
struct listNode{
    int data;
    struct listNode *link;
};
int main(){
    struct listNode *first,*second;
    first=(struct listNode*)malloc(sizeof(struct listNode));
    second=(struct listNode*)malloc(sizeof(struct listNode));
    second->link=NULL;
    second->data=10;
    first->data=20;
    first->link=second;
    // printf("%d",second->data);
    struct listNode *temp;
    temp=first->link;
    printf("%d",temp->data);



}