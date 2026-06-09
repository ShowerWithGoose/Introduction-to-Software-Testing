#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    scanf("%s",&s); // @@ Using &s is incorrect; s is already a pointer to char array, should be scanf("%s", s);
    int i,j;
    if(s[1]=='.')
    {
        if(s[0]!='0')
        {
            for(i=0;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
            printf("e0");    
        }
        else
        {
            for(i=2;i<strlen(s);i++)
            {
                if((s[i]!='0')&&(i!=strlen(s)-1))
                {
                    printf("%c.",s[i]); // @@ This prints only one digit before decimal but skips handling multiple digits correctly in some edge cases
                    for(j=i+1;j<strlen(s);j++)
                    {
                        printf("%c",s[j]);
                    }
                    printf("e%d",i-1); // @@ Exponent should be negative when original number starts with 0., e.g., 0.00123 -> 1.23e-3, not e2
                    break;
                }
                else if(i==strlen(s)-1)
                {
                    printf("%ce-%d",s[i],i-1);
                }
            }
        }
    }
    else
    {
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='.')
            {
                printf("%c.",s[0]);
                for(j=1;j<=i-1;j++)
                {
                    printf("%c",s[j]);
                }
                for(j=i+1;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e%d",i-1); // @@ For numbers like "123.45", exponent should be 2 (since 1.2345e2), but i-1 gives correct value only if i is position of '.', which it is — so this may actually be correct. However, logic fails if there's no '.' handled elsewhere.
                break;
            }
        }
    }
    return 0;
}