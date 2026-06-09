#include <stdio.h>
#include <string.h>
#include <math.h>

int a[12];
char b[12]; @@ Array size is insufficient to hold permutations with spaces for N up to 10. Should be at least 22.
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
        for(e=0;e<m;e++)  printf("%c",b[e]); @@ Prints characters without spaces because the space separator was never stored in the array.
        printf("\n");
        return;
    }
    for(i=1;i<=k;i++){
        if(a[i]==0){
            a[i]=1;
            b[m]='0'+i; @@ Fails to insert a space after the number as required by the output format. Should store a space at b[m+1].
            f(m+1,n-1); @@ Increments m by 1, but should increment by 2 to skip the space character that should be stored after each number.
            a[i]=0;
        }
    }
}