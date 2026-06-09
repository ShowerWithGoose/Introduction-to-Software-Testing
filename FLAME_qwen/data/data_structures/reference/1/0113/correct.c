#include<stdio.h>
void qu(int k,int n,int a[]){
    int i;
    if(n==k){
        for(i=0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");
        return;
    }
    else{
        for(i=1;i<=n;i++){
            int j,flag=1;
            for(j=0;j<k;j++){
                if(a[j]==i){
                    flag=0;
                }
            }
            if(flag){
                a[k]=i;
                qu(k+1,n,a);
            }
        }
    }
}
int main()
{
    int i,n;  
    scanf("%d",&n);
    int a[n];
    qu(0,n,a);
    return 0;
}
