#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) if(!((p) = malloc(s))){ fprintf(stderr,"Insufficient memory"); exit(EXIT_FAILURE);}
#define IS_EMPTY(first) (!(first))
typedef struct listNode *listPointer;  
typedef struct listNode{
    int data;
    listPointer link;
}listNode;
listPointer create2(){
    listPointer first,second;
    MALLOC(first,sizeof(listNode));
    MALLOC(second,sizeof(listNode));
    second->link = NULL;
    second->data = 20;
    first->data = 10;
    first->link=second;
    return first;


}
int main(){
    listNode item1,item2,temp;
    item1.data=10;
    item2.data=20;
    item1.link=item2.link;
    item2.link=NULL;
    printf("\n%d item 1 data :",item1.data);
    printf("\n%d item 2 data :",item2.data);
    printf("\n%p item 1 link :",&item1.link);
    printf("\n%p",&item2.link);
    temp.link=item1.link;
    printf("\t%d\n",temp.data);
}