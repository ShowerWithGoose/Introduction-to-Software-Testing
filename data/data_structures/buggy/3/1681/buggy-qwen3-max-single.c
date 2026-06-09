#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    scanf("%s",a);
    int l=0,i,m=0,n=0,k=0;
    l=strlen(a);
    if(a[0]=='0'&&a[1]=='.')
    {
        for(i=2;i<l;i++)
        {
            if(a[i]!='0')
            {
            m=i;
            k=m;
            break;    
            }
        }
        if(m==l-1)
        {
            printf("%ce-%d",a[l-1],l-2);
            
        }
        else
        {
            printf("%c.",a[m]);
        for(m++;m<l;m++)
        {
            printf("%c",a[m]);
        }
        printf("e-%d",l-k); @@ [The exponent calculation is incorrect. It should be (k - 1), not (l - k). For example, input "0.00123" should yield e-3, but this computes e-(5-3)=e-2.]
        }  
    }
    else if(a[0]<='9'&&a[0]>='1'&&a[1]=='.')
    {
        printf("%s",a);
        printf("e0");
    }
    else if(a[0]<='9'&&a[0]>='1'&&a[1]!='.')
    {
        for(i=0;i<l;i++)
        {
            if(a[i]=='.')
            {
                n=i;
                break;
            }
        }
        printf("%c.",a[0]);
        for(i=1;i<n;i++)
        {
            printf("%c",a[i]);
        }
            for(i=n+1;i<l;i++)
        {
            printf("%c",a[i]);
        }
        printf("e%d",n-1);
    }
    return 0;
}