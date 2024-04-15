#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) if(!((p) = malloc(s))){ fprintf(stderr,"Insufficient memory");} 
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
}listNode;

listPointer head,tail;

listPointer createNode(listPointer tail){
    listPointer temp;
    MALLOC(temp,sizeof(struct listNode));
    printf("Enter the data ");
    scanf("%d",&temp->data);
    tail->link=temp;
    temp->link=NULL;

    return temp;
}


listPointer searchNum(listPointer head,int num){
    for(;head;head=head->link){
        if(head->data==num){
            return head;
        }
    }
    return NULL;
}

void printList(listPointer head){
    printf("the elements in the linkedlist are\n");
    for(;head;head=head->link){
        printf("%d\t",head->data);
    }

}
int main(){
    int n,num;
    MALLOC(head,sizeof(struct listNode));
    head->data=0;
    head->link=tail;
    tail=head;

    printf("Enter the no of nodes in linked list \n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        tail=createNode(tail);
    }
    printList(head);
    printf("\nEnter the number to be searched : \n ");
    scanf("%d",&num);

    if(searchNum(head,num)){
        printf("The number %d is present in the list",num);
        return 0;
    }
    printf("The number %d is not present in the list",num);
    return 0;

}