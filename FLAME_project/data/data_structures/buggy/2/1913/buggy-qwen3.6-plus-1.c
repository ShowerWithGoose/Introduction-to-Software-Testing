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
} // @@ [Missing return statement for invalid operator or default case, leading to undefined behavior if an unexpected character is passed, though likely not the primary crash cause here. More critically, the logic error below causes the crash.]
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
            printf("%d\n",caculated(fir,left,right)); // @@ [Logical Error: The third argument to caculated should be 'sec' (the second operand), not 'right' (the operator character). Passing the ASCII value of the operator as an integer operand yields incorrect results, and if 'right' was '=', it might have been caught earlier, but here it calculates fir op '=' which is wrong. However, the runtime error is likely due to the loop logic below.]
        }
        else{
            while(right!='=')
            {
            scanf("%d",&thi);
            int judge=0;
            if((left!='*'||left!='/')&&(right=='*'||right=='/')) // @@ [Logical Error: The condition `left!='*'||left!='/'` is always true because `left` cannot be both '*' and '/' simultaneously. This means `judge` is set to 1 whenever `right` is '*' or '/', regardless of `left`. This breaks the precedence logic. It should be `left!='*' && left!='/'` (or equivalently `(left=='+' || left=='-')`).]
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