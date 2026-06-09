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
            op = s[j];
            int num2 = 0;
            
            for(i = j;i < strlen(s); i ++)
            {
                if((s[i] <='9') && (s[i] >= '0'))
                {
                    num2 = num2 * 10 + (s[i] - '0');
                }
                
                if((isdigit(s[i+1])) == 0)
                {
                    break;
                }
            }
            
            j = i;    
                
            num1 = bo(num1,op,num2); // @@ [Error: When encountering '*' or '/', the code immediately computes num1 = bo(num1, op, num2) without considering operator precedence. For example, in "10 + 20 * 30", when '*' is encountered, num1 is 20 (the number after '+'), and it computes 20 * 30 = 600, but this ignores that '+' has lower precedence and should be applied later. The correct approach is to handle '*' and '/' immediately only if the previous operator is also '*' or '/', otherwise defer the computation.]
            
        }
        else if((s[j] == '+') || (s[j] == '-'))
        {
            res = bo(res,op,num1); // @@ [Error: When encountering '+' or '-', the code adds the current num1 to res using the previous operator op. However, this does not correctly handle cases where there are multiple '*' or '/' operations before a '+' or '-', because num1 may have been incorrectly computed due to the previous error. Additionally, the logic for updating res and num1 is flawed for expressions with multiple operators of different precedence.]
            num1 = 0;
            op = s[j];
        }
        j ++;
    }
    
    res = bo(res,op,num1);
    
    printf("%d",res);

    return 0;
}