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
    while(p=getchar()!='\n'){ @@ // The assignment `p=getchar()!='\n'` is parsed as `p = (getchar() != '\n')`, so `p` becomes 0 or 1, not the actual character. This breaks input parsing.
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){ @@ // Same error: `p` stores boolean result, not the character, causing incorrect loop control and potential infinite loop or missed inputs.
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; @@ // Coefficient should be multiplied, exponent added. Here it's reversed: adding coefficients and multiplying exponents.
            b[e]=l[2*c-1]*y[2*d-1]; @@ // Same reversal error: this line multiplies coefficients but stores in `b` (which holds exponents), and previous line adds exponents into `a` (which should hold exponents).
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e); @@ // Sorting by `a[]` (which incorrectly holds sums of coefficients) instead of exponents. Should sort by exponents descending.
    while(f<=(e+1)){ @@ // Loop condition goes beyond array bounds (`f <= e+1`), accessing `a[f+1]` when `f == e+1` leads to out-of-bounds read.
        if(a[f]==a[f+1]){ @@ // Comparing `a[f]` (incorrectly stored coefficient sums) for combining like terms, but should compare exponents.
            b[f]=b[f]+b[f+1]; @@ // Adding `b[f]` (incorrectly stored products of coefficients) — logic is backwards due to earlier swap of roles of a[] and b[].
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;}
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e); @@ // Again sorting by wrong array (a[] is not exponents).
    for(f=1;f<=(e+2);f++){ @@ // Loop runs to `e+2`, which accesses uninitialized or out-of-bound elements, causing extra zero terms in output.
        printf("%d %d ",b[f],a[f]); @@ // Printing `b[f]` (coefficient?) then `a[f]` (exponent?), but due to earlier errors, roles are swapped and data is corrupted.
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }