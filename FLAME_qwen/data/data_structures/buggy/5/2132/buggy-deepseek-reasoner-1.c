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
            a[e]=l[2*c]+y[2*d]; // @@ [Possible out-of-bounds: if number of product terms > 1000, e exceeds array size.]
            b[e]=l[2*c-1]*y[2*d-1]; // @@ [Same out-of-bounds issue.]
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e);
    while(f<=(e+1)){ // @@ [Off-by-one error: should be f < e to avoid accessing out-of-bounds a[f+1].]
        if(a[f]==a[f+1]){ // @@ [Potential out-of-bounds when f == e.]
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;} // @@ [When g==e, a[e+1] is out of logical range; should be while(g<e).]
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e);
    for(f=1;f<=(e+2);f++){ // @@ [Off-by-one: should be f <= e to print only the distinct terms; also does not skip zero coefficients.]
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }