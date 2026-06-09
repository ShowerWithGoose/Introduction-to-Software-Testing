#include<stdio.h>
int n,a[15],vi[15];
void per(int k){
    if(k==n+1){
        for(int i=1;i<=n;++i) printf("%d ",a[i]);
        puts("");
        return;
    }
    for(int i=1;i<=n;++i){
        if(!vi[i]){
            vi[i]=1;a[k]=i;
            per(k+1);
            vi[i]=0;a[k]=0;
        }
    }
}

int main(){
    scanf("%d",&n);
    per(1);
    return 0;
}
