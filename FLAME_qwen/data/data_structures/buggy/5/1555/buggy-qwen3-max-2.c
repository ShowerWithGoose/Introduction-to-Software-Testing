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
    while((ch=getchar())!='\n'){ @@ [Using `char` for `getchar()` return value is incorrect; `getchar()` returns `int` to properly handle EOF, which may not fit in a `char`. This can cause infinite loops or undefined behavior when input ends.]
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
        p->coe=(p->coe)*10+ch-'0'; @@ [This assumes the first character is a digit, but it could be '-' for negative coefficients. The code does not handle negative numbers at all.]
        while((ch=getchar())!=' '){ @@ [Same issue: `ch` is `char`, and this loop doesn't handle '-' sign. Also, if input ends abruptly (e.g., last term), this may read beyond or misbehave.]
            p->coe=(p->coe)*10+ch-'0';
        }
        while((ch=getchar())!=' '&&ch!='\n'){ @@ [Again, `ch` should be `int`. Also, this fails to handle negative exponents—but problem says exponents are non-negative, so sign not needed here. However, coefficient parsing already broken for negatives.]
            
            p->index=(p->index)*10+ch-'0';
        }
        if(ch=='\n'){
            break;
        }    
    }
    ///获得第二个式子信息 
    struct form *first2=NULL,*tail2=NULL,*q;
    //first2=tail2=q;
    while((ch=getchar())!='\n'){ @@ [Same error: `ch` is `char`, should be `int` to correctly detect EOF or newline. Also, after first polynomial input, if second line is empty or EOF, this may hang or crash.]
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
        q->coe=(q->coe)*10+ch-'0'; @@ [Does not handle negative coefficients. If input has negative number, this treats '-' as digit, leading to garbage values.]
        while((ch=getchar())!=' '){ @@ [Same issues: no negative handling, wrong type for `ch`.]
            q->coe=(q->coe)*10+ch-'0';
        }
        while((ch=getchar())!=' '&&ch!='\n'){ @@ [Same as above.]
            
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
            int tempcoe,tempindex;
            tempcoe=(p->coe)*(q->coe);
            tempindex=(p->index)+(q->index);
            pf=finalfirst;
            while(pf!=NULL){
                if((pf->index)==tempindex){
                    pf->coe+=tempcoe;
                    break;
                }
                else if((pf->index>tempindex)&&(pf->link!=NULL)&&(pf->link->index<tempindex)){
                    struct form *tempp;
                    tempp=(struct form*)malloc(sizeof(struct form));
                    tempp->link=pf->link;
                    tempp->coe=tempcoe;
                    tempp->index=tempindex;
                    pf->link=tempp;
                    break;
                }
                else if((pf->index>tempindex)&&(pf->link==NULL)){
                    struct form *tempp;
                    tempp=(struct form*)malloc(sizeof(struct form));
                    tempp->link=NULL;
                    tempp->coe=tempcoe;
                    tempp->index=tempindex;
                    pf->link=tempp;
                    finaltail=tempp;
                    break;
                }
                else if(pf->index<tempindex){
                    struct form *tempp;
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
        if(finalfirst->index!=0){ @@ [This skips terms with exponent 0 (constant term), which is wrong. The problem requires outputting all non-zero terms, including constant term if present. Also, if coefficient becomes zero due to cancellation, it should be omitted—but this code never removes zero-coefficient terms.]
            printf("%d %d ",finalfirst->coe,finalfirst->index);
        }
        pf=finalfirst;
        finalfirst=finalfirst->link;
        free(pf);
    }
    return 0;
}