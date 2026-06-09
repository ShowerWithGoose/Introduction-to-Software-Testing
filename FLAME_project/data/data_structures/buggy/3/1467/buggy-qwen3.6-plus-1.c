#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [The function 'gets' is deprecated and removed in C11; use 'fgets' instead. Also, this line causes a compilation warning/error in strict environments.]
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ [Compilation Error: The conditional operator (?:) returns an rvalue, which cannot be used as the left operand of an assignment or as a standalone statement in this context. It should be replaced with an if-else statement.]
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