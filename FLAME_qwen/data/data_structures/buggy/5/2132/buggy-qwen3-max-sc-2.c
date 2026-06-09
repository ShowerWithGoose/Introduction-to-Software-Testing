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
    while(p=getchar()!='\n'){ // @@ [Operator precedence error: '=' has lower precedence than '!=', so it evaluates as p = (getchar() != '\n'), assigning a boolean to char p. Should be (p = getchar()) != '\n'. Also, first term already read, but loop condition doesn't account for possible EOF or format errors.]
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){ // @@ [Same operator precedence error as above. Also, assumes input always alternates coefficient/exponent correctly, but indexing logic is flawed.]
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){ // @@ [Loop bounds assume m is odd (number of inputs is even), but m counts total integers read, not terms. If m is even, this may access out-of-bounds array elements like l[2*c].]
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; // @@ [Exponent should be sum of exponents, but l[2*c] is the (2c)-th integer read, which may not be an exponent if indexing is off. Also, coefficients are multiplied, not added — this line swaps coefficient and exponent roles incorrectly.]
            b[e]=l[2*c-1]*y[2*d-1]; // @@ [This assigns product of coefficients to b[e], but then a[e] holds exponent sum. However, later printing uses b[f] as coefficient and a[f] as exponent, which is correct, but the storage here is reversed in naming (a=exponent, b=coefficient). The real issue is incorrect indexing: l[2*c-1] is coefficient, l[2*c] is exponent only if input is perfectly paired starting at index 1. But m counts total numbers, so if m=3 (invalid, since terms need pairs), behavior is undefined.]
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e); // @@ [optiBubbleSort expects arrays indexed from 1 to n, but e is the count of products, and the sort function accesses a[j+1] up to j = n - i, which when n=e, may access a[e+1] → out-of-bounds. Also, the sort function sorts by a[] (exponents) descending, which is correct, but the merge step below is flawed.]
    while(f<=(e+1)){ // @@ [Loop condition f <= e+1 causes access to a[f+1] when f=e+1 → a[e+2], which is out-of-bounds. Should be f < e.]
        if(a[f]==a[f+1]){ // @@ [Accesses a[f+1] without ensuring f+1 <= e, leading to out-of-bounds read. Also, after shifting elements down, it doesn't re-check the current f against the new next element (should not increment f after merging).]
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;} // @@ [Shifting loop goes to g<=e, so a[g+1] when g=e is a[e+1], which is uninitialized/out-of-bounds. Should be g < e.]
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e); // @@ [Redundant sort after merging, but more importantly, if merging created zero-coefficient terms, they are not removed. The final print loop doesn't skip zero coefficients.]
    for(f=1;f<=(e+2);f++){ // @@ [Loop runs to f <= e+2, which accesses b[e+2] and a[e+2] — far beyond valid range (valid indices 1..e). Should be f <= e. Also, if any coefficient became zero during merging, it still prints it, violating problem requirement to omit zero terms.]
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }