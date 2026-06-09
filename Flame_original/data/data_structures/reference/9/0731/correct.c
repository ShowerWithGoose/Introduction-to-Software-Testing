#include<stdio.h>
#include<stdlib.h>

int numsofans;
struct stru{
    int x1;
    int y1;
    int x2;
    int y2;
    struct stru* p;
}struc[101];
struct s1{
    int ans;
    struct stru *p;
}s11[101];
int comp(const void *a,const void *b){
    struct stru * ap=(struct stru *)a;
    struct stru * bp=(struct stru *)b;
    return ap->x1-bp->x1;
}
void f(int n,int m){
    if(struc[m].p==NULL){
        for(int o=m+1;o<n;o++){
            if(struc[o].x1==struc[m].x2&&struc[o].y1==struc[m].y2){
                struc[m].p=struc+o;
                f(n,o);
                return;
            }
        }
    }
    return;
}
void f1(int n,struct stru *m){
    if(m->p!=NULL){
        s11[numsofans].ans++;
        f1(n,m->p);
        return;
    }
    numsofans++;
    return;
}
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&struc[i].x1,&struc[i].y1,&struc[i].x2,&struc[i].y2);
    }
    qsort(struc,n,sizeof(struct stru),comp);
    for(int i=0;i<n;i++){
        f(n,i);
    }
    for(int i=0;i<n;i++){
        s11[numsofans].p=struc+i;
        f1(n,struc+i);
    }
    int max=0;
    int x,y;
    for(int i=0;i<numsofans;i++){
        if(s11[i].ans>max)max=s11[i].ans,x=s11[i].p->x1,y=s11[i].p->y1;
    }
    printf("%d %d %d",max+1,x,y);
    return 0;
}
