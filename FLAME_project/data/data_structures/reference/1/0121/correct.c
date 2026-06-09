#include<stdio.h>
#include<string.h>
int a[10]={0},b[10]={0};
int n;
void dfs(int step) {
    if(step==n){
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++){
        if(b[i]==0){             
            a[step]=i+1;
            b[i]=1;              
            dfs(step+1);
            b[i]=0;              
        }
    }
}


int main(){
    scanf("%d",&n);
    dfs(0);
    return 0;
} 

