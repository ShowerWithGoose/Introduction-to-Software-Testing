#include<stdio.h>
int a[10],book[10],n; // @@ Array size is only 10, but indices from 1 to n (n up to 10) cause out-of-bounds access (e.g., a[10] and book[10] are invalid). Should be at least size 11.
void  dfs(int step){ 
    int i;
    if(step==n+1){   
        for(i=1;i<=n;i++)
            printf("%d",a[i]); // @@ Missing space after %d; expected output requires spaces between numbers (e.g., "1 2 3" not "123").
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