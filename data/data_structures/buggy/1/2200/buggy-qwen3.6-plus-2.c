#include<stdio.h>
int a[10],book[10],n; // @@ Array size should be at least 11 to safely access indices 1 to N when N=10, otherwise accessing index 10 causes out-of-bounds error.
void  dfs(int step){ 
    int i;
    if(step==n+1){   
        for(i=1;i<=n;i++)
            printf("%d",a[i]); // @@ Missing space separator between integers in the output, should be printf("%d ", a[i]); to match the required format.
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