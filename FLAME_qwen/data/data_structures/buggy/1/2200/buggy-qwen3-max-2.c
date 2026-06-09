#include<stdio.h>
int a[10],book[10],n; // @@ [Array size is insufficient for N=10 when using 1-based indexing; should be at least size 11 or 15 as in reference]
void  dfs(int step){ 
    int i;
    if(step==n+1){   
        for(i=1;i<=n;i++)
            printf("%d",a[i]); // @@ [Missing space after each number; output format requires space separation]
        printf("\n");
        return ;
    }
     for(i=1;i<=n;i++){
        if(book[i]==0){ 
            a[step]=i;
            book[i]=1;    
            dfs(step+1);
            book[i]=0;
        }
    }
    return;

}
int main(){
    scanf("%d",&n);
    dfs(1);  
    return 0;
}