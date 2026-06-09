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
    while(p=getchar()!='\n'){
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d];
            b[e]=l[2*c-1]*y[2*d-1];
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e); // @@ Error: e includes an extra uninitialized term (since index e is beyond the actual product terms), causing a zero‑exponent term to be sorted into the array, which later corrupts combination and output.
    while(f<=(e+1)){ // @@ Error: Condition should be f <= e-1 to only iterate over actual terms; using (e+1) includes uninitialized indices a[e] and a[e+1], causing false matches of zero exponents.
        if(a[f]==a[f+1]){ // @@ Error: Compares a[f] with a[f+1] where f+1 may be out of the valid range; moreover, a[f+1] might be the extra zero term, leading to incorrect merging.
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;} // @@ Error: The shifting loop uses e as the upper bound, but e may not represent the actual number of terms (e could be larger than the count of valid terms).
            e--; // @@ Error: Decrements e incorrectly; does not reflect the true number of remaining terms after merging.
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e); // @@ Error: After the erroneous combination, e is wrong (e.g., becomes 0 for one term), causing the sort to operate on an incorrect range and potentially misorder the remaining terms.
    for(f=1;f<=(e+2);f++){ // @@ Error: Prints up to index e+2, which always includes at least two extra terms (since e is incorrectly reduced), leading to unwanted "0 0" at the end.
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }