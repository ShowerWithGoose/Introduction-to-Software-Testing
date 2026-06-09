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
    return -1; // @@ Error: should return 0 for equal exponents to satisfy strict weak ordering requirement of qsort.
} 

int main(){
    int i;
    scanf("%d%d",&a[0].num,&a[0].exp ); // @@ Error: reading first term outside the loop may cause issues for polynomials with only one term; the newline after this will not be consumed before the loop tries to read the next term.
    for(i=1;;i++){
        scanf("%d%d",&a[i].num,&a[i].exp); // @@ Error: if the first polynomial has only one term, this scanf will attempt to read from an empty input stream, likely resulting in undefined behavior.
        if(getchar()=='\n')
        break;
    }
    int m=0;
    for(int j=0;;j++){
        scanf("%d%d",&b[j].num,&b[j].exp);
        for(int k=0;k<=i;k++,m++){ // @@ Error: using 'i' which may be incorrect if the first polynomial reading was flawed; also, 'i' is the index of the last term, but the number of terms is i+1.
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ Error: index out of bounds; should be k < m (m is the count, indices 0..m-1).
        for(int xk=0;xk<=sum;xk++){ // @@ Error: index out of bounds; should be xk < sum.
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp); // @@ Error: cmp function does not return 0 for equal exponents, causing undefined behavior in qsort.
    for(int s=0;s<sum;s++){
        printf("%d %d ",c[s].num,c[s].exp); // @@ Error: does not check if coefficient is zero; should only print non-zero terms.
    }
    return 0;
    
}