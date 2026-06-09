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
            swap(a, i, p); // @@ Error: This second swap does not undo the first rotation (right shift) – it applies the same right rotation again, corrupting the array for subsequent permutations. The inverse of the rotation should be a left shift, not the same operation.
        }
    }
}

void swap(int a[], int i, int p){
    int temp, re;
    temp=a[i];
    re=i;
    for(i=re; i>p; i--){ // @@ Error: This function performs a right rotation of subarray a[p..i], not a simple swap. This rotation is not symmetric (its inverse is a left rotation), causing incorrect backtracking when called the second time.
        a[i]=a[i-1];
    }
    a[p]=temp;
}