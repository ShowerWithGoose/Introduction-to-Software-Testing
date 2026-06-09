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
        for(int k=0;k<=i;k++,m++){ // @@ [Loop condition `k<=i` is incorrect: `a` has valid indices from 0 to i-1, so this accesses a[i] which is uninitialized. Also, `m` is incremented inside loop but used as index without bounds check, risking buffer overflow in `c`.]
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ [Loop condition `k<=m` goes out of bounds: `c` has indices 0 to m-1, so `c[m]` is invalid. Also, inner loop uses `xk<=sum`, which may access beyond valid range.]
        for(int xk=0;xk<=sum;xk++){ // @@ [Loop condition `xk<=sum` accesses `c[sum]` which is out of bounds since valid indices are 0 to sum-1. Additionally, modifying `sum` during iteration leads to unpredictable behavior and missed merges.]
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp); // @@ [`m` is total number of generated terms, but after merging some terms are marked with `exp=-1`. Sorting before filtering or using unfiltered `m` includes invalid terms and misses proper consolidation.]
    for(int s=0;s<sum;s++){
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}