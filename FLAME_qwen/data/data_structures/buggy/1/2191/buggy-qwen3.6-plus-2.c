#include <stdio.h>
#include <string.h>
#include <math.h>

int a[12];
char b[12]; // @@ Array size is insufficient to store both digits and space separators for N up to 10, and the code lacks space handling.
int k;
void f(int m,int n);

int main(){
    scanf("%d",&k);
    f(0,k);
    
    return 0;
}

void f(int m,int n){
    int e,i;
    if(n==0){
        for(e=0;e<m;e++)  printf("%c",b[e]); // @@ Prints characters without spaces between them, violating the output format requirement.
        printf("\n");
        return;
    }
    for(i=1;i<=k;i++){
        if(a[i]==0){
            a[i]=1;
            b[m]='0'+i; // @@ Only stores the digit character, missing the required space separator between numbers.
            f(m+1,n-1);
            a[i]=0;
        }
    }
}