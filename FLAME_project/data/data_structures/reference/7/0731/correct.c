#include<stdio.h>
#include<stdlib.h>

struct note{
    struct note *A,*B,*C;
    int n;
}n0;
struct note *p0=&n0;
int n;
int f(struct note *p,int num){
    if(p->n>num){
        if(p->B==NULL){p->B=malloc(sizeof(struct note));
        (p->B)->n=num;}else{
            p=p->B;
            f(p,num);
        }
    }else{
        if(p->C==NULL){p->C=malloc(sizeof(struct note));
        (p->C)->n=num;}else{
            p=p->C;
            f(p,num);
        }
    }
}
void ans(int m,struct note *p){
    if(p->B==NULL&&p->C==NULL)printf("%d %d\n",p->n,m);
    if(p->B!=NULL){
        ans(m+1,p->B);
    }
    if(p->C!=NULL){
        ans(m+1,p->C);
    }
    
}
int main(void){
    scanf("%d",&n);
    scanf("%d",&n0.n);
    int num;
    for(int i=0;i<n-1;i++){
    scanf("%d",&num);
    f(p0,num);
    }
    ans(1,p0);
    return 0;
}
