#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) if(!((p) = malloc(s))){ fprintf(stderr,"Insufficient memory");}
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
}listNode;

listPointer head,tail;

void createNode(){
    listPointer temp;
    MALLOC(temp,sizeof(struct listNode));
    // temp->data=data;
    int data;
    printf("Enter the data");
    scanf("%d",&data);
    if(head){
        tail->link=temp;
        // tempn=tail;
        temp->data=data;
        temp->link=NULL;
        tail=temp;
        printf("%d\n",temp->data);
    }
    head->link=temp;
    temp->data=data;
    temp->link=NULL;
    printf("%d\n",temp->data);
}
int main(){
    int n;
    MALLOC(head,sizeof(struct listNode));
    MALLOC(tail,sizeof(struct listNode));
    printf("Enter the no of nodes in linked list ");
    scanf("\n%d",&n);
    for(int i=0;i<n;i++){
        createNode();
    }
    for(;head;head=head->link){
        printf("%d\n",head->data);
    }
}