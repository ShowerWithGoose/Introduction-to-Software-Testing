#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rank(int a[],int b[],int n,int d);

int main()
{
    int n,a[100]={0},b[100]={0};
    scanf("%d",&n);
    rank(a,b,n,1);
    return 0;
}

void rank(int a[],int b[],int n,int d)
{
    int i;
    if(d==n+1){
        for(i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]){
            b[i]=1;
            a[d]=i;
            rank(a,b,n,d+1);
            b[i]=0;
        }
    }
}

