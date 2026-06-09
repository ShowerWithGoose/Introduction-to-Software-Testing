#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Mult Mult;
struct Mult
{
    int xi;
    int ci;
    Mult *next;
    Mult *back;
};

int main(){
    Mult *fir1=NULL,*fir2=NULL,*fir3=NULL;
    Mult *cur1=NULL,*cur2=NULL,*cur3=NULL;
    Mult *pre1=NULL,*pre2=NULL,*pre3=NULL;
    char ch1,ch2;
    for(;;)
    {
        cur1=(Mult*)malloc(sizeof(Mult));
        if(fir1==NULL){
            fir1=cur1;
        }
        if(pre1!=NULL){
            pre1->next=cur1;
        }
        scanf("%d%c%d",&cur1->xi,&ch1,&cur1->ci);
        ch2=getchar();
        if(ch2=='\n'){ // @@ Break occurs before setting cur1->next = NULL for the last node, leaving it uninitialized.
            break;
        }
        cur1->next=NULL;
        pre1=cur1;  
    }
    for(;;)
    {
        cur2=(Mult*)malloc(sizeof(Mult));
        if(fir2==NULL){
            fir2=cur2;
        }
        if(pre2!=NULL){
            pre2->next=cur2;
        }
        scanf("%d%c%d",&cur2->xi,&ch1,&cur2->ci);
        ch2=getchar();
        if(ch2=='\n'){ // @@ Same issue: break before setting cur2->next = NULL for the last node.
            break;
        }
        cur2->next=NULL;
        pre2=cur2;  
    }
    cur1=fir1;
    cur2=fir2;
    while(cur2!=NULL){ // @@ Should perform polynomial multiplication and store result, not just print. This loop prints the second polynomial instead.
        printf("%d %d ",cur2->xi,cur2->ci); // @@ Prints input data instead of product terms.
        cur2=cur2->next; // @@ Iteration associated with the wrong loop.
    }printf("\n");while(cur1!=NULL){ // @@ Should print the product polynomial, not the first input polynomial.
        printf("%d %d ",cur1->xi,cur1->ci); // @@ Prints input data instead of product terms.
        cur1=cur1->next; // @@ Iteration associated with the wrong loop.
    }
    return 0;}