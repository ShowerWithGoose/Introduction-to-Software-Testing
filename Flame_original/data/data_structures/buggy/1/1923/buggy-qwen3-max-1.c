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
            swap(a, i, p); // @@ [The swap function does not correctly reverse the previous swap. The current swap implementation shifts elements instead of performing a simple exchange, so swapping back with the same function does not restore the original array state, leading to incorrect permutations and violating lexicographical order.]
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
    a[p]=temp; // @@ [This function does not perform a standard swap; instead, it rotates/shifts elements from position p to i, which breaks the permutation generation logic. A correct swap should only exchange two elements, not shift a block.]
}