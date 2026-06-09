#include<stdio.h>
#include<string.h>
int main()
{
    char c[100];
    gets(c); // @@ [Using `gets()` is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Should use `fgets()` instead.]
    int num=0,flag=0,i=0,judge=0;
    if(strlen(c)==1)
    {
        printf("%c",c[0]);
        printf("e0");
    }
    else
    {
        if(c[0]=='0')
        {
            for(num=1,i=2;c[i]=='0';i++) // @@ [Incorrect initialization: when input starts with "0.", the first digit after '.' is at index 2 only if there's exactly one '0' before '.', but this assumes format "0.00...", which may not hold if input is malformed or has more digits before decimal (though problem says valid input). However, more critically, if the string length is small (e.g., "0.1"), accessing c[2] may be out of bounds if string is short, leading to undefined behavior. Also logic skips the first non-zero digit incorrectly.]
                num++;
            while(c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);    
                i++;
            }
            printf("e-%d",num);
        }
        else
        {
            while(c[i]!='.'&&c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);
                i++;
            }
            if(c[i]=='\0')
            {
                printf("e%d",judge-1);
            }
            else
            {
                printf("."); 
                for(i++;c[i]!='\0';i++)
                {
                    printf("%c",c[i]);
                }
                printf("e%d",judge-1);
            }
        }
    }
        

    return 0;
}