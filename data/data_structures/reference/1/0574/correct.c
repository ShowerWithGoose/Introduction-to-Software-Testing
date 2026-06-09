#include<stdio.h>
#include<math.h>
#include<string.h>
int a[300];
void dz(int m,int n)
{
    int i,j,hold;
    for(i=m,j=n;i<=j;i++,j--){
        hold=a[i];
        a[i]=a[j];
        a[j]=hold;
    }
    return 0;
}
long long jc(int n)
{
    if(n==0||n==1){
        return 1;
    }
    else {
        return (n*jc(n-1));
    }
}
int main()
{
    int n,i,jld[6],hold,delta,min=10086;
    long long cs;
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        a[i]=i;
    }
    for(i=1;i<=n;i++){
        printf("%d ",i);
    }
    printf("\n");
    for(cs=jc(n)-1;cs>=1;cs--){
        for(i=n;;i--){
            if(i-1==0){
                jld[1]=0;
                break;
            }
            else if(a[i-1]<a[i]){
                jld[1]=i-1;
                break;
            }
        }
        for(i=jld[1]+1;i<=n;i++){
            delta=a[i]-a[jld[1]];
            if(delta<=min&&delta>0){
                jld[2]=i;
                min=delta;
            }
        }
        min=10086;
        hold=a[jld[1]];
        a[jld[1]]=a[jld[2]];
        a[jld[2]]=hold;
        dz(jld[1]+1,n);
        for(i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}



