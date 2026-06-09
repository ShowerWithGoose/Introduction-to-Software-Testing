#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int a[1001],b[1001],l[101],y[101];
 void optiBubbleSort(int a[],int b[], int n)
 {
 int i, j, hold, swapFlag;
 for (i = 1; i < n; i++)
 {
 swapFlag = 0;
 for (j = 1; j <= n - i; j++)
 {
 if (a[j] < a[j + 1])
 {
 swapFlag = 1;
 hold = a[j];
 a[j] = a[j + 1];
 a[j + 1] = hold;
 hold = b[j];
 b[j] = b[j + 1];
 b[j + 1] = hold;
 
 }
 }
 if (0 == swapFlag)
 break;
 }
 }
int main()
{
    int m=1,n=1,c=1,d=1,e=1,f=1,g=1;
    char p,q;
    scanf("%d",&l[m]);
    while(p=getchar()!='\n'){ // @@ [Operator precedence error: '=' has lower precedence than '!=', so it should be while((p=getchar())!='\n')]
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){ // @@ [Same operator precedence error as above]}
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; // @@ [Incorrect indexing: l and y store alternating coefficient and exponent, but this assumes even indices are exponents and odd are coefficients without validation; also accesses l[2*c] which may be out of bounds when c=(m+1)/2 and m is odd]
            b[e]=l[2*c-1]*y[2*d-1]; // @@ [Same indexing issue: assumes l[2*c-1] is coefficient, but input parsing doesn't guarantee correct pairing due to flawed reading loop]
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e); // @@ [optiBubbleSort expects arrays starting at index 1, but a and b are used with 1-based indexing inconsistently; also sorts by 'a' (exponents) descending, but later logic assumes sorted order]
    while(f<=(e+1)){ // @@ [Loop condition goes beyond array bounds: when f == e+1, accessing a[f+1] is a[e+2], which is uninitialized]
        if(a[f]==a[f+1]){ // @@ [Accesses a[f+1] when f can be e+1, leading to out-of-bounds read]
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;} // @@ [Shifting elements leaves last element uninitialized and doesn't handle multiple merges correctly]
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e); // @@ [Redundant sort after merging, but more critically, the merge logic is flawed and may leave zero-coefficient terms]
    for(f=1;f<=(e+2);f++){ // @@ [Loop runs to e+2, which accesses uninitialized memory beyond the valid range of a and b arrays]
        printf("%d %d ",b[f],a[f]); // @@ [Prints even zero-coefficient terms and uninitialized values due to incorrect loop bound and missing zero-term filtering]
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }