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
    while(p=getchar()!='\n'){ // @@ Operator precedence: `!=` has higher precedence than `=`, so `p` is assigned the result of `getchar()!='\n'` (0 or 1), not the character itself. This causes incorrect input reading.
        m++;scanf("%d",&l[m]);}
    scanf("%d",&y[n]);
    while(p=getchar()!='\n'){ // @@ Same operator precedence issue as above.
        n++;scanf("%d",&y[n]);}
//    printf("%d",m);
    for(c=1;c<=(m+1)/2;c++){
        for(d=1;d<=(n+1)/2;d++){
            a[e]=l[2*c]+y[2*d]; // @@ Logic error: Should store exponent (sum of exponents) in a[e], but l[2*c] and y[2*d] are coefficients, not exponents. The input stores coefficient and exponent alternately, so exponents are at odd indices (2*c-1 and 2*d-1), not even.
            b[e]=l[2*c-1]*y[2*d-1]; // @@ Logic error: Should store coefficient (product of coefficients) in b[e], but l[2*c-1] and y[2*d-1] are exponents, not coefficients. Coefficients are at even indices (2*c and 2*d).
            e++;
        }
    }
    optiBubbleSort(&a[1],&b[1], e);
    while(f<=(e+1)){
        if(a[f]==a[f+1]){
            b[f]=b[f]+b[f+1];
            g=f+1;while(g<=e){a[g]=a[g+1];b[g]=b[g+1];g++;}
            e--;
            continue;
        }f++;
    }
    optiBubbleSort(&a[1],&b[1], e);
    for(f=1;f<=(e+2);f++){ // @@ Off-by-one error: Loop condition should be f <= e, not f <= (e+2), to avoid printing uninitialized or out-of-bounds array elements.
        printf("%d %d ",b[f],a[f]);
    }
//    for(f=1;f<=m;f++)printf("%d ",l[f]);
//    for(f=1;f<=n;f++)printf("%d ",y[f]);
    return 0;
 }