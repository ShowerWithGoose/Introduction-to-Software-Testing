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
        for(int k=0;k<=i;k++,m++){ // @@ The loop condition should be k < i (since i is the index of the last element, the count is i+1), and the increment of m inside the loop causes m to be incremented multiple times per iteration of the outer loop, leading to incorrect indexing and potential out-of-bounds access.
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ The loop condition should be k < m, not k <= m, because m is the total number of elements (after the previous loop, m is the count), and using <= will access out-of-bounds index m.
        for(int xk=0;xk<=sum;xk++){ // @@ The loop condition should be xk < sum, not xk <= sum, to avoid out-of-bounds access.
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp); // @@ After modifying sum, the array size should be m (original count), but the sorting should be done on the original m elements, not the reduced sum. However, the logic of combining terms is flawed; the correct approach is to sort first, then combine adjacent terms. Additionally, using m here is correct for the original count, but the combination loop above incorrectly modifies sum and may leave gaps.
    for(int s=0;s<sum;s++){ // @@ The loop should iterate over all m elements (or the combined count), but sum has been reduced incorrectly. This will miss terms and may print incomplete results.
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}