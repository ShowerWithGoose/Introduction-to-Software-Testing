#include<stdio.h>
int a[10]={0};
void ssy(int a[],int n,int m){
    int i,j,num;
    if(m==n){
        for(i=0;i<n;i++){
            printf("%d",a[i]); // @@ The output format is incorrect. Integers should be separated by a space, e.g., printf("%d ", a[i]); or handle spacing carefully. Also, the expected output for N=2 is "1 2 \n" (with a trailing space based on reference usually, or just space separated). The current code prints "12".
        }
        printf("\n");
        return ;
    }
    else{
        for(num=1;num<=n;num++){
            for(j=0;j<m;j++)
                if(a[j]==num){
                    break;
                }
                if(j==m){
                    a[m]=num;
                    ssy(a,n,m+1);
                }
        }return ;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    ssy(a,n,0);
    return 0;
}