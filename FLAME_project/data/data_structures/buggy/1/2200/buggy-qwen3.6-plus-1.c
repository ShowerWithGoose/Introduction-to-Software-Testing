#include<stdio.h>
int a[10],book[10],n;
void  dfs(int step){ 
    int i;
    if(step==n+1){   
        for(i=1;i<=n;i++)
            printf("%d ",a[i]); // @@ The original code printed numbers without spaces (e.g., "12"), but the expected output requires space-separated integers (e.g., "1 2"). Also, the reference program handles the trailing space or format carefully, but simply adding a space after each number is the standard fix for this specific "Wrong Answer" on formatting. Note: The reference program prints a space after the last number too ("1 2 "), which is often accepted or the problem implies strict spacing. However, the primary error in the buggy code is the lack of any separator.
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