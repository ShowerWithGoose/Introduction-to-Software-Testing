#include<stdio.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
int n;
int a[10]={1,2,3,4,5,6,7,8,9,10};
int b;
void chang(int N);
void p(int N);
void p(int N){
    if(N==1){
        FOR(i,0,n-1)printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
    else FOR(i,0,N){
        p(N-1);
        if(i<N-1){
            chang(N-1);
            b=a[n-N],a[n-N]=a[n-N+i+1],a[n-N+i+1]=b;
        }
    }
}
void chang(int N){
    for(int i=n-N,j=n-1;i<j;i++,j--)
        b=a[i],a[i]=a[j],a[j]=b;
    return;
}
int main(){
    scanf("%d",&n);
    p(n);
    return 0;
}