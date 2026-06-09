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
    f(a,b,m,1); // @@ [The function call passes m as the third argument and 1 as the fourth, but the reference program initializes the recursion with m=0 and n as the total count. Here, the logic is inverted: the recursion should start with n=0 and use m as the total number of elements, but the function uses n as the current depth and m as the total. The initial call should be f(a,b,m,0) to match the reference program's logic where the first parameter is the current index (starting from 0) and the second is the total count.]
    
    return 0;
}
void f(int *a,int *b, int m,int n){
    int i;
    if(n==m+1){ // @@ [The base condition should be n==m, not n==m+1, because the recursion starts at n=1 and should stop when n reaches m+1, but the reference program starts at 0 and stops at n. Since the initial call passes 1 instead of 0, the condition is off by one. To match the reference, the initial call should be f(a,b,m,0) and the condition should be n==m.]
        for(i=1;i<=m;i++)
            printf("%d",a[i]); // @@ [Missing space between numbers. The reference program prints each number followed by a space, but this prints them concatenated without spaces. Should be printf("%d ",a[i]);]
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