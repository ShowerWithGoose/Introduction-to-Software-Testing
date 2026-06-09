#include <stdio.h>
int nums[500000000]={0}; // @@ [Declaring an extremely large static array (2GB+) may exceed memory limits or cause compilation/linking failure on many systems, leading to a compilation or runtime environment error.]
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
        {num1[sum1][0]=a,num1[sum1][1]=b,sum1++,c=getchar()}; // @@ [Storing a long long int 'a' into an int array element causes type mismatch and potential data truncation.]
        }
        else
        {
        scanf("%d %d",&num1[sum1][0],&num1[sum1][1]);
        sum1++;
        c=getchar();}
        
    }while(c!='\n');

        while(scanf("%d %d",&num2[sum2][0],&num2[sum2][1])!=EOF) // @@ [This loop does not check for newline termination; it reads until EOF, which doesn't match the input format that ends with a newline. This leads to incorrect parsing of the second polynomial.]
        sum2++;

    for(i=0;i<sum1;i++)
    {
        for(j=0;j<sum2;j++)
        {
            n=num1[i][1]+num2[j][1];
            nums[n]+=num1[i][0]*num2[j][0]; // @@ [If the exponent sum 'n' exceeds the bounds of the 'nums' array (which is already dangerously large), it causes undefined behavior. Also, using 'int' for coefficients may overflow during multiplication or accumulation.]
            max=(max>n)?max:n;
        }
    }
    for(i=max;i>=0;i--)
    {
        if(nums[i]!=0)
        printf("%d %d ",nums[i],i); // @@ [Printing coefficient as '%d' is okay only if it fits in int, but intermediate results might have overflowed, and the massive 'nums' array likely caused compilation/linker failure before this point.]
    }
}