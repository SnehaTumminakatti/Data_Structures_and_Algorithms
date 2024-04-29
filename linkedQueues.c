#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
}listNode;

typedef struct queue{
    listPointer front;
    listPointer rear;
}queue;

void push(queue *q){
    listPointer temp;
    int data;
    temp=malloc(sizeof(struct listNode*));
    printf("Enter the data you want to store : \n");
    scanf("%d",&data);
    temp->data=data;
    temp->link=NULL;
    // if(!(q->rear->link)){
    //     q->rear=temp;
    //     q->front=temp;
    //     printf("a");
    //     return;
    // }
    q->front->data++;
    q->rear->link=temp;
    q->rear=temp;
}

queue* createLinkedQueue(){
    queue *qlist;
    qlist=malloc(sizeof(struct queue*));
    qlist->rear=malloc(sizeof(struct listNode*));
    qlist->front=qlist->rear;
    
    // qlist->front->data=0;
    // qlist->rear->data=0;
    return qlist;
}

int queueEmpty(queue* s){
    return !(s->front->link);
}

int pop(queue* list){
    if(queueEmpty(list)){
        puts("Queue Empty");
        return 0;
    }
    listPointer temp,delNode;
    int item;
     list->front->data--;
    delNode=list->front;
    temp=delNode->link;
    list->front=temp;
    item=delNode->data;
    free(delNode);
    return item;
}

int main(){
    queue *qlist;
    qlist=createLinkedQueue();
    pop(qlist);
    // pop(qlist);

   
    push(qlist);
    push(qlist);
    push(qlist);
    push(qlist);
    push(qlist);
    
    printf("%d",pop(qlist));
    printf("%d",pop(qlist));
    printf("%d",pop(qlist));
    printf("%d",qlist->front->data);
    printf("%d",qlist->rear->data);
}