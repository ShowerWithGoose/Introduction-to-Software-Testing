#include<stdio.h>
void digui(int a[],int b[],int n,int ceng){
    int i;
    if(ceng==n+1){
        for(i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
        }
    if(ceng!=n+1){
            for(i=1;i<=n;i++){
        if(b[i]==0){
        b[i]=1;
        a[ceng]=i;
        digui(a,b,n,ceng+1);
        b[i]=0;
   } }}

}
int main()
{
    int a[11]={0},b[11]={0};
    int n,ceng=1;
    scanf("%d",&n);
    digui(a,b,n,ceng);

}

