#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))

void perm(int a[], int p, int q);
void swap(int a[], int i, int p);
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
            swap(a, i, p);
            perm(a, p+1, q);//递归 
            swap(a, i, p); // @@ [The second call to swap does not reverse the initial shift. The swap function performs a right shift, so calling it again with the same arguments does not restore the array; it produces a different arrangement. A separate left-shift function (like swapback in the reference) is needed to correctly undo the change. This logical error causes the permutation generation to be incorrect.]
        }
    }
}

void swap(int a[], int i, int p){
    int temp, re;
    temp=a[i];
    re=i;
    for(i=re; i>p; i--){
        a[i]=a[i-1];
    }
    a[p]=temp;
}