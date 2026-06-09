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
            swap(a, i, p); // @@ The swap function does not correctly reverse the previous swap. It performs a left-shift insertion instead of a simple element exchange, which breaks permutation generation and causes incorrect state restoration.
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
    a[p]=temp; // @@ This "swap" is not a true swap—it shifts elements between p and i, altering more than two positions. This destroys the array state needed for correct backtracking in permutation generation.
}