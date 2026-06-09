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
    for(int j=0;;j++){ // @@ [Compilation error in strict C89/C90: variable declaration inside for loop is not allowed. Also, j is unbounded and may cause array overflow.]
        scanf("%d%d",&b[j].num,&b[j].exp);
        for(int k=0;k<=i;k++,m++){ // @@ [Compilation error in strict C89/C90: variable declaration inside for loop. Logical error: k<=i accesses a[i] out of bounds, valid indices are 0 to i-1, so condition should be k<i.]
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ [Compilation error in strict C89/C90: variable declaration inside for loop. Logical error: k<=m accesses c[m] out of bounds, valid indices are 0 to m-1, so condition should be k<m.]
        for(int xk=0;xk<=sum;xk++){ // @@ [Compilation error in strict C89/C90: variable declaration inside for loop. Logical error: xk<=sum may access out of bounds as sum decreases during iteration.]
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp); // @@ [Logical error: cmp function does not return 0 when exponents are equal, violating qsort's comparator contract and causing undefined behavior.]
    for(int s=0;s<sum;s++){ // @@ [Compilation error in strict C89/C90: variable declaration inside for loop. Logical error: sum is modified during merging, but qsort sorted m elements; printing sum elements may skip valid terms or access invalid indices.]
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}