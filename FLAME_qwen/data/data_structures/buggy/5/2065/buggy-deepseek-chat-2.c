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
        for(int k=0;k<=i;k++,m++){ // @@ The loop condition should be k < i (since i is the index of the last element, the count is i+1), but using <= i causes an off-by-one error, accessing a[i] which may be uninitialized or out of bounds.
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ The loop condition should be k < m (since m is the count of elements), using <= m accesses out-of-bounds index c[m].
        for(int xk=0;xk<=sum;xk++){ // @@ The loop condition should be xk < sum (since sum is the count), using <= sum accesses out-of-bounds index c[sum].
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp); // @@ After merging, the actual number of valid elements is sum, not m. Sorting should use sum as the count, otherwise it includes invalid entries with exp=-1.
    for(int s=0;s<sum;s++){
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}