#include <stdio.h>
#include <string.h>
#include <ctype.h>

int res = 0;

int bo(int a, char b, int c)
{
    if(b == '+')
    {
        return (a + c);
    }
    else if(b == '-')
    {
        return(a - c);
    }
    else if(b == '*')
    {
        return(a * c);
    }
    else
    {
        if(c != 0)
        {
            return(a/c);
        }    
    }
    
    return 0;
}

int main()
{
    //输入 
    char s[5000];
    int j = 0, i = 0;
    
    fgets(s,sizeof(s),stdin);
    
    //puts(s);
    
    //处理数字 

    int num1 = 0,res = 0;
    char op = '+';
    
    while(s[j] != '=') // @@ [The loop may access beyond the string if '=' is not present, but more critically, it doesn't skip spaces. Input may contain spaces, which breaks digit parsing and operator detection.]
    {        
        if((s[j] <='9') && (s[j] >= '0'))
        {
            num1 = num1 * 10 + (s[j] - '0');
            //while((s[j] <='9') && (s[j] >= '0'))
        }
        else if((s[j] == '*') || (s[j] == '/'))
        {
            op = s[j];
            int num2 = 0;
            
            for(i = j;i < strlen(s); i ++) // @@ [This loop starts at operator position j, so first character processed is the operator itself, not a digit. Also, it doesn't skip spaces, and assumes next token is contiguous digits, which fails with spaces.]
            {
                if((s[i] <='9') && (s[i] >= '0'))
                {
                    num2 = num2 * 10 + (s[i] - '0');
                }
                
                if((isdigit(s[i+1])) == 0) // @@ [Accesses s[i+1] which may be out-of-bounds when i == strlen(s)-1. Also, isdigit('\0') is false, so it breaks after first digit if no following digit, but logic is flawed for multi-digit numbers after operator.]
                {
                    break;
                }
            }
            
            j = i; // @@ [j is set to i, but then j++ at end of outer loop skips next character, possibly missing operators or digits. Also, doesn't account for spaces.]
                
            num1 = bo(num1,op,num2);
            
        }
        else if((s[j] == '+') || (s[j] == '-'))
        {
            res = bo(res,op,num1);
            num1 = 0;
            op = s[j];
        }
        j ++;
    }
    
    res = bo(res,op,num1);
    
    printf("%d",res);

    return 0;
}