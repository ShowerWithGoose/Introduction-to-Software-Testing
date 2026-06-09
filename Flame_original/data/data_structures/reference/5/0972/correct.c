#include<stdio.h>
#include<stdlib.h>
struct list {
    int di;
    int zhi;
}sta1[100],sta2[100],p[100];
char c=' ';
int cnt1=0,cnt2=0;
int comfuc(const void *a,const void *b){
    struct list *c=(struct list *)a;
    struct list *d=(struct list *)b;
    return d->zhi-c->zhi;
}
int main(){
    int cnt1=0,cnt2=0;
    while(c!='\n'){
        scanf("%d%d%c",&sta1[cnt1].di,&sta1[cnt1].zhi,&c);
        cnt1++;

    }
    c=' ';
    while(c!='\n'){
        scanf("%d%d%c",&sta2[cnt2].di,&sta2[cnt2].zhi,&c);
        cnt2++;

    }
    int k=0;
    for(int i=0;i<cnt1;i++){
        for(int j=0;j<cnt2;j++){
            p[k].di=sta1[i].di*sta2[j].di;
            p[k].zhi=sta1[i].zhi+sta2[j].zhi;
            k++;
        }
    }
    qsort(p,k,sizeof(p[0]),comfuc);
    for(int i=0;i<k;i++){
        if(p[i].zhi==p[i+1].zhi&&p[i].zhi!=0){
            p[i+1].di+=p[i].di;
            p[i].di=0;
        }
    }
    for(int i=0;i<k;i++){
        if(p[i].di!=0){
            printf("%d %d ",p[i].di,p[i].zhi);
        }
    }
    return 0;
}
