#include<stdio.h>
int a[10],book[10],n; // @@ array size should be at least 11 to safely access indices 1..n when n=10
void  dfs(int step){ 
    int i;
    if(step==n+1){   
        for(i=1;i<=n;i++)
            printf("%d",a[i]); // @@ missing space: should be "%d " to separate numbers
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