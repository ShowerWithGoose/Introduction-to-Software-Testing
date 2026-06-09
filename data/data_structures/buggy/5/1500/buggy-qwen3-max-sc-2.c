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
        scanf("%d%c%d",&cur1->xi,&ch1,&cur1->ci); // @@ [Incorrect format specifier: expects a space between coefficient and exponent, but %c reads the space as ch1; should use " %d %d" instead]
        ch2=getchar();
        if(ch2=='\n'){
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
        scanf("%d%c%d",&cur2->xi,&ch1,&cur2->ci); // @@ [Same issue: %c consumes the space, leading to incorrect parsing of input]
        ch2=getchar();
        if(ch2=='\n'){
            break;
        }
        cur2->next=NULL;
        pre2=cur2;  
    }
    cur1=fir1;
    cur2=fir2;
    while(cur2!=NULL){
        printf("%d %d ",cur2->xi,cur2->ci);
        cur2=cur2->next;
    }printf("\n");while(cur1!=NULL){
        printf("%d %d ",cur1->xi,cur1->ci);
        cur1=cur1->next;
    }
    return 0;}