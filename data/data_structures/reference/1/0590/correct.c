#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[20];
int b[20];
int fun(int*a,int*b,int n,int x){
    int i;
    if(x==n+1){
        for(i=1;i<=n;i++){
            printf("%d ",a[i]);
        }printf("\n");return 0;
    }


    for(i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=1;
            a[x]=i;
            fun(a,b,n,x+1);
            b[i]=0;
        }
    }
}
int main(){
int n;
scanf("%d",&n);
fun(a,b,n,1);






return 0;}

