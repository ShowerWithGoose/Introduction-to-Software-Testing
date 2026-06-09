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
        printf("%c",num[i]);
        for(i=k+1;i<len;i++)
        printf("%c",num[i]);
        printf("e%d",k-1); // @@ Error: The exponent should be k-1 only when the integer part has more than one digit. For numbers like 87899.999..., the integer part length is k (since k is the index of the decimal point), so the exponent should be k, not k-1. For example, input "87899.9999999999000999" has k=5, so exponent should be 4, but the code outputs e4 which is correct in this case; however, the buggy output shows "8.78999999999999000999e4" which is missing the digit '9' after the decimal point. The actual error is that the code incorrectly copies digits from the integer part: it starts from i=2 (skipping num[1]) and copies up to k-1, but it should include all digits from index 1 to k-1. The line for(i=2;i<k;i++) should be for(i=1;i<k;i++) to include the second digit of the integer part.
        
            }
            return 0;
}