#include <stdio.h>
int n;
int a[12],b[12];
void dfs(int step) {
    if(step==n+1) {
        for (int i=1; i<=n; i++) {
            printf("%d",a[i]); // @@ [The numbers are printed without spaces, but the required output format has spaces between each number.]
        }
        printf("\n");
        return ;
    }
    for(int i=1; i<=n; i++) {
        if(b[i]==0) {
            a[step]=i;
            b[i]=1;
            dfs(step+1);
            b[i]=0;        
        }

    }


}
int main() {
    scanf("%d",&n);
    dfs(1);


    return 0;
}