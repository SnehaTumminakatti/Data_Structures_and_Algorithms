#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) if(!((p) = malloct(s))){ fprintf(stderr,"Insufficient memory");}

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
    listPointer prevNode;
    prevNode=head->link;
    for(;head;head=head->link){
        if(head->data==num){
            return prevNode;
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

void deleteNum(listPointer delNode){
    listPointer trail;
    trail=delNode->link;
    delNode->link=trail->link;
    free(trail);   
}
int main(){
    int n,num;
    MALLOC(head,sizeof(struct listNode));
    listPointer temp;
    head->data=0;
    head->link=tail;
    tail=head;

    printf("Enter the no of nodes in linked list \n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        
        tail=createNode(tail);
    }
    
    printList(head);
    printf("\nEnter the number to be deleted: \n ");
    scanf("%d",&num);

    temp=searchNum(head,num);
    if(temp){
        deleteNum(temp);
        printf(" list  after deletion : \n");
        printList(head);
        return 0;
    }
    printf("The number %d is not present in the list",num);
    return 0;

}