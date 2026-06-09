#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ The function 'gets' is deprecated and removed in C11/C++14 standards, causing compilation warnings or errors in strict environments. It should be replaced with 'fgets'.
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ This line causes a compilation error "lvalue required as left operand of assignment" because the conditional operator (ternary operator) returns an rvalue (or requires both operands to be lvalues of compatible types in a specific way that doesn't allow assignment to the result of the expression itself in this context). You cannot assign to the result of a ternary expression like this. It should be split into an if-else statement.
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