//找规律、模块化分析 
#include <stdio.h>//sum op1 x op2 y op3
int main()
{
    int sum,x,y;
    char op1,op2,op3;
    scanf("%d %c",&sum,&op1); // @@ The format string "%d %c" consumes optional whitespace before reading the character. If the input has spaces after the number (e.g., "24 /"), op1 will correctly read '/'. However, if there are no spaces or multiple spaces, this might behave unexpectedly depending on previous inputs. More critically, the logic for handling the end of expression '=' is flawed in the loop condition and update.
    while(op1!='=')
    {
        scanf("%d %c",&x,&op2); // @@ Similar to above, reading x and the next operator. The space in format string skips whitespace. This reads the next number and the operator following it.
        while(op2=='*'||op2=='/')
        {
            scanf("%d %c",&y,&op3);
            if(op2=='*')
            x=x*y;
            else if(op2=='/')
            x=x/y;
            op2=op3;
        }
        if(op1=='+')
        sum+=x;
        else if(op1=='-')
        sum-=x;
        op1=op2; // @@ This updates op1 to the operator that terminated the inner while loop (either '+', '-', or '='). If op2 was '=', the loop condition while(op1!='=') will terminate correctly. However, there is a subtle issue: if the expression ends with '=', op2 becomes '='. The inner while loop doesn't execute. Then we apply the previous op1 to x. Then op1 becomes '='. The outer loop terminates. This seems logically okay for the structure, BUT look at the first read.
    }
    printf("%d",sum);
    
    
    return 0;
}