#include<stdio.h>
#include<ctype.h>
#include<string.h>
void f(int a[100],int b[100],int n,int l)
{
    int i;
    if(l==n+1){
        for(i=1;i<=n;i++){
            printf("%d",a[i]); // @@ [Missing space separator between numbers; should be "%d " to match output format.]
        }
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=1;
            a[l]=i;
            f(a,b,n,l+1);
            b[i]=0;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[100]={0};
    int b[100]={0};
    f(a,b,n,1);
    return 0;
}