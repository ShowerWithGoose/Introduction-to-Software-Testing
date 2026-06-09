#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ Type mismatch: &a[0] is int*, but %c expects char*. This causes a compilation error.
    a[0]=a[0]-'0';
    while((c=getchar())!='=')
    {
        if(c==' ')
        {
            continue;
        }
        else
        {
            if(c>='0'&&c<='9')
            {
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/')
                {
                    a[k-1]=a[k-1]*10+c-'0';
                }
                else
                {
                    a[k]=c-'0';
                    k++;
                }
            }
            else
            {
                a[k]=c; // @@ Storing char operators in an int array mixes data types, which can cause logical errors if a number's value matches an operator's ASCII code.
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--; // @@ j is initialized to 0, so j-- makes it -1, causing an out-of-bounds array access at b[-1].
            b[j]=b[j]*a[i+1];
            i++;
        }
        else if(a[i]=='/')
        {
            j--; // @@ Same error: decrementing j from 0 results in -1, leading to invalid memory access.
            b[j]=b[j]/a[i+1];
            i++;
        }
        else
        {
            b[j]=a[i]; // @@ Logic error: this mixes operators and numbers in array b, breaking the subsequent evaluation logic.
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++)
    {
        if(b[i]=='+')
        {
            r+=b[i+1];
        }
        else if(b[i]=='-')
        {
            r-=b[i+1];
        }
        else
        {
            continue;
        }
    }
    printf("%d\n",r);
    return 0;
}