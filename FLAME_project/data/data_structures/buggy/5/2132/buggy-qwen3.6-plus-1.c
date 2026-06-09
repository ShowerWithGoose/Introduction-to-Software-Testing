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
    while((p=getchar())!='\n'){ // @@ [The original code `p=getchar()!='\n'` assigns the boolean result (0 or 1) to p due to operator precedence, causing an infinite loop or incorrect parsing. It should be `(p=getchar())!='\n'`. Also, this logic skips reading the exponents entirely, assuming input is just coefficients, but the problem states pairs of coefficient and exponent.]
        m++;scanf("%d",&l[m]);} // @@ [This loop structure is fundamentally flawed for reading pairs of integers (coefficient, exponent). It reads one integer, then checks for newline. If the input is "8 1000000000", it reads 8, checks space (not newline), reads 1000000000 into next slot. This mixes coefficients and exponents into a single array `l` without distinction, making subsequent pairing logic `l[2*c]` and `l[2*c-1]` unreliable if spacing varies or if newlines are involved incorrectly.]
    scanf("%d",&y[n]);
    while((p=getchar())!='\n'){ // @@ [Same error as above: operator precedence issue with `p=getchar()!='\n'`. Should be `(p=getchar())!='\n'`. ]
        n++;scanf("%d",&y[n]);} // @@ [Same structural flaw: fails to correctly parse coefficient-exponent pairs into separate structures or handle the input format robustly.]
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; // @@ [Logic Error: The problem requires multiplying polynomials. The exponent of the product term is the SUM of exponents, and the coefficient is the PRODUCT of coefficients. Here, `a` stores exponents and `b` stores coefficients (based on the print statement `printf("%d %d ",b[f],a[f])`). So `a[e]` (exponent) should be sum of exponents. However, `l` and `y` arrays contain mixed data due to previous parsing errors. Assuming `l[2*c-1]` is coeff and `l[2*c]` is exp for poly 1, and similarly for `y`, this line calculates sum of exponents correctly IF the indexing was correct. But see below for coefficient calculation.]
            b[e]=l[2*c-1]*y[2*d-1]; // @@ [Logic Error: Calculates product of coefficients. This is correct for polynomial multiplication. However, the indexing relies on the flawed input parsing. If input parsing stored coeffs at odd indices and exps at even, this might work logically, but the parsing loop `while(p=getchar()!='\n')` is broken.]
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e);
    while(f<=(e+1)){ // @@ [Boundary Error: The loop condition `f<=(e+1)` accesses `a[f+1]` inside the loop, which can go out of bounds when `f` is `e` or `e+1`. It should likely be `f < e` or similar, ensuring `f+1` is valid within the current size `e`. Also, `e` changes inside the loop, so the bound should be dynamic or checked carefully.]
        if(a[f]==a[f+1]){
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;}
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e);
    for(f=1;f<=(e+2);f++){ // @@ [Output Boundary Error: Prints up to `e+2`, which includes uninitialized or garbage values. It should print up to `e`. Also, it prints terms with zero coefficients if they weren't filtered out properly, although the merging step attempts to remove duplicates. The main issue is printing beyond the valid number of terms `e`.]
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }