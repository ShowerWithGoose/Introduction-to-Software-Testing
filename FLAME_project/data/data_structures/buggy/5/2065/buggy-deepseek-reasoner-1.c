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
    for(i=1;;i++){ // @@ over-read: reads next pair before checking for newline; with single term, reads second polynomial's data.
        scanf("%d%d",&a[i].num,&a[i].exp); // @@ reads extra term incorrectly.
        if(getchar()=='\n') // @@ check occurs after reading, should be before to break properly.
        break;
    }
    int m=0;
    for(int j=0;;j++){
        scanf("%d%d",&b[j].num,&b[j].exp); // @@ attempts to read from empty input due to previous over-read.
        for(int k=0;k<=i;k++,m++){ // @@ uses i which is incorrect due to over-read; also loop bound should check.
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ should be k<m, out-of-bounds.
        for(int xk=0;xk<=sum;xk++){ // @@ should be xk<sum, out-of-bounds.
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp); // @@ should sort only sum elements, not m.
    for(int s=0;s<sum;s++){
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}