#include<stdio.h>
int a[10],b[10]={0};
int n;
void dfs(int x) {
    int i;
    if(x==n){
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(i=0;i<n;i++){
        if(b[i]==0){            
            a[x]=i+1;
            b[i]=1;             
            dfs(x+1);
            b[i]=0;              
        }
    }
}int main(){
    scanf("%d",&n);
    dfs(0);
    return 0;
}

