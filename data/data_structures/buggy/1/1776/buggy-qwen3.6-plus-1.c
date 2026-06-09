#include <stdio.h>
int n;
int a[12],b[12];
void dfs(int step) {
    if(step==n+1) {
        for (int i=1; i<=n; i++) { // @@ Declaring loop variable inside for loop may cause compilation error in C89/C90 standards
            printf("%d",a[i]); // @@ Missing space separator between integers in output, should be "%d "
        }
        printf("\n");
        return ;
    }
    for(int i=1; i<=n; i++) { // @@ Declaring loop variable inside for loop may cause compilation error in C89/C90 standards
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