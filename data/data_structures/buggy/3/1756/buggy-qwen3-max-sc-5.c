#include<stdio.h>
#include<string.h>
char a[1005];
int main()
{
    int sum,flag=0,b,c,d;
    gets(a); @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    for(int i=0;i<strlen(a);i++)
    {    
        if(flag==0&&a[i]!='0'&&a[i]!='.')
        {
            flag=1;
            b=i;
        }
        if(a[i]=='.')
        {
            c=i;
        }
    }
//    i=strlen(a)
//    while(i>0&&a[i]==0)
//    {
//        
//    }
    for(int i=strlen(a)-1;i>c;i--)
    {
        if(a[i]!='0'&&a[i]!='.')
        {
            d=i;
            break;
        }
    }
    //printf("%d",d);
    if(flag==1)
    {
        for(int i=b;i<=b+d;i++) @@ [Incorrect loop bound: should not go to b+d; this causes out-of-bounds access and wrong digit extraction]
        {
            if(i==b+1&&i!=strlen(a))
            printf(".");
            //printf("$");
            if(a[i]!='.')
            printf("%c",a[i]);
        }
        int p;
        if(a[0]=='0')
        p=c-b; @@ [Incorrect exponent calculation for numbers < 1; should be (c - b - 1) with negative sign handled properly]
        else
        p=c-b-1; @@ [Exponent logic flawed; does not correctly compute scientific notation exponent in all cases]
        if(p>=0)
        printf("e%d\n",p);
        else
        {
            p=-p;
            printf("e-%d\n",p);
        }
        
    }
    else
    printf("0e0\n"); @@ [Does not match problem constraints: input always has significant digits before and after decimal, so "0e0" case shouldn't occur, but more critically, program logic fails on valid inputs]
}