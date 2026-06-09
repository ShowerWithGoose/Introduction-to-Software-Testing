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
    f(a,b,m,1); // @@ The function call passes 1 as the starting value for n, but the reference program uses 0-based indexing. This causes the recursion to start at n=1 instead of n=0, leading to incorrect permutation generation and missing the first element.
    
    return 0;
}
void f(int *a,int *b, int m,int n){
    int i;
    if(n==m+1){ // @@ The base condition checks n==m+1, but since n starts at 1, this means the recursion will stop after generating m elements, but the array indexing starts at 1, so a[0] is never used. This is inconsistent with the expected 0-based indexing and causes the output to miss the first element or produce incorrect permutations.
        for(i=1;i<=m;i++)
            printf("%d",a[i]); // @@ Missing space between numbers in output. The problem requires each integer to be separated by a space, but this prints them concatenated without spaces.
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