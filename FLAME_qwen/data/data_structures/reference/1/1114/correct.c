#include<stdio.h>
int main(){
    int i,n,a[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800},j,k,m,jj;
    scanf("%d",&n);
    for(i=0;i<a[n];i++){
        j=n;k=i;
        int b[11]={};
        while(j--){
            jj=k/a[j];
            k-=jj*a[j];
            jj++;
            for(m=1;m<=n&&jj;m++)if(!b[m])jj--;
            m--;
            b[m]|=1;
            printf("%d ",m);
        }
        putchar('\n');
    }
    return 0;
}
