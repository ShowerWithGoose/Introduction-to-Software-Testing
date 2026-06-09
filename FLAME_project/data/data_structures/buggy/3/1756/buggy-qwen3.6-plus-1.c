#include<stdio.h>
#include<string.h>
char a[1005];
int main()
{
    int sum,flag=0,b,c,d;
    gets(a);
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
        for(int i=b;i<=d;i++) // @@ The loop condition `i<=b+d` is incorrect. It should iterate through the significant digits from the first non-zero digit `b` to the last significant digit `d`. Using `b+d` as the upper bound causes the loop to run too many times, potentially accessing out-of-bounds memory or printing extra characters/spaces, leading to the wrong output format (e.g., extra spaces in "9  e-1").
        {
            if(i==b+1&&i!=strlen(a)) // @@ The condition for printing the decimal point is flawed. It assumes the decimal point should always be after the second character of the output sequence (`b+1`), which is only true if there are digits after the first significant digit. However, the logic for placing the decimal point in scientific notation depends on whether there are remaining significant digits after the first one. A simpler approach is to print the first digit, then if there are more significant digits (`b < d`), print a dot and the rest. The current check `i!=strlen(a)` is also risky if `b+1` equals `strlen(a)`.
            printf(".");
            //printf("$");
            if(a[i]!='.')
            printf("%c",a[i]);
        }
        int p;
        if(a[0]=='0')
        p=c-b; // @@ For numbers like 0.9, `a[0]` is '0', `c` is 1 (index of '.'), `b` is 2 (index of '9'). `p = 1 - 2 = -1`. This calculates the exponent correctly for numbers less than 1.
        else
        p=c-b-1;
        if(p>=0)
        printf("e%d\n",p);
        else
        {
            p=-p;
            printf("e-%d\n",p);
        }
        
    }
    else
    printf("0e0\n");
}