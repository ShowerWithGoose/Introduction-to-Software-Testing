#include<stdio.h>
#include<stdbool.h>
void printall(int n)
{
    int *num=(int*)malloc(n*sizeof(int)); // @@ [missing #include <stdlib.h> for malloc]
    int i=0;
    for(i=0;i<n;i++)
    {
        num[i]=i+1;
    }
    for(i=0;i<n-1;i++)
    {
        printf("%d ",num[i]);
    }
    printf("%d\n",num[n-1]);
    while(bigger(num,n)==1)
    {
        changebigger(num,n);
        for(i=0;i<n-1;i++)
        {
            printf("%d ",num[i]);
        }
        printf("%d\n",num[n-1]);
    }
    free(num); // @@ [missing #include <stdlib.h> for free]
}
int bigger(int *num,int n)
{
    int i=0;
    for(i=n-1;i>=0;i--)
    {
        if(num[i]>num[i-1]) return 1; // @@ [accesses num[-1] when i=0, causing undefined behavior]
    }
    return 0;
}
void changebigger(int *num,int n)
{
    int i,j,tong,mo,tou;
    for(i=n-2;i>=0&&num[i]>num[i+1];i--);
    if(i>=0)
    {
        for(j=n-1;num[j]<num[i];j--);
        tong=num[i];
        num[i]=num[j];
        num[j]=tong;
    }
    for(mo=n-1,tou=i+1;mo>tou;mo--,tou++)
    {
        tong=num[tou];
        num[tou]=num[mo];
        num[mo]=tong;
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    printall(n);
    return 0;
}