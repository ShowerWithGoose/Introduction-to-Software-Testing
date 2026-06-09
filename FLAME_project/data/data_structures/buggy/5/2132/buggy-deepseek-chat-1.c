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
    while(p=getchar()!='\n'){ // @@ The condition `p=getchar()!='\n'` is incorrect due to operator precedence; it assigns the result of `getchar()!='\n'` (0 or 1) to p, not the character. This causes incorrect input reading.
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){ // @@ Same operator precedence issue as above; this loop will not read input correctly.
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; // @@ This stores the sum of exponents (from l[2*c] and y[2*d]) into array a, but a is intended for exponents; however, the logic for indexing is flawed because l and y store coefficients and exponents interleaved, and the loop bounds (m+1)/2 may not correctly represent the number of terms.
            b[e]=l[2*c-1]*y[2*d-1]; // @@ This stores the product of coefficients into array b, but the indexing assumes l[1], l[3], ... are coefficients, which may be incorrect if input reading failed.
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e);
    while(f<=(e+1)){
        if(a[f]==a[f+1]){
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;}
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e);
    for(f=1;f<=(e+2);f++){ // @@ The loop runs up to e+2, which may exceed the valid array indices, causing out-of-bounds access and printing extra zeros.
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }