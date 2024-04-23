#include<stdio.h>
#include<stdlib.h>
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
}listNode;

listPointer createLinkedList(){
    listPointer head,tail;
    head=malloc(sizeof(struct listNode));
    tail=head;
    head->link=tail;
    head->data=0;
    return tail;
}

listPointer createNode(listPointer tail,int data){
    listPointer temp;
    temp=malloc(sizeof(struct listNode));
    temp->data=data;
    temp->link=NULL;
    tail->link=temp;
    return temp;
}

listPointer getListData(listPointer tail){
    listPointer temp;
    temp=tail;
    int n,data;
    printf("Enter the number of elements in the list : \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the data of the element %d : \n",i);
        scanf("%d",&data);
        tail=createNode(tail,data);
    }
    return temp;
}

void printList(listPointer list){

    for(;list;list=list->link){
        printf("%d\t",list->data);
    }
}

listPointer getDataLink(listPointer list,int data){
    for(;list;list=list->link){
        if(list->data==data){
            break;
        }
    }
    return list;
}

listPointer moveNodesRight(listPointer list){
    listPointer temp,nextNode,leftNode,currNode,nextNodeLink,left;
    int leftData,curData,count;
    count=0;
    printf("Enter the data of leftNode :");
    scanf("%d",&leftData);
    printf("\nEnter the data of the current Node :");
    scanf("%d",&curData);
    leftNode=getDataLink(list,leftData);
    currNode=getDataLink(list,curData);
    // printf("%d",leftNode->data);
    // printf("%d",currNode->data);
    left=leftNode;
    temp=leftNode;
    temp=temp->link;
    while(1){
        nextNode=temp;
        nextNodeLink=nextNode->link;
        temp=nextNodeLink;
        nextNode->link=leftNode;
        leftNode=nextNode;
        // printf("the leftNode link is  %p\t",leftNode->link);
        count++;
        // printf("%d",count);
        if(leftNode==currNode){
            break;
        }
    }
    // printf("%d",currNode->link->link->data);
    // int i=-1;
    // while(count!=i){
    //    printf("%d",currNode->data);
    //    currNode=currNode->link;
    //    i++;
    // }
    for(;left->data!=currNode->data;currNode=currNode->link){
            printf("%d",currNode->data);
    }
  
    
    return currNode;
}

int main(){
    listPointer list,resList;
    list=createLinkedList();
    list=getListData(list);
    printList(list);
    resList=moveNodesRight(list);
    // printList(resList);
}