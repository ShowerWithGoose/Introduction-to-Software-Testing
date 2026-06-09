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
    while((p=getchar())!='\n'){ // @@ [Fixed operator precedence: original code assigned result of comparison to p, causing infinite loop or incorrect parsing. Also added parentheses.]
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while((p=getchar())!='\n'){ // @@ [Fixed operator precedence: original code assigned result of comparison to p, causing infinite loop or incorrect parsing. Also added parentheses.]
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=m/2;c++){ // @@ [Corrected loop bound: l array stores coeff, exp, coeff, exp... so m is total count. Number of terms is m/2. Original (m+1)/2 is incorrect for even m and potentially out of bounds.]
        for(d=1;d<=n/2;d++){ // @@ [Corrected loop bound: y array stores coeff, exp... so n is total count. Number of terms is n/2.]
            a[e]=l[2*c-1]+y[2*d-1]; // @@ [Fixed index logic: l[2*c-1] is coefficient? No, input is coeff exp. Let's trace. Input: 8 1000000000. l[1]=8, l[2]=1000000000. So odd indices are coeffs, even are exponents? Wait. Problem says: "a_n n ...". So first is coeff, second is exp. l[1]=coeff, l[2]=exp. So l[2*c-1] is coeff, l[2*c] is exp. The original code had l[2*c] as exp in addition? No, original: a[e]=l[2*c]+y[2*d]. This adds exponents. So l[2*c] must be exponent. l[2*c-1] must be coefficient. Correct.]
            b[e]=l[2*c-1]*y[2*d-1]; // @@ [Fixed index logic: l[2*c-1] is coefficient, y[2*d-1] is coefficient. Multiply them.]
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e-1); // @@ [Corrected size passed to sort: e was incremented after last insert, so number of elements is e-1.]
    f=1; // @@ [Initialize f before the merging loop. Original code started with f=1 from declaration but logic below is flawed.]
    while(f<e){ // @@ [Corrected loop condition and logic for merging like terms. Original loop condition and inner logic were buggy leading to out of bounds or incorrect merging.]
        if(a[f]==a[f+1]){
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<e){a[g]=a[g+1];b[g]=b[g+1];g++;} // @@ [Fixed shift loop bound to avoid accessing uninitialized/out-of-bounds memory.]
            e--;
            continue;
        }
        f++;
    }
    // optiBubbleSort(&a[1],&b[1], e-1); // @@ [Sorting again is unnecessary if we just merge adjacent equal exponents after initial sort, but if coefficients become zero, they should be removed. The current logic doesn't remove zero coefficients explicitly, just merges. If sum is 0, it stays. We should probably filter zeros.]
    for(f=1;f<=e-1;f++){ // @@ [Corrected loop bound to print valid elements. e-1 is the current count of terms.]
        if(b[f]!=0) // @@ [Add check to skip terms with zero coefficient if any remain after merging.]
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }