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
            if(k!=strlen(a)-1)
            {
                printf(".");
            }
            for(i=0;i<strlen(b);i++)
            {
                printf("%c",b[i]);
            }
            printf("e");
            printf("%d",-(k-1)); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", k=9 (index of '9'), but the exponent should be -8 (since the first non-zero digit is at position 9 from the decimal point, so exponent = -(k-2) = -7? Actually, the correct exponent is -8 because the number is 9.123456789012e-8). The formula should be -(k-2) to account for the decimal point at index 1.
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