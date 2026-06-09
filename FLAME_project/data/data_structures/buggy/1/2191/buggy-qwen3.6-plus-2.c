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
        for(e=0;e<m;e++)  printf("%c",b[e]); // @@ The output format is incorrect. The problem requires integers separated by spaces (e.g., "1 2"), but this code prints characters without spaces (e.g., "12"). Additionally, using char array limits the solution to single-digit numbers, though N<=10 makes '10' two chars, breaking the logic further if not handled. The primary error here is the lack of space separation and wrong type usage for integer output.
        printf("\n");
        return;
    }
    for(i=1;i<=k;i++){
        if(a[i]==0){
            a[i]=1;
            b[m]='0'+i;
            f(m+1,n-1);
            a[i]=0;
        }
    }
}