#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
}listNode;

listPointer createNode(listPointer tail,int data){
    listPointer temp;
    temp=malloc(sizeof(struct listNode));
    temp->data=data;
    temp->link=NULL;
    tail->link=temp;
    return temp;
}

void printList(listPointer first){
    
    for(;first;first=first->link){
        printf("%d\t",first->data);
    }
}

void attach(listPointer tail,listPointer list){
    if(list){
        for(;list;list=list->link){
             tail=createNode(tail,list->data);
        }
    }
    
}


listPointer createLinkedList(){
    listPointer head,tail;
    head=malloc(sizeof(struct listNode));
    tail=head;
    head->link=tail;
    head->data=0;
    return tail;
}

listPointer mergeLists(listPointer listA,listPointer listB){
    int i=1;
    listPointer mergedList,tempList;
    mergedList=createLinkedList();
    tempList=mergedList;
    
     listA=listA->link;
     listB=listB->link;
    while(1){
        if(i%2){
            tempList=createNode(tempList,listA->data);
            listA=listA->link;
            if(!listA){
                attach(tempList,listB);
                break;
            }
             i++;
        }
        tempList=createNode(tempList,listB->data);
        listB=listB->link;
        if(!listB){
            attach(tempList,listA);
            break;
        }
         i++;
       
    }
    return mergedList;
}

listPointer getData(listPointer list){
    listPointer tempNodes;
    tempNodes=list;
    int n,data;
    printf("Enter the number of elements in the list");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter the data of element %d : ",i+1);
        scanf("%d",&data);
        tempNodes=createNode(tempNodes,data);
    }
    return list;
}

int main(){
    listPointer listA,listB,mergedList;
    listA=createLinkedList();
    listA=getData(listA);
    listB=createLinkedList();
    listB=getData(listB);
    mergedList=mergeLists(listA,listB);
    printList(mergedList);
}