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
        return;
    }
    curNode=list->top;
    curNode->link=temp;
    list->top=temp;
    temp->link=curNode;
}

int stackEmpty(stack *s){
    return !(s->header->link);
}

int pop(stack *s){
    if(stackEmpty(s)){
        puts("Stack Empty");
        return 0;
    }
    listPointer temp;
    int item;
    temp=s->top;
    item=temp->data;
    s->top=temp->link;
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
    listPointer temp,list;
    temp=s->top;
    list=temp;
    while(temp->link!=s->header->link){
        printf("a");
        temp=temp->link;
    }
}

void doStackOperations(stack* s){
    int choice;
    
    while(1){
        printf("Enter the Operation to be performed:\n");
        printf("1. PUSH\t 2. POP\t 3. QUIT\n");
        scanf("%d",&choice);
        if(choice==3){
            break;
        }

        if(choice==1){
            push(s);
            printf("The elements in the list after the push operation are as follows\n");
            displayList(s);
        }
        
        if(choice==2){
            pop(s);
            printf("The elements after the pop Operation are as follows\n");
            displayList(s);
        }
    }
}

int main(){
    stack *list;
    list=createLinkedStack();
    // push(list);
    // push(list);
    // push(list);

    doStackOperations(list);
}