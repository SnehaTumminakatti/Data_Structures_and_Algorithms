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
int main(){
    int n;  
    int count=-1;
    MALLOC(head,sizeof(struct listNode));
        head->data=0;
        head->link=tail;
        tail=head;

    printf("Enter the no of nodes in linked list ");
    scanf("\n%d",&n);
    for(int i=0;i<n;i++){
        tail=createNode(tail);
        printf("%d",tail->data);
    }
    printf("the elements in the linkedlist are \n");
    for(;head;head=head->link){
        printf("%d\n",head->data);
        count++;
    }
   printf("The number of elements in the linked list are %d \n",count);          
}