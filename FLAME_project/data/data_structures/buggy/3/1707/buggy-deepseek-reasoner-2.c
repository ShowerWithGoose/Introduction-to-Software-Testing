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
        for(i=2;i<k;i++)
        printf("%c",num[i]); // @@ This loop starts from i=2, skipping the digit at index 1, causing the missing '7' in the output (e.g., yields "8.899..." instead of "8.789..."). Should be i=1.
        for(i=k+1;i<len;i++)
        printf("%c",num[i]);
        printf("e%d",k-1);
        
            }
            return 0;
}