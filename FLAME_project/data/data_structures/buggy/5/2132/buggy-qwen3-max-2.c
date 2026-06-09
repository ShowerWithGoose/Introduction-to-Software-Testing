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
    while(p=getchar()!='\n'){ @@ // The assignment `p = getchar() != '\n'` is parsed as `p = (getchar() != '\n')`, so `p` becomes 0 or 1, not the actual character. This breaks input parsing.
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){ @@ // Same error: `p` stores boolean result, not the character, causing incorrect loop control and potential infinite loop or missed inputs.
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; @@ // Exponent should be sum of exponents, but l[2*c] is coefficient if input alternates coeff-exp; indexing assumes even positions are exponents, but input starts with coeff at index 1, so l[2*c] is exponent only if c starts correctly. However, more critically: this line uses `l[2*c]` which may be out of bounds when m is odd or small. Also, logic assumes fixed pairing but input reading is broken.
            b[e]=l[2*c-1]*y[2*d-1]; @@ // Coefficient multiplication is correct in intent, but relies on correct parsing which failed earlier.
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e);
    while(f<=(e+1)){ @@ // Loop condition `f <= (e+1)` accesses `a[f+1]` when f = e+1 → a[e+2], which is out of bounds. Should be `f < e`.
        if(a[f]==a[f+1]){ @@ // Accesses a[f+1] beyond array when f == e, leading to undefined behavior.
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;}
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e);
    for(f=1;f<=(e+2);f++){ @@ // Loop runs to `e+2`, but valid indices are 1..e. This prints uninitialized/garbage values (like the extra "0 0" in output).
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }