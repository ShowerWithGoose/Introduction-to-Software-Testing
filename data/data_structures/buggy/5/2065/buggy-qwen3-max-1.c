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
        for(int k=0;k<=i;k++,m++){ // @@ [Loop condition 'k<=i' is incorrect: 'i' is the count of terms in 'a', but valid indices are 0 to i-1. This causes out-of-bounds access to a[i]. Also, 'm' is incremented inside loop header but used as index before being updated correctly.]
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ [Loop condition 'k<=m' accesses c[m], which is out of bounds since valid indices are 0 to m-1. Should be 'k < m'.]
        for(int xk=0;xk<=sum;xk++){ // @@ [Loop condition 'xk<=sum' may access c[sum], which is out of bounds. Also, 'sum' is modified inside the loop, leading to unpredictable behavior and possible missed merges or double-counting.]
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp);
    for(int s=0;s<sum;s++){ // @@ [After merging, some terms may have coefficient zero (not just exp=-1), but the code only skips terms with exp==-1 during merge. However, it prints all remaining terms without checking if coefficient is zero, which violates problem requirement to omit zero-coefficient terms. Additionally, 'sum' was decremented during merging but array wasn't compacted, so c[s] for s near original 'm' may contain garbage or unmerged zero terms.]
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}