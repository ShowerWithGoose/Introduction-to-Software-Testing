#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Mult Mult;
struct Mult
{
    int xi;
    int ci;
    Mult *next;
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
        scanf("%d%c%d",&cur2->xi,&ch1,&cur2->ci);
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
        cur3=(Mult*)malloc(sizeof(Mult));
        if(fir3==NULL){
            fir3=cur3;
        }
        if(pre3!=NULL){
            pre3->next=cur3;
        }
        cur3->xi=cur1->xi*cur2->xi;
        cur3->ci=cur1->ci+cur2->ci;
        cur3->next=NULL;
        cur2=cur2->next;
        pre3=cur3;
    }
    cur1=cur1->next;
    pre3=fir3;
    cur3=fir3->next;
   while(cur1!=NULL){
        cur2=fir2;
        while(cur2!=NULL){
            while(1){
                if(cur3==NULL){
                    cur3=(Mult*)malloc(sizeof(Mult));
                    pre3->next=cur3;
                    cur3->ci=cur1->ci+cur2->ci;
                    cur3->xi=cur1->xi*cur2->xi;
                    cur3->next=NULL;
                    break;
                }
                if(cur2->ci+cur1->ci>cur3->ci){
                    cur3=(Mult*)malloc(sizeof(Mult));
                    cur3->ci=cur1->ci+cur2->ci;
                    cur3->xi=cur1->xi*cur2->xi;
                    cur3->next=pre3->next;
                    pre3->next=cur3;
                    break;
                }
                if(cur2->ci+cur1->ci==cur3->ci){
                    cur3->xi+=cur2->xi*cur1->xi;
                    break;
                }
                if(cur2->ci+cur1->ci<cur3->ci){
                    pre3=cur3;
                    cur3=cur3->next;
                }
            }
            cur2=cur2->next;
        }
        cur1=cur1->next;
        cur3=fir3->next;
    }
    cur3=fir3;
    while(cur3!=NULL){
        printf("%d %d ",cur3->xi,cur3->ci);
        free(cur3);
        cur3=cur3->next;
    }
    return 0;
}
