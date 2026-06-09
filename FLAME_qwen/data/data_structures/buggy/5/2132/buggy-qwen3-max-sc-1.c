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
    while(p=getchar()!='\n'){ @@ // The assignment 'p = getchar() != '\n'' is incorrect due to operator precedence; it assigns the result of the comparison (0 or 1) to p, not the character. Should be: while((p = getchar()) != '\n')
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){ @@ // Same error as above: operator precedence causes p to store boolean result instead of the actual character read.
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; @@ // Incorrect indexing: l and y store alternating coefficient and exponent, but this assumes even indices are exponents and odd are coefficients starting at index 1, which may go out of bounds or misalign data.
            b[e]=l[2*c-1]*y[2*d-1]; @@ // Same indexing issue: assumes input was stored correctly in l[] and y[], but input reading logic is flawed so data layout is wrong.
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e); @@ // Passing &a[1] and &b[1] implies arrays are 1-indexed, but C arrays are 0-indexed; also, the sort function expects full array size, but 'e' may exceed valid range.
    while(f<=(e+1)){ @@ // Loop condition uses f <= e+1, which accesses a[f+1] when f == e+1 → out-of-bounds access (undefined behavior).
        if(a[f]==a[f+1]){ @@ // Accesses a[f+1] without ensuring f+1 <= e → buffer overread.
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;} @@ // Shifts elements left to remove duplicate, but loop condition g<=e writes to b[g] = b[g+1] when g==e → reads b[e+1], which is uninitialized/out-of-bound.
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e); @@ // Same 1-indexing issue; also, after merging terms, array may contain zeros or unsorted data, but sorting again doesn't fix structural issues.
    for(f=1;f<=(e+2);f++){ @@ // Loop runs to f <= e+2, accessing b[f] and a[f] up to index e+2, which is beyond allocated/initialized range → undefined behavior.
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }