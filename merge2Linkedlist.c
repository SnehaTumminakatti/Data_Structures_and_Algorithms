#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) if(!((p) = malloc(s))){ fprintf(stderr,"Insufficient memory");}
#define compare(a,b)  ((a>b)?1:-1)
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
}listNode;

listPointer createNode(listPointer tail,int data){
    listPointer temp;
    MALLOC(temp,sizeof(struct listNode));
    temp->data=data;
    temp->link=NULL;
    tail->link=temp;
    return temp;
}

void createNElements(listPointer tail,int listLength,int arr[]){
    for(int i=0;i<listLength;i++){
       tail=createNode(tail,arr[i]);
    }
}

void attach(listPointer tail,listPointer list){
    for(;list;list=list->link){
        tail=createNode(tail,list->data);
    }
}

void printList(listPointer head){
    printf("the elements in the linkedlist are\n");
    for(;head;head=head->link){
        // printf("asd");
        printf("%d\t",head->data);
    }
    puts("");
}

int main(){
    listPointer head1,head2,head3,tail1,tail2,tail3,list1,list2,list3;
    int data1[] = {21,33,66,68,70};
    int data2[] = {1,2,33,53,90};
    int len1 = sizeof(data1) / sizeof(data1[0]);
    int len2 = sizeof(data2) / sizeof(data2[0]);
    // printf("%d\t%d",len1,len2);
    MALLOC(head1,sizeof(struct listNode));
    MALLOC(head2,sizeof(struct listNode));
    MALLOC(head3,sizeof(struct listNode));
    head1->link = tail1;
    head2->link = tail2;
    head3->link = tail3;
    tail1 = head1;
    tail2 = head2;
    tail3 = head3;
    createNElements(tail1,len1,data1);
    createNElements(tail2,len2,data2);
    list1=head1;
    list2=head2;
    list3=head3;
    // for(int i=0;i<len2;i++){
    //     printf("%d\t",data2[i]);
    // }
    // for(;list2;list2=list2->link){
    //     puts("");
    //     printf("%d\t",list2->data);
    // }
    // int res=compare(5,3);
    // printf("%d",res);
   
    // printf("%d\t",list1->link->data);
    // printf("%d\t",list2->link->data);
    
    // int res=compare(list1->link->data,list2->link->data);
    // printf("%d",res);
  
    list2=list2->link;
    list1=list1->link;
           
    while(1){
        switch(compare(list1->data,list2->data)){
            case 1:
                   tail3=createNode(tail3,list2->data);
                   list2=list2->link;
                   if(!list2){
                        attach(tail3,list1);
                        printList(list3);
                        exit(0);
                   }
                   break;
            case -1: 
                    
                    tail3=createNode(tail3,list1->data);
                    list1=list1->link;
                    if(!list1){
                        attach(tail3,list2);
                        printList(list3);
                        exit(0);
                   }
                   break;
        }
    }
//    for(;list3;list3=list3->link){
//         puts("");
//         printf("%d\t",list3->data);
//     }
    
}