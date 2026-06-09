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
            swap(a, i, p);
        }
    }
}

void swap(int a[], int i, int p){ // @@ The function name 'swap' and its implementation suggest a rotation/shift operation rather than a simple element swap. However, the logic inside performs a right shift of elements from index p to i-1, placing the original a[i] at a[p]. This changes the relative order of elements between p and i, which violates the standard backtracking permutation algorithm that requires restoring the array state exactly. Specifically, when i > p, this operation rotates the subarray a[p..i]. The corresponding "undo" swap(a, i, p) will not correctly restore the original order because the elements have shifted positions. For example, if a=[1,2,3], p=0, i=2: swap shifts to [3,1,2]. Recursive call happens. Then swap(a, 2, 0) is called. Inside swap, i=2, p=0. It takes temp=a[2]=2. Shifts a[0..1] right? No, loop `for(i=re; i>p; i--)` with re=2. i=2: a[2]=a[1]=1. i=1: a[1]=a[0]=3. Then a[0]=temp=2. Result [2,3,1]. Original was [1,2,3]. State is corrupted. This leads to incorrect permutations or duplicates. The standard approach uses a simple element swap: temp=a[i]; a[i]=a[p]; a[p]=temp;
    int temp, re;
    temp=a[i];
    re=i;
    for(i=re; i>p; i--){
        a[i]=a[i-1];
    }
    a[p]=temp;
}