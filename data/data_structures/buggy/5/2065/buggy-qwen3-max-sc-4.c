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
        for(int k=0;k<=i;k++,m++){ // @@ [Loop bound error: 'k <= i' accesses a[i] which is one past the last valid element; also, m is incremented inside loop but used as index without initialization per j]
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ [Loop bound error: should be k < m, not k <= m; also, inner loop uses xk <= sum which may exceed array bounds]
        for(int xk=0;xk<=sum;xk++){ // @@ [Loop bound error: xk <= sum goes out of bounds since valid indices are 0 to m-1; also modifies 'sum' during iteration causing undefined behavior]
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp);
    for(int s=0;s<sum;s++){ // @@ [Incorrect output count: 'sum' was decremented during merging but array wasn't compacted; also, terms with zero coefficient aren't filtered]
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}