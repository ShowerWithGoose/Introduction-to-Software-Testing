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
        for(i=2;i<k;i++) // @@ [Error: The loop should start from i=1 to include the second digit before the decimal point, otherwise it is skipped in the output]
        printf("%c",num[i]);
        for(i=k+1;i<len;i++)
        printf("%c",num[i]);
        printf("e%d",k-1);
        
            }
            return 0;
}