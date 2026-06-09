#include<stdio.h>
#include<stdbool.h>
void printall(int n)
{
    int *num=(int*)malloc(n*sizeof(int)); // @@ Missing #include <stdlib.h> for malloc; causes implicit declaration error.
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
    while(bigger(num,n)==1) // @@ 'bigger' used before declaration; implicit function declaration not allowed in C99.
    {
        changebigger(num,n); // @@ 'changebigger' used before declaration; implicit function declaration not allowed in C99.
        for(i=0;i<n-1;i++)
        {
            printf("%d ",num[i]);
        }
        printf("%d\n",num[n-1]);
    }
    free(num); // @@ Missing #include <stdlib.h> for free; implicit declaration error.
}
int bigger(int *num,int n)
{
    int i=0;
    for(i=n-1;i>=0;i--) // @@ Loop includes i=0, but inside accesses num[i-1] which is out-of-bounds when i=0.
    {
        if(num[i]>num[i-1]) return 1; // @@ Accesses num[-1] when i=0; out-of-bounds access (undefined behavior).
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