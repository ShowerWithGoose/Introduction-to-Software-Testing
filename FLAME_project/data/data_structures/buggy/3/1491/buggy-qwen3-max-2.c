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
                printf("."); // @@ [This prints a dot before the digits, but scientific notation requires one non-zero digit before the decimal point. The correct format should be "9.123..." not ".9123...".]
            }
            for(i=0;i<strlen(b);i++)
            {
                printf("%c",b[i]);
            }
            printf("e");
            printf("%d",-(k-1)); // @@ [The exponent calculation is off by one. For input "0.00000009123...", the first non-zero digit '9' is at index 9 (0-based), so exponent should be -(9 - 1) = -8, but due to incorrect base formatting, the logic fails to align with standard scientific notation rules. However, the main issue is the missing leading digit before the decimal point.]
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