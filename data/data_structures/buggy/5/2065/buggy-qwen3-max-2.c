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
        for(int k=0;k<=i;k++,m++){ // @@ [Loop condition `k<=i` is incorrect: `i` is the count of terms in `a`, but valid indices are `0` to `i-1`. This causes out-of-bounds access to `a[i]`. Also, `m` is incremented inside loop header but used as index into `c`, which may exceed array bounds.]
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ [Loop condition `k<=m` accesses `c[m]`, but valid indices are `0` to `m-1`. This is an out-of-bounds read.]
        for(int xk=0;xk<=sum;xk++){ // @@ [Loop condition `xk<=sum` accesses `c[sum]`, but valid indices are `0` to `sum-1` (since `sum = m` and `c` has `m` elements). This is an out-of-bounds read.]
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp);
    for(int s=0;s<sum;s++){ // @@ [After merging like terms, some entries in `c` are marked with `exp = -1` and skipped, but `qsort` was called before removing them, so sorted order includes invalid terms. Also, `sum` was decremented during merging but loop still uses original `sum` logic inconsistently. Moreover, terms with zero coefficient should be omitted, but code only checks `exp != -1`.]
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}