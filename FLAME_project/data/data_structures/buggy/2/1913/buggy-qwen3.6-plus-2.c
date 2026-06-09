#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
char readch()
{
    char b;
    do{
        scanf("%c",&b);
    }
    while(b==' ');
    return b;
}
int caculated(int x,char b,int y)
{
    if(b=='+'){
        return x+y;
    }
    else if(b=='-'){
        return x-y;
    }
    else if(b=='*'){
        return x*y;
    }
    else if(b=='/'){
        return x/y;
    }
} // @@ The function `caculated` does not return a value if `b` is not one of '+', '-', '*', or '/'. Although the problem states the input is valid, missing a return statement for the default case leads to undefined behavior. More critically, in the main logic below, this function is called with incorrect arguments or in states where variables are uninitialized or hold wrong values due to logic errors.

int main()
{
    int fir,sec,thi;
    char left,right;
    scanf("%d",&fir);
    left=readch();
    if(left=='=')
    {
        printf("%d\n",fir);
    }
    else{
        scanf("%d",&sec);
        right=readch();
        if(right=='='){
            printf("%d\n",caculated(fir,left,right)); // @@ Error: The third argument passed to `caculated` is `right` (a char operator), but it should be `sec` (the second integer operand). It calculates `fir left sec`, so it should be `caculated(fir, left, sec)`. Passing `right` (e.g., '=') as an integer operand causes incorrect calculation or undefined behavior.
        }
        else{
            while(right!='=')
            {
            scanf("%d",&thi);
            int judge=0;
            if((left!='*'||left!='/')&&(right=='*'||right=='/')) // @@ Logic Error: The condition `left!='*'||left!='/'` is always true because `left` cannot be both '*' and '/' simultaneously. This means `judge` is set to 1 whenever `right` is '*' or '/', regardless of `left`. The correct logic to check if `left` has lower precedence than `right` (i.e., `left` is + or - and `right` is * or /) should be `(left=='+' || left=='-') && (right=='*' || right=='/')`. The current logic fails to correctly handle operator precedence, leading to incorrect order of operations.
            {
                judge=1;
            }
            if(judge==0)
            {
                fir=caculated(fir,left,sec);
                sec=thi;
                left=right;
            }
            else
            {
                sec=caculated(sec,right,thi);
            }
            right=readch();
        }
    }
        printf("%d\n",caculated(fir,left,sec));
    }
}