#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void sort(int l,int r,int a[],int b[],int c[],int d[])
{
    int mid=a[(l+r)/2];
    int i=l,j=r;
    int tmp,tmp1,tmp2,tmp3;
    do
    {
        while(a[i]<mid)
        i++;
        while(a[j]>mid)
        j--;
        if(i<=j)
        {
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            tmp1=b[i];
            b[i]=b[j];
            b[j]=tmp1;
            tmp2=c[i];
            c[i]=c[j];
            c[j]=tmp2;
            tmp3=d[i];
            d[i]=d[j];
            d[j]=tmp3;
            i++;
            j--; // @@ [The original code incorrectly increments j instead of decrementing it, causing incorrect partitioning in the quicksort implementation. This leads to wrong ordering of segments, which affects the chain-building logic later.]
        }
    }
    while(i<=j);
            if(l<j)
            sort(l,j,a,b,c,d);
            if(i<r)
            
                sort(i,r,a,b,c,d);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[105],b[105],a1[105],b1[105];
    int count[105];
    int a2=0,b2=0;
    int max=0;
    int t;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&a1[i],&b1[i]);
        
    }
    sort(0,n-1,a,b,a1,b1);
    for(int i=0;i<n;i++)
    {
        count[i] = 1; // @@ [The count array is not initialized properly. Without initializing count[i] to 1 (each segment starts with length 1), the subsequent increment (count[i]++) leads to undefined behavior due to garbage values. This causes incorrect segment counts like 834 in the output.]
        a2=a1[i];
        b2=b1[i];
        for(int t=i+1;t<n;t++)
        {
            if(a[t]==a2&&b[t]==b2)
            {
                count[i]++;
                a2=a1[t];
                 b2=b1[t];
            }
        }
    }
     t=0;
    for(int i=0;i<n;i++)

{
if(count[i]>max)
{
max=count[i];
t=i;}
    }
    printf("%d %d %d\n",max,a[t],b[t]); // @@ [The output prints 'max' directly, but since count[i] was meant to represent total segments (starting at 1), and if count[i] had been correctly initialized to 1, then no +1 would be needed. However, due to missing initialization, even if fixed, the logic here assumes count[i] already includes the starting segment. But given the earlier missing initialization, this line may still be off. However, the primary error is the uninitialized count array and the sort bug. The '+1' was compensating for uninitialized count[i]=0, but that's incorrect logic. After fixing initialization to 1, we should output max, not max+1. But in current buggy state, both issues compound. Given test expects 2, and with fix of initialization to 1 and correct chaining, max becomes 2, so printing max is correct. Hence, this line should print max, not max+1 — but only after count[i] is initialized to 1. Since the initialization is missing, the '+1' was an attempt to fix it, but it's applied incorrectly because the loop logic also depends on proper initialization. So the real fix is initializing count[i]=1 and printing max. Therefore, this line is wrong as written because it assumes count[i] started at 0, but the correct design requires count[i] to start at 1 and then output max. However, since the initialization is missing, this line contributes to the error. But the dominant errors are the uninitialized count and the sort bug. Given the instructions, we mark lines with direct errors. The missing initialization is the critical one, and this line's '+1' is a consequence. However, strictly speaking, if count[i] were initialized to 1, then max would be 2 and we should print max, not max+1. So this line is also erroneous in its current form. But note: in the current code, count[i] is uninitialized, so it contains garbage. The '+1' doesn't fix it. The main issue is the missing initialization. We'll mark the initialization line as the key error, and this line may be conditionally wrong, but without initialization, it's meaningless. Per problem, we mark lines where error occurs. The most direct errors are: 1) j++ instead of j-- in sort, 2) missing initialization of count[i]. The printf line uses max+1 which would be correct ONLY if count[i] started at 0 and counted additional segments. But the problem says: output number of segments. Each chain starts with 1 segment. So if you find 1 connection, total is 2. The inner loop does count[i]++ for each connected segment beyond the first. So if you start with count[i]=0, then after one connection, count[i]=1, and +1 gives 2 — which is correct. But if you don't initialize, it's garbage. So the intended logic is: count[i] = 0 initially, then for each extension, count[i]++, then output count[i]+1. OR: count[i]=1 initially, then count[i]++ for each extension, then output count[i]. The current code does NOT initialize count[i], so it's garbage. Then it does count[i]++ (so garbage+1), then outputs garbage+1+1. That's why output is 834. So two fixes needed: initialize count[i]=0 or 1 consistently, and adjust output. The reference program initializes to 1 and accumulates. In this code, the inner loop starts from i+1 and checks forward, so it's trying to build chain in sorted order. The correct approach is to initialize count[i] = 1. Then, when you find a next segment, you do count[i]++. Then output count[i]. So the printf should be max, not max+1. But the code currently does not initialize count[i], and prints max+1. So both are wrong. However, the most immediate cause of the garbage value is the missing initialization. We mark that line. The printf line is also logically inconsistent, but the garbage comes from missing init. Per instructions, mark lines with errors. We mark the missing initialization as the critical error. The sort bug also causes incorrect ordering, so chains aren't built properly. Both must be fixed. We mark both.]
    return 0;
}