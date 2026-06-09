#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    struct form{
        int coe;
        int index;
        struct form *link;
    };
    struct form *first1=NULL,*p,*tail1=NULL;
    //first1=tail1=p;
    char ch;
    while((ch=getchar())!='\n'){
        p=(struct form*)malloc(sizeof(struct form));
        p->link=NULL;
        if(first1==NULL){
            first1=tail1=p;
        }
        else{
            tail1->link=p;
            tail1=p;
        }
        p->coe=0;
        p->index=0;
        p->coe=(p->coe)*10+ch-'0'; // @@ Does not handle negative coefficients; if input starts with '-', it will be parsed incorrectly.
        while((ch=getchar())!=' '){
            p->coe=(p->coe)*10+ch-'0'; // @@ Same issue: fails to parse negative coefficients correctly.
        }
        while((ch=getchar())!=' '&&ch!='\n'){
            
            p->index=(p->index)*10+ch-'0';
        }
        if(ch=='\n'){
            break;
        }    
    }
    ///获得第二个式子信息 
    struct form *first2=NULL,*tail2=NULL,*q;
    //first2=tail2=q;
    while((ch=getchar())!='\n'){
        q=(struct form*)malloc(sizeof(struct form));
        q->link=NULL;
        if(first2==NULL){
            first2=tail2=q;
        }
        else{
            tail2->link=q;
            tail2=q;
        }
        q->coe=0;
        q->index=0;
        q->coe=(q->coe)*10+ch-'0'; // @@ Does not handle negative coefficients.
        while((ch=getchar())!=' '){
            q->coe=(q->coe)*10+ch-'0'; // @@ Same issue with negative coefficients.
        }
        while((ch=getchar())!=' '&&ch!='\n'){
            
            q->index=(q->index)*10+ch-'0';
        }
        if(ch=='\n'){
            break;
        }    
    }
    struct form *finalfirst,*finaltail,*pf=NULL;//p是指向两个 
    p=first1;
    finalfirst=(struct form*)malloc(sizeof(struct form));
    finalfirst->link=NULL;
    pf=finaltail=finalfirst;
    pf->coe=pf->index=0;
    pf->link=NULL;
    while(p!=NULL){
        q=first2;
        while(q!=NULL){
            int tempcoe,tempindex; // @@ In C89/C90, variable declarations must be at the beginning of a block. Declaring inside a loop may cause a compilation error on older compilers.
            tempcoe=(p->coe)*(q->coe);
            tempindex=(p->index)+(q->index);
            pf=finalfirst;
            while(pf!=NULL){
                if((pf->index)==tempindex){
                    pf->coe+=tempcoe;
                    break;
                }
                else if((pf->index>tempindex)&&(pf->link!=NULL)&&(pf->link->index<tempindex)){
                    struct form *tempp; // @@ In C89/C90, variable declarations must be at the beginning of a block. Declaring inside an if block may cause a compilation error.
                    tempp=(struct form*)malloc(sizeof(struct form));
                    tempp->link=pf->link;
                    tempp->coe=tempcoe;
                    tempp->index=tempindex;
                    pf->link=tempp;
                    break;
                }
                else if((pf->index>tempindex)&&(pf->link==NULL)){
                    struct form *tempp; // @@ In C89/C90, variable declarations must be at the beginning of a block. Declaring inside an if block may cause a compilation error.
                    tempp=(struct form*)malloc(sizeof(struct form));
                    tempp->link=NULL;
                    tempp->coe=tempcoe;
                    tempp->index=tempindex;
                    pf->link=tempp;
                    finaltail=tempp;
                    break;
                }
                else if(pf->index<tempindex){
                    struct form *tempp; // @@ In C89/C90, variable declarations must be at the beginning of a block. Declaring inside an if block may cause a compilation error.
                    tempp=(struct form*)malloc(sizeof(struct form));
                    tempp->link=finalfirst;
                    tempp->coe=tempcoe;
                    tempp->index=tempindex;
                    finalfirst=tempp;
                    break;
                }
                pf=pf->link;
            }
            q=q->link;
        }
        p=p->link;
    }
    pf=finalfirst;
    while(finalfirst!=NULL){
        if(finalfirst->index!=0){ // @@ Skips printing constant terms (index 0) because the dummy node has index 0 and real constant terms may be incorrectly merged into it or skipped.
            printf("%d %d ",finalfirst->coe,finalfirst->index);
        }
        pf=finalfirst;
        finalfirst=finalfirst->link;
        free(pf);
    }
    return 0;
}