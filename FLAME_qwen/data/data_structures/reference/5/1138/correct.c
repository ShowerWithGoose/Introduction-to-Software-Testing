//
// Created by  on 2022/3/25.
//
#include "stdlib.h"
#include "stdio.h"
struct node{
    int base,ex;
};
int cmp(const void *a,const void *b){
    return ((struct node *)b)->ex-((struct node *)a)->ex;
}
struct node A[1000+7],B[1000+7];
struct node ans[1000+7];
int n1,n2;
char ch;
int main(){
    setbuf(stdout,NULL);
    for(n1=0;ch!='\n';n1++){
        scanf("%d %d",&A[n1].base,&A[n1].ex);   ch=getchar();
    }
    ch=0;
    for(n2=0;ch!='\n';n2++){
        scanf("%d %d",&B[n2].base,&B[n2].ex);   ch=getchar();
    }
    n1--;n2--;
    int n;
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            ans[n].base=A[i].base*B[j].base;
            ans[n].ex=A[i].ex+B[j].ex;
            n++;
        }
    }
    qsort(ans,n-1,sizeof(ans[0]),cmp);
//    for(int i=0;i<=n-1;i++) printf("%d ",ans[i].ex);
//    return 0;
    for(int i=0;i<=n-1;i++){
        while(ans[i].ex==ans[i+1].ex && i<=n-1){
            ans[i+1].base+=ans[i].base;
            i++;
        }
        printf("%d %d ",ans[i].base,ans[i].ex);
    }
    return 0;
}
