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
    while(p=getchar()!='\n'){ // @@ Operator precedence: `p=getchar()!='\n'` is parsed as `p = (getchar() != '\n')`, so p is 0 or 1, not the character. Should be `(p=getchar())!='\n'`.
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){ // @@ Same operator precedence issue as above.
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; // @@ Incorrect: should store exponent, but here stores sum of coefficients? Actually should be sum of exponents, but l[2*c] and y[2*d] are exponents? The input stores coefficient and exponent alternately, so l[2*c] is exponent of first polynomial, y[2*d] is exponent of second polynomial. This line is correct for exponent, but the array indexing assumes 1-based and alternating pattern, which may be fragile.
            b[e]=l[2*c-1]*y[2*d-1]; // @@ Correct: coefficient product.
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e); // @@ The sort function expects 1-based indexing and n as number of elements, but e is the count after increment, so e-1 is the actual number of elements. Also, the function sorts by a (exponent) descending, which is correct.
    while(f<=(e+1)){ // @@ Loop condition uses e+1, but e is the count after last increment, so the valid indices are 1 to e-1. This may cause out-of-bounds access.
        if(a[f]==a[f+1]){ // @@ Potential out-of-bounds when f == e-1, accessing a[e] which is uninitialized.
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;} // @@ Shifting loop may go out of bounds when g == e, accessing a[e+1] and b[e+1].
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e); // @@ After merging, e is reduced, but the sort function still uses e as count, which is now correct.
    for(f=1;f<=(e+2);f++){ // @@ Loop runs up to e+2, which is too many iterations, printing uninitialized or garbage values.
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }