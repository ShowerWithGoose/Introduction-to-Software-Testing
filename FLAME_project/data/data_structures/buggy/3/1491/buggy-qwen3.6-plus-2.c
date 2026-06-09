#include<stdio.h>
#include<string.h>
char a[100005],b[100005];
int main()
{
    gets(a);
    int i=0,j=0,k=0;
    int p;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='.')
        {
            p=i;
            break;
        }
    }
    if(p==1)
    {
        if(a[0]!='0')
        {
            for(i=0;i<strlen(a);i++)
            {
                printf("%c",a[i]);
            }
                printf("e0");
        }
        else
        {
            for(i=2;i<strlen(a);i++)
            {
                if(a[i]!='0')
                {
                    k=i;
                    break;
                }
            }
            for(i=k;i<strlen(a);i++)
            {
                b[j]=a[i];
                j++;
            }
            if(k!=strlen(a)-1) // @@ The condition `k!=strlen(a)-1` checks if there are digits after the first significant digit. However, the output format requires the base to have one digit before the decimal point. If we just print ".", it results in ".912..." instead of "9.12...". The logic for constructing the scientific notation base is flawed here. It should print the first significant digit, then a decimal point, then the rest.
            {
                printf("."); // @@ This prints a leading decimal point if there are subsequent digits, but misses printing the first significant digit before the decimal point. For input 0.0000000912..., k points to '9'. The code prints "." then "912...", resulting in ".912...". It should print "9" then "." then "12...".
            }
            for(i=0;i<strlen(b);i++)
            {
                printf("%c",b[i]);
            }
            printf("e");
            printf("%d",-(k-1));
        }
    
    }
    else
    {
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]!='.')
            {
                b[j]=a[i];
                j++;
            }
            
        }
        printf("%c",b[0]);
        printf(".");
        for(i=1;i<strlen(b);i++)
        {
            printf("%c",b[i]);
        }
        printf("e");
        printf("%d",p-1);
    }
    return 0;
    
}