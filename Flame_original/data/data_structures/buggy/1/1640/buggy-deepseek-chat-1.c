#include<stdio.h>
#include<stdbool.h>
void printall(int n)
{
    int *num=(int*)malloc(n*sizeof(int));
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
    free(num);
}
int bigger(int *num,int n)
{
    int i=0;
    for(i=n-1;i>=0;i--)
    {
        if(num[i]>num[i-1]) return 1; // @@ [Error: When i=0, num[i-1] accesses num[-1], which is out-of-bounds and causes undefined behavior. The loop should start from i=n-1 down to i=1 to avoid this.]
    }
    return 0;
}
void changebigger(int *num,int n)
{
    int i,j,tong,mo,tou;
    for(i=n-2;i>=0&&num[i]>num[i+1];i--); // @@ [Error: This loop condition is incorrect for generating next permutation. It should find the first decreasing element from the right, i.e., while num[i] >= num[i+1], not num[i] > num[i+1]. Using > instead of >= may miss cases where equal elements exist (though not in this problem, but logically incorrect).]
    if(i>=0)
    {
        for(j=n-1;num[j]<num[i];j--); // @@ [Error: This loop condition is incorrect. It should find the smallest element greater than num[i] from the right, i.e., while num[j] <= num[i], not num[j] < num[i]. Using < instead of <= may select the wrong element.]
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