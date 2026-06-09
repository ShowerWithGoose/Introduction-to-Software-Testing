#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct{
    int num;
    int exp;
}asketla;
asketla a[100],b[100],c[1000];

int cmp(const void*aa,const void*ab){
    if(((asketla*)aa)->exp<((asketla*)ab)->exp)
    return 1;
    return -1;
} 

int main(){
    int i;
    scanf("%d%d",&a[0].num,&a[0].exp );
    for(i=1;;i++){
        scanf("%d%d",&a[i].num,&a[i].exp);
        if(getchar()=='\n')
        break;
    }
    int m=0;
    for(int j=0;;j++){
        scanf("%d%d",&b[j].num,&b[j].exp);
        for(int k=0;k<=i;k++,m++){ // @@ Error: The loop condition `k<=i` includes an extra iteration because `i` is the index of the last term read, but the number of terms is `i+1`. This causes out-of-bounds access to `a[i+1]` and `c[m]` beyond allocated size, leading to runtime error.
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ Error: The loop condition `k<=m` includes an extra iteration because `m` is the total number of terms stored (starting from 0), so valid indices are 0 to m-1. Accessing `c[m]` is out-of-bounds, causing runtime error.
        for(int xk=0;xk<=sum;xk++){ // @@ Error: The loop condition `xk<=sum` includes an extra iteration because `sum` is the current count of terms, but valid indices are 0 to sum-1. Accessing `c[sum]` is out-of-bounds, causing runtime error.
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp); // @@ Error: The third argument to qsort should be `m` (the number of elements), but after the merging loop, `sum` is the correct count of valid terms. Using `m` (original count) may include invalid terms with exp=-1, leading to incorrect sorting and output.
    for(int s=0;s<sum;s++){
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}