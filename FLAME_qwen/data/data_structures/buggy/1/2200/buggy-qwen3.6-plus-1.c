#include<stdio.h>
int a[10],book[10],n; // @@ Array size is 10, but indices 1 to N (up to 10) are accessed, causing out-of-bounds error when N=10. Size should be at least 11.
void  dfs(int step){ 
    int i;
    if(step==n+1){   
        for(i=1;i<=n;i++)
            printf("%d",a[i]); // @@ Missing space separator between integers. The output format requires each integer to be separated by a space.
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