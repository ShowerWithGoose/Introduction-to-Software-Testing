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

    int num1 = 0,res = 0; // @@ Local variable 'res' shadows the global 'res', which may cause compilation warnings/errors and logical confusion.
    char op = '+';
    
    while(s[j] != '=') // @@ Missing check for string terminator '\0', may cause out-of-bounds access or infinite loop if '=' is missing.
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
            
            for(i = j;i < strlen(s); i ++) // @@ Loop starts at operator index 'j' instead of after it, and does not skip spaces, leading to incorrect number parsing.
            {
                if((s[i] <='9') && (s[i] >= '0'))
                {
                    num2 = num2 * 10 + (s[i] - '0');
                }
                
                if((isdigit(s[i+1])) == 0) // @@ Breaks immediately on spaces or non-digit characters, preventing correct parsing of multi-digit numbers.
                {
                    break;
                }
            }
            
            j = i;    // @@ Incorrectly updates loop index 'j', causing the main loop to re-process the operator or skip necessary characters.
                
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