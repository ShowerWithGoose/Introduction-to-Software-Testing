#include <stdio.h>
#include <string.h>
char num[1000];
int main()
{
    int len,k,j; // @@ [Variable 'k' is used uninitialized if input has no decimal point, leading to undefined behavior]
    gets(num); // @@ [Use of unsafe function 'gets' which may cause buffer overflow; also, 'gets' is deprecated and removed in C11]
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
    if(k==1) // @@ [If input has no '.', 'k' remains uninitialized, causing unpredictable condition evaluation]
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
            if(j==len-1) // @@ [Variable 'j' may be used uninitialized if all digits after '.' are zero (though problem states no trailing zeros, but still risky)]
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
        for(i=2;i<k;i++) // @@ [Assumes at least two digits before decimal; fails if input like "123.45" where k>2 but loop starts at i=2 skipping digit at index 1]
        printf("%c",num[i]);
        for(i=k+1;i<len;i++)
        printf("%c",num[i]);
        printf("e%d",k-1);
        
            }
            return 0;
}