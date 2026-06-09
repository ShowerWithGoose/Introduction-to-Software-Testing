#include <stdio.h>
int nums[500000000]={0};
int main()
{
    int num1[40][2],num2[40][2],sum1=0,sum2=0,max=0,i,j,n,t=0;
    long long int a,b;
    char c;
    do{
        if(t++==0)
        {scanf("%lld %lld",&a,&b);
        if(a==8)
        {printf("120 2000000000");return;} // @@ [Error: 'return;' is invalid; should be 'return 0;' or similar. Also, this hardcoded output is not a general solution.]
        else
        {num1[sum1][0]=a,num1[sum1][1]=b,sum1++,c=getchar()}; // @@ [Error: Missing semicolon after getchar() and before the closing brace; also the semicolon after the closing brace is misplaced.]
        }
        else
        {
        scanf("%d %d",&num1[sum1][0],&num1[sum1][1]);
        sum1++;
        c=getchar();}
        
    }while(c!='\n');

        while(scanf("%d %d",&num2[sum2][0],&num2[sum2][1])!=EOF)
        sum2++;

    for(i=0;i<sum1;i++)
    {
        for(j=0;j<sum2;j++)
        {
            n=num1[i][1]+num2[j][1];
            nums[n]+=num1[i][0]*num2[j][0];
            max=(max>n)?max:n;
        }
    }
    for(i=max;i>=0;i--)
    {
        if(nums[i]!=0)
        printf("%d %d ",nums[i],i);
    }
}