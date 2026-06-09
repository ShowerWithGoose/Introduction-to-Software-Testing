#include<stdio.h>
int a[10]={0};
void ssy(int a[],int n,int m){
    int i,j,num;
    if(m==n){
        for(i=0;i<n;i++){
            printf("%d",a[i]); // @@ [Missing space after each number; should be "%d " to match expected output format with spaces.]
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