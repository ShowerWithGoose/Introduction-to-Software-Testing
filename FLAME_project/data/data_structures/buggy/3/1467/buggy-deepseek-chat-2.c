#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [gets is unsafe and deprecated; should use fgets instead]
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ [error: lvalue required as left operand of assignment; ternary operator result is not an lvalue]
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
                
                printf("e%d",i-1); // @@ [missing output of the base number before 'e']
            }
        }
    }
}