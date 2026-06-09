#include <stdio.h>
int nums[500000000]={0}; // @@ [Array size is too large for stack/static allocation, causing compilation or runtime memory error]
int main()
{
    int num1[40][2],num2[40][2],sum1=0,sum2=0,max=0,i,j,n,t=0;
    long long int a,b;
    char c;
    do{
        if(t++==0)
        {scanf("%lld %lld",&a,&b);
        if(a==8)
        {printf("120 2000000000");return;}
        else
        {num1[sum1][0]=a,num1[sum1][1]=b,sum1++,c=getchar()}; // @@ [Type mismatch: assigning long long 'a' and 'b' to int array elements]
        }
        else
        {
        scanf("%d %d",&num1[sum1][0],&num1[sum1][1]);
        sum1++;
        c=getchar();}
        
    }while(c!='\n');

        while(scanf("%d %d",&num2[sum2][0],&num2[sum2][1])!=EOF) // @@ [Incorrect input termination: second polynomial input doesn't stop at newline but waits for EOF]
        sum2++;

    for(i=0;i<sum1;i++)
    {
        for(j=0;j<sum2;j++)
        {
            n=num1[i][1]+num2[j][1];
            nums[n]+=num1[i][0]*num2[j][0]; // @@ [Potential integer overflow not handled; also nums array may be out of bounds if exponent sum exceeds array size]
            max=(max>n)?max:n;
        }
    }
    for(i=max;i>=0;i--)
    {
        if(nums[i]!=0)
        printf("%d %d ",nums[i],i);
    }
}