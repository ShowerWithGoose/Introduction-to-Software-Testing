#include <stdio.h>
#include <string.h>
char num[1000];
int main()
{
    int len,k,j;
    gets(num);
    int i;
    len=strlen(num);
    for(i=0;i<len;i++)
    {
        if(num[i]=='.')
        {
          k=i;
          break;
        }        
    }
    if(k==1)
    {
        if(num[0]=='0')
        {
            for(i=2;i<len;i++)
            {
                if(num[i]!='0')
                {
                    j=i;
                    break;
                }
            }
            if(j==len-1)
            {
                printf("%c",num[j]);
                printf("e-%d",j-1);
            }
            else
            {
                printf("%c.",num[j]);
                for(i=j+1;i<len;i++)
                {
                    printf("%c",num[i]);
                }
                printf("e-%d",j-1);
            }
            
        }
        else
        {
            printf("%c.",num[0]);
            for(i=2;i<len;i++)
            {
                printf("%c",num[i]);
            }
            printf("e0");
        }
    }
    else
    {
        printf("%c.",num[0]);
        for(i=1;i<k;i++) // @@ The loop should start from index 1 (the digit immediately after the first digit) to copy all digits between the first digit and the decimal point. Starting from 2 skips the second digit (index 1), causing '7' to be missing in "87899...".
        printf("%c",num[i]);
        for(i=k+1;i<len;i++)
        printf("%c",num[i]);
        printf("e%d",k-1);
        
            }
            return 0;
}