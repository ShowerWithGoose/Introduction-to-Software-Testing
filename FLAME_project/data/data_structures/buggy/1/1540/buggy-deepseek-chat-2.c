#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[10005];
int b[10005];
void f(int *a,int *b,int m,int n);
int main(){
    int m;
    scanf("%d",&m);
    f(a,b,m,1);
    
    return 0;
}
void f(int *a,int *b, int m,int n){
    int i;
    if(n==m+1){
        for(i=1;i<=m;i++)
            printf("%d",a[i]); // @@ Missing space between numbers; should be "%d " for each number except the last, or use a space separator.
        printf("\n");
        return;
    }
    for(i=1;i<=m;i++){
        if(b[i]==0){
            b[i]=1;
            a[n]=i;
            f(a,b,m,n+1);
            b[i]=0;
        }
    }
}