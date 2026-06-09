#include <stdio.h>
#include <string.h>
#include <math.h>

int a[12];
char b[12];
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
        for(e=0;e<m;e++)  printf("%c",b[e]); // @@ [The output uses characters instead of integers with space separation. For input 2, it prints '1' and '2' as adjacent chars "12", but expected "1 2".]
        printf("\n");
        return;
    }
    for(i=1;i<=k;i++){
        if(a[i]==0){
            a[i]=1;
            b[m]='0'+i; // @@ [Storing digits as characters in char array leads to incorrect output format; should store integers and print with spaces.]
            f(m+1,n-1);
            a[i]=0;
        }
    }
}