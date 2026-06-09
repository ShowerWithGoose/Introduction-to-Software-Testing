#include <stdio.h>
int b[10],c[10],a[10]={1,2,3,4,5,6,7,8,9,10};
int main()
    {
        int n;
        scanf("%d",&n);
        file(0,n);
        return 0;
    } 
void file(int j,int n)
{
    int k,l;
    if(j==n){
    for(k=0;k<n;k++) printf("%d ",b[k]);
    printf("\n");
    }
    else{
    for(l=0;l<n;l++){
        if(c[l]==0){
            c[l]=1;
            b[j]=a[l];
            file(j+1,n);
            c[l]=0;
            }
        }
    }
}



