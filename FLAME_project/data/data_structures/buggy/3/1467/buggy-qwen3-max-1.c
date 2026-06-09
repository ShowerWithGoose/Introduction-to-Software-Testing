#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [Use of unsafe and deprecated function 'gets'; also causes implicit declaration warning without including <stdio.h> properly, but more critically, 'gets' was removed in C11 and is not allowed in secure code. However, the primary compilation error comes from the ternary expression below.]
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ [The ternary operator is used incorrectly as an lvalue; assignment cannot be performed this way because the result of the ternary operator is not a modifiable lvalue in this context. This line causes a compilation error: "lvalue required as left operand of assignment".]
                for (int j=i-1;j<strlen(str);j++)
                {
                    printf("%c",str[j]);
                }
                printf("e-%d",i-1);    
                break;        
            }
        }
        if (str[0]!='0')
        {
            if (str[i]=='.')
            {
                
                printf("e%d",i-1);
            }
        }
    }
}