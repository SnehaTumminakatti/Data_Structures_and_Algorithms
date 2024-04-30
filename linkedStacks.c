#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link; 
}listNode;

typedef struct stack{
    listPointer top;
    listPointer header;
}stack;

listPointer makeNode(int value){
    listPointer temp;

    temp=malloc(sizeof(struct listNode));
    temp->data=value;
    temp->link=NULL;
    return temp;

}

void push(stack *list, int data){
    listPointer lastNode;
    listPointer newNode = makeNode(data);
    if (list->top == NULL){
        
    }
    = list->top->link; 
    list->top->link = newNode;
    list->top = newNode;
}



int pop(stack* list){
    if(stackEmpty(list)){
        puts("Stack empty!!");
        return;
    }
    int data = list->top->data;


}


void push(stack *list){
    listPointer temp,curNode;
    int item;
    printf("Enter the data to be stored\n");
    scanf("%d",&item);
    temp=malloc(sizeof(struct listNode));
    temp->data=item;
    temp->link=NULL;
    if(!(list->header->link)){
        list->header->link=temp;
        temp->link=list->header;
        list->top=temp;
        list->header->data=list->header->data+1;
        return;
    }
        list->header->data=list->header->data+1;

    curNode=list->top;
    curNode->link=temp;
    list->top=temp;
    temp->link=curNode;
    
}

int stackEmpty(stack *s){
    return s->header->link==NULL;
}

int pop(stack *s){
    if(stackEmpty(s)){
        puts("Stack Empty");
        return 0;
    }
    listPointer temp;
    int item,t;
    t=s->header->data;
    temp=s->header;
    for(int i=0;i<t;i++){
       temp=temp->link;
    }
    item=temp->data;
    s->header->data=--t;
    free(temp);
    return item;
}

stack* createLinkedStack(){
    stack *s;
    s=malloc(sizeof(struct stack));
    s->header=malloc(sizeof(struct listNode));
    s->top=s->header;
    s->header->data=0;
    return s;

}

void displayList(stack *s){
    listPointer temp;
    temp=s->header;
    int numNodes=s->header->data;
    temp=temp->link;
    for(int i=0;i<numNodes;i++){
        printf("\t%d",temp->data);
        temp=temp->link;
    }
    puts("");
   
}

void doStackOperations(stack* s){
    int choice;
    
    while(1){
        printf("\nEnter the Operation to be performed:\n");
        printf("1. PUSH\t 2. POP\t 3. QUIT\n");
        scanf("%d",&choice);
        if(choice==3){
            return;
        }

        if(choice==1){
            int item;
            printf("Enter the data to be stored\n");
            scanf("%d",&item);
            push(s, item);
            printf("The elements in the list after the push operation are as follows\n");
            displayList(s);
        }
        
        if(choice==2){
            printf("The Poped element is : %d \n",pop(s));
            printf("The elements after the pop Operation are as follows\n");
            displayList(s);
        }
    }
}

int main(){
    stack *list;
    list=createLinkedStack();
    doStackOperations(list);
}