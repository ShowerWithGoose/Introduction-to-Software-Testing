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
    optiBubbleSort(&a[1],&b[1], e); // @@ Error: Passes offset pointer, excluding a[0] and including uninitialized element at index e. Should pass a and b directly with count e-1.
    while(f<=(e+1)){ // @@ Error: Loop condition f<=(e+1) is too large; valid indices are 1 to e-1, leading to out-of-bounds access.
        if(a[f]==a[f+1]){ // @@ Error: Potential out-of-bounds when f is e or e+1, and when combining after shifting.
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;} // @@ Error: When g==e, a[g+1] accesses out-of-bounds; also shifting logic incorrect for end of array.
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e); // @@ Error: Same issue as previous sort call.
    for(f=1;f<=(e+2);f++){ // @@ Error: Loop prints up to e+2 elements, but only e-1 valid elements exist; prints uninitialized values.
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }