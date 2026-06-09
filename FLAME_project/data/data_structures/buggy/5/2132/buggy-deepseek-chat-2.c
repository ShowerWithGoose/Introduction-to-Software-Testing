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
    while(p=getchar()!='\n'){ // @@ [Error: Operator precedence issue. The expression `p=getchar()!='\n'` is parsed as `p = (getchar() != '\n')`, so `p` gets the boolean result (0 or 1) instead of the character. This causes incorrect reading of input, leading to wrong polynomial data.]
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){ // @@ [Same operator precedence issue as above, causing incorrect input reading for the second polynomial.]
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; // @@ [Error: The exponent should be the sum of exponents, but here `l[2*c]` and `y[2*d]` are coefficients, not exponents. The array indexing is incorrect; exponents are stored at odd indices (2*c-1) and coefficients at even indices (2*c).]
            b[e]=l[2*c-1]*y[2*d-1]; // @@ [Error: The coefficient should be the product of coefficients, but here `l[2*c-1]` and `y[2*d-1]` are exponents, not coefficients. The array indexing is swapped.]
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
    for(f=1;f<=(e+2);f++){ // @@ [Error: Loop condition `f<=(e+2)` may print extra elements beyond the valid data, causing output of uninitialized or zero values like "0 0".]
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }