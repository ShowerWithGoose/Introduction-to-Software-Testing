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
    for(i=1;;i++){ // @@ This loop incorrectly reads the next polynomial's data because it starts without checking if the first polynomial has more terms.
        scanf("%d%d",&a[i].num,&a[i].exp); // @@ This line reads the next polynomial's first term when the first polynomial has only one term.
        if(getchar()=='\n')
        break;
    }
    int m=0;
    for(int j=0;;j++){ // @@ This loop may run infinitely because the input stream is already exhausted.
        scanf("%d%d",&b[j].num,&b[j].exp); // @@ This scanf will fail if no input remains, leaving b[j] uninitialized.
        for(int k=0;k<=i;k++,m++){ // @@ Uses incorrect 'i' (includes garbage term from the second polynomial) leading to out-of-range access or extra products.
            c[m].num =a[k].num*b[j].num ;
            c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n') // @@ This getchar may return EOF, not '\n', causing the loop to continue indefinitely.
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){
        for(int xk=0;xk<=sum;xk++){
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp);
    for(int s=0;s<sum;s++){
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}