#include<stdlib.h>
#include<stdio.h>
#define MALLOC(p,s) if(!((p) = malloct(s))){ fprintf(stderr,"Insufficient memory");}
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
}listNode;
listPointer head,tail;
listPointer createNode(listPointer tail){
    listPointer temp;
    printf("Enter the dat you want to store :\n");
    scanf("%d",&temp->data);
    tail->link=temp;
    temp->link=NULL;
    return temp;

}

int main(){
    int n;
    MALLOC(head,sizeof(struct listNode));
    head->link=tail;
    tail=head;
    printf("Enter the no of nodes in linked list ");
    scanf("\n%d",&n);
    for(int i=0;i<n;i++){
        tail=createNode(tail);
        // printf("%d",tail->data);
    }
    for(int i=0;i<=n;i++,head=head->link){
        if(i%2!=0){
            
        }
    }

}