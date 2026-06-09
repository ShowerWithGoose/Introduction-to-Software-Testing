#include<stdio.h>
#include<string.h>
int a[11]={0,1,2,3,4,5,6,7,8,9,10};
int N;
void put()
{
    for(int k=1;k<=N;k++)
            printf("%d ",a[k]);
        printf("\n");
}
void ex(int x)
{
    if(x==2){
        put();
        a[N]^=a[N-1],a[N-1]^=a[N],a[N]^=a[N-1];
        put();
        a[N]^=a[N-1],a[N-1]^=a[N],a[N]^=a[N-1];
        return;
    }
    for(int i=1;i<=x;i++){
        swap(N-x+i,N-x+1);
        ex(x-1);
        swap(N-x+1,N-x+i);
    }
    return;
}
void swap(int x,int y)
{
    if(x==y)return;
    if(x>y)
        for(int i=x-1;i>=y;i--)
            a[i]^=a[i+1],a[i+1]^=a[i],a[i]^=a[i+1];
    else
        for(int i=x;i<=y-1;i++)
            a[i]^=a[i+1],a[i+1]^=a[i],a[i]^=a[i+1];
    return;
}
int main()
{
    scanf("%d",&N);
    if(N==1)
        printf("1");
    else
        ex(N);
    return 0;
}

