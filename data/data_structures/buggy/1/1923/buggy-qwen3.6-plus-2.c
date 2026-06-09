#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))

void perm(int a[], int p, int q);
void swap(int a[], int i, int p); // @@ The function name 'swap' may conflict with a system macro or function defined in standard headers (e.g., <sys/param.h> or <stdlib.h> on some platforms), causing a compilation error. It should be renamed.
int main()
{
    int n, i;
    int a[100];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        a[i]=i+1;
    }
    perm(a, 0, n-1);
    return 0;
}

void perm(int a[], int p, int q){//p前面，q后面 
    int i, len;
    if(p==q){
        len=q+1;
        for(i=0; i<len; i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    else{
        for(i=p; i<=q; i++){
            swap(a, i, p); // @@ 'swap' name conflict; also logically this shifts elements, but the subsequent call should reverse the shift to backtrack.
            perm(a, p+1, q);//递归 
            swap(a, i, p); // @@ 'swap' name conflict; logically this should be a 'swapback' function to restore the array state for the next iteration, otherwise permutations will be incorrect.
        }
    }
}

void swap(int a[], int i, int p){ // @@ 'swap' name conflict with system headers; rename to avoid compilation error.
    int temp, re;
    temp=a[i];
    re=i;
    for(i=re; i>p; i--){
        a[i]=a[i-1];
    }
    a[p]=temp;
}