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
    
    while(s[j] != '=')
    {        
        if((s[j] <='9') && (s[j] >= '0'))
        {
            num1 = num1 * 10 + (s[j] - '0');
            //while((s[j] <='9') && (s[j] >= '0'))
        }
        else if((s[j] == '*') || (s[j] == '/'))
        {
            op = s[j]; // @@ [Error: Overwrites the pending addition/subtraction operator with the multiplication/division operator. This corrupts the state and leads to incorrect precedence handling.]
            int num2 = 0;
            
            for(i = j; i < strlen(s); i ++) // @@ [Error: Should start at j+1 to skip the operator itself. Also, does not skip whitespace, so it fails to read the next number when spaces are present.]
            {
                if((s[i] <='9') && (s[i] >= '0'))
                {
                    num2 = num2 * 10 + (s[i] - '0');
                }
                
                if((isdigit(s[i+1])) == 0) // @@ [Error: Breaks immediately if the next character is not a digit, but a space is not a digit, so it stops before reading any digits. Should skip spaces.]
                {
                    break;
                }
            }
            
            j = i;    
                
            num1 = bo(num1,op,num2);
            
        }
        else if((s[j] == '+') || (s[j] == '-'))
        {
            res = bo(res,op,num1); // @@ [Error: Uses the current op, which may have been set to '*' or '/' from a previous multiplication/division, instead of the correct pending addition/subtraction operator.]
            num1 = 0;
            op = s[j];
        }
        j ++;
    }
    
    res = bo(res,op,num1);
    
    printf("%d",res);

    return 0;
}