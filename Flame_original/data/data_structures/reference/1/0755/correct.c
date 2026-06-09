#include<stdio.h>
int a[10],book[10]={0};
int n;
void dfs(int step)
{
    int i;
    if(step==n){
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(i=0;i<n;i++){
        if(book[i]==0){
            a[step]=i+1;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}
