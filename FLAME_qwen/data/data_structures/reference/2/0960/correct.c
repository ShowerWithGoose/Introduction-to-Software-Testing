#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
char opt[1005];
int top1,top2;
char s[1005];
long  long stack[1005];
int main()
{
    int i;long temp;
    scanf("%[^=]",&s);                      
    int len = strlen(s);
    for(i = 0; i < len; i++)
    {
        temp = 0;
        if(s[i] == ' ') continue;      
        if( s[i] <='9'&&s[i] >= '0' )		
        {
            while( s[i] <='9'&&s[i] >= '0' ) temp = temp*10 + s[i++] - '0';
            stack[++top1] = temp;			
            i-=1;                         
        }
        else
        {
            char opts = s[i];	
            if( (top1>=2&&top2>=1&&opt[top2] == '*'|| opt[top2] == '/'))    
            {
                if(opt[top2] == '*') temp = stack[top1-1]*stack[top1];  
                else temp = stack[top1-1]/stack[top1];
                top1--;
                top2--;
                stack[top1] = temp;   				
            }
            opt[++top2] = opts;											
        }

    }
    if((top2>=1&&top1>=2 &&opt[top2] == '*' || opt[top2] == '/' ) )        
    {
        if(opt[top2]== '*') temp = stack[top1-1]*stack[top1];
        else temp = stack[top1-1]/stack[top1];
        top1-=1;
        top2-=1;
        stack[top1] = temp;
    }
    temp = stack[1];	
    for(i = 1; i< top1; )
    {
        if(opt[i]== '+') temp = temp + stack[i+1];
        else temp = temp - stack[i+1];i++;
    }
    printf("%lld",temp);
    return 0;
}


