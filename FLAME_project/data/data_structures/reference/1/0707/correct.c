#include<stdio.h>
int x[10],num[10]={0},n;

void dfs(int depth) 
{
    int i;
    if(depth==n){
        for(i=0;i<n;i++){
            printf("%d ",x[i]);
        }
        printf("\n");
        return;
    }
    for(i=0;i<n;i++){
        if(num[i]==0){             
            x[depth]=i+1;
            num[i]=1;              
            dfs(depth+1);
            num[i]=0;              
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}



