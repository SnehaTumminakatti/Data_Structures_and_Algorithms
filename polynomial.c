#include<stdio.h>
#include<stdlib.h>
typedef struct polyNode *polyPointer;
typedef struct polyNode{
    int coeff;
    int exp;
    polyPointer link;
}polyNode;

polyPointer getNode(){
    polyPointer head,tail;
    head=malloc(sizeof(struct polyNode*));
    tail=head;
    head->link=tail;
    return tail;
}
polyPointer createPoly(int coeff,int exp){
    polyPointer temp;
    temp=malloc(sizeof(struct polyPointer*));
    temp->coeff=coeff;
    temp->exp=exp;
    temp->link=NULL;
    return temp;
}

polyPointer getPolyData(polyPointer poly){
    polyPointer head;
    head=poly;
    int n,coeff,exp;
    printf("Enter the number of terms in a polynomial \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coefficient and exponent of the polynomial");
        scanf("%d",&coeff);
        scanf("%d",&exp);
        poly->link=createPoly(coeff,exp);
        poly=poly->link;
    }
    return head;
}

void printPolynomial(polyPointer polynomial){
    polyPointer poly;
    poly=polynomial;
    for(;poly;poly=poly->link){
        printf("%d\t%d\n",poly->coeff,poly->exp);
    }
}

polyPointer attach(polyPointer poly,polyPointer tail){
    polyPointer temp;
    temp=createPoly(poly->coeff,poly->exp);
    tail->link=temp;
    tail=temp;
    return tail;
}

int checkNull(polyPointer poly,polyPointer polyB,polyPointer polyC){
    polyPointer temp;
    
    if(poly==NULL){
        for(;polyB;polyB=polyB->link){
            temp=createPoly(polyB->coeff,polyB->exp);
            polyC->link=temp;
            polyC=temp;
        }
        return 1;
    }
    return 0;
}

polyPointer addCoeff(polyPointer a,polyPointer b,polyPointer c){
    polyPointer temp;
    int coeff;
    coeff=a->coeff+b->coeff;
    temp=createPoly(coeff,a->exp);

    printf("%d",temp->coeff);
    c->link=temp;
    c=temp;
    return c;
} 

polyPointer addPoly(polyPointer a,polyPointer b,polyPointer c){
   polyPointer polyA,polyB,polyC,head;
   polyA=a;
   polyB=b;
   polyC=c;
   head=polyC;
   polyA=polyA->link;
   polyB=polyB->link;
   while(1){

        if(polyA->exp > polyB->exp){
            polyC=attach(polyA,polyC);
            printf("%d",polyC->coeff);
            polyB=polyB->link;
            if(checkNull(polyB,polyA,polyC)){
                break;
            }
        }

        if(polyA->exp < polyB->exp){
            polyC=attach(polyB,polyC);
            
            polyA=polyA->link;
            if(checkNull(polyA,polyB,polyC)){
                break;
            }
        }

        if(polyA->exp == polyB->exp){
            polyC=addCoeff(polyA,polyB,polyC);
            polyA=polyA->link;
            polyB=polyB->link;
            if(checkNull(polyA,polyB,polyC)){
                break;
            }
            if(checkNull(polyB,polyA,polyC)){
                break;
            }
            
        }
        // printf("%d",polyC->coeff);
   }
   return head;



}

int main(){
    polyPointer polyA,polyB,resPoly;
    polyA=getNode();
    polyB=getNode();
    resPoly=getNode();
    polyA=getPolyData(polyA);
    polyB=getPolyData(polyB);
    printPolynomial(polyA);
    printPolynomial(polyB);
    resPoly=addPoly(polyA,polyB,resPoly);
    printPolynomial(resPoly);
}