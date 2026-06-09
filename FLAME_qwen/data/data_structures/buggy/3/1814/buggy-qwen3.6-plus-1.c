#include<stdio.h>
#include<string.h>
int main()
{
    char num[108],ans[108];
    gets(num); // @@ gets() is removed in the C11 standard and causes a compilation error in modern compilers; use fgets() or scanf() instead.
    int k;
    int i;
    int len=strlen(num);
    for(i=0;i<len;i++)
    {
        if(num[i]=='.')
        {
            k=i;
            break;
        }

    }
    int m,n;
    if(k==1)
    {
        if(num[0]=='0'){

        for(i=2;i<len;i++)
        {
            if(num[i]!='0')
            {
                m=i;
                break;
            }
        }
        ans[0]=num[m];
        if(m!=(len-1))
        {      ans[1]='.';
            for(i=m+1,n=2;i<len;i++,n++)
            {
                ans[n]=num[i];
            }
        }
        else
        {n=1;
        }
        for(int j=0;j<n;j++)
        {
            printf("%c",ans[j]);
        }
        printf("e-%d",m-1);

    }
    else
    {
        for(int i=0;i<len;i++){
            printf("%c",num[i]);}
            printf("e0");

    }
}
else
{
    ans[0]=num[0];
    ans[1]='.';
    for(  i=1,m=2;i<len;i++)
    {
        if(num[i]!='.')
        {
            ans[m]=num[i];
            m++;
        }
    }
    for(int i=0;i<len-1;i++) // @@ Logical error: the loop condition i<len-1 fails to print the last digit of the mantissa; it should be i<m or i<len to include all significant digits.
    {
        printf("%c",ans[i]);


}
printf("e%d",k-1);

}
return 0;        }