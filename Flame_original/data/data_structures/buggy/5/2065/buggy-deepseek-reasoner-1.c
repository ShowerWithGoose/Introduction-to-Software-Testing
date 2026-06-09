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
    for(i=1;;i++){ // @@ [Error: reading first term outside loop leaves newline in buffer; for single‑term polynomial scanf will hang waiting for next integer. Should read all terms inside loop with newline check after each read.]
        scanf("%d%d",&a[i].num,&a[i].exp);
        if(getchar()=='\n')
        break;
    }
    int m=0;
    for(int j=0;;j++){ // @@ [Error: inner loop uses i which may be incorrect if first polynomial has only one term due to the reading bug above.]
        scanf("%d%d",&b[j].num,&b[j].exp);
        for(int k=0;k<=i;k++,m++){
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ [Error: off‑by‑one; should be k < m. Accessing c[m] is beyond valid product terms and leads to undefined behavior.]
        for(int xk=0;xk<=sum;xk++){ // @@ [Error: off‑by‑one (should be xk < sum) and modifying sum inside the loop is unsafe; may skip higher valid indices in later iterations.]
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    // Missing: sort c[] by exponent descending using qsort()
    for(int s=0;s<sum;s++){ // @@ [Error: printing uses sum which may not cover all valid terms (valid indices can be > sum-1 after combination). Also does not skip terms with exponent -1, and no check for zero coefficient. The output is not sorted.]
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}