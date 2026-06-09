#include<stdio.h>
int mark[12],a[12];
void f(int,int);
int main()
{
    int n;
    scanf("%d",&n);
    f(0,n);
    return 0;
}
void f(int step,int m)
{
    int j;
    if(step==m){
        for(int i=0;i<m;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(j=0;j<m;j++){
        if(0==mark[j]){
            mark[j]=1;
            a[step]=j+1;
            f(step+1,m);
            mark[j]=0;
        }
    }
}

