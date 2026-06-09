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
        for(int k=0;k<=i;k++,m++){ // @@ [Loop condition 'k<=i' is incorrect: 'i' is the count of terms in 'a', but valid indices are 0 to i-1. This causes out-of-bounds access to a[i]. Also, 'm' is incremented inside loop header but used as index without initialization per j iteration, leading to overwriting and incorrect indexing.]
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ [Loop runs up to 'm' inclusive, but 'c' has valid indices from 0 to m-1. This leads to out-of-bounds access. Should be 'k < m'.]
        for(int xk=0;xk<=sum;xk++){ // @@ [Loop runs up to 'sum' inclusive, but 'sum' equals 'm', and 'c' only has 'm' elements (0 to m-1). Also, modifying 'sum' during iteration breaks loop logic and causes undefined behavior.]
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp);
    for(int s=0;s<sum;s++){ // @@ [After merging terms by marking with exp=-1, the array 'c' is not re-filtered or compacted. The sort uses original 'm', but printing uses 'sum' which was decremented arbitrarily during merging, leading to printing uninitialized or zeroed terms and missing others. Also, terms with exp=-1 may still be printed if not skipped.]
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}