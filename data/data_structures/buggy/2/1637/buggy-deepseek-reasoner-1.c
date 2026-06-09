#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ Potential error: if first character is a space, a[0] becomes space-'0' (negative), causing issues later.
    a[0]=a[0]-'0'; // @@ Assumes first character is a digit; if it is not, produces incorrect value.
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
                a[k]=c;
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--; // @@ Error: j decremented from 0 to -1, causing out‑of‑bounds access.
            b[j]=b[j]*a[i+1]; // @@ Error: b[-1] is undefined; also b[j] is 0, resulting in incorrect product.
            i++;
        }
        else if(a[i]=='/')
        {
            j--; // @@ Same out‑of‑bounds error as above.
            b[j]=b[j]/a[i+1]; // @@ Same undefined behavior.
            i++;
        }
        else
        {
            b[j]=a[i];
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++)
    {
        if(b[i]=='+') // @@ Logical error: b contains only numbers, never '+'/'-', so this condition never true.
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