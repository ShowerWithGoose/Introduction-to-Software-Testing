#include<stdio.h>

int n;
int a[1000],b[1000];

void qp(int x){  //全排列递归函数
    int i;
    if(x==n+1){
        for(i=1;i<n;i++){
            printf("%d ",b[i]);
        }
        printf("%d\n",b[n]);
        return;
    }
    for(i=1;i<=n;i++){
        if(a[i]==0){
            b[x]=i;a[i]=1;
            qp(x+1);
            a[i]=0;
        }
    }
}

int main(){
    scanf("%d",&n);
    qp(1);
    return 0;
}
