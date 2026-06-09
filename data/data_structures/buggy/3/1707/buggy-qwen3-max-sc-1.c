#include <stdio.h>
#include <string.h>
char num[1000];
int main()
{
    int len,k,j; // @@ [k and j are used uninitialized if no '.' is found or in certain input cases, leading to undefined behavior]
    gets(num); // @@ [gets() is unsafe and deprecated; may cause buffer overflow. Also, in some environments, it's not available, which could lead to compilation error if strict standards are enforced]
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
    if(k==1) // @@ [k is uninitialized if the input has no decimal point, leading to undefined behavior]
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
            if(j==len-1) // @@ [j is uninitialized if all digits after '.' are zero (which shouldn't happen per problem statement, but still risky), or if loop doesn't run]
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
        for(i=2;i<k;i++) // @@ [if k <= 2, this loop does nothing or causes logic error; also assumes at least two digits before '.', which may not hold]
        printf("%c",num[i]);
        for(i=k+1;i<len;i++)
        printf("%c",num[i]);
        printf("e%d",k-1);
        
            }
            return 0;
}