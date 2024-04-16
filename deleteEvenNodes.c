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
    printf("Enter the data you want to store :\n");
    scanf("%d",&temp->data);
    tail->link=temp;
    temp->link=NULL;
    return temp;

}

void deleteOddNodeList(listPointer head,int n){
           printf("klj");
    listPointer prevNode,temp,currNode;
    
    prevNode=head;
    currNode = head->link;
        // printf("\n%d\n",head->link->data);

    for(int i=1;i<=n;i++){
        if(!(i%2)){
            prevNode->link=currNode->link;
            temp = currNode;
            // printf("%d\n",head->data);
            free(temp);
            currNode = prevNode;
        }
       prevNode=currNode;
       currNode = currNode->link;
    }  
    // return trail;
}

void printList(listPointer head){
    printf("the elements in the linkedlist are\n");
    for(;head;head=head->link){
        printf("asd");
        printf("%d\t",head->data);
    }
    puts("");
}

int main(){
    int n;
    MALLOC(head,sizeof(struct listNode));
    head->data=0;
    head->link=tail;
    tail=head;
    // listPointer res;
    printf("Enter the no of nodes in linked list ");
    scanf("\n%d",&n);
    for(int i=0;i<n;i++){
        tail=createNode(tail);
    }
    printList(head);
    deleteOddNodeList(head,n);
    printList(head);


}