#include<stdio.h>
#include<string.h>
int n,a[11],b[11];
void search(int x){
    if(x==n){
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");return;
    }
    for(int i=1;i<=n;i++){
        if(b[i]) continue;
        b[i]=1;a[x+1]=i;search(x+1);b[i]=0;
    }
}
int main(){
    scanf("%d",&n);
    search(0);
    return 0;
}
