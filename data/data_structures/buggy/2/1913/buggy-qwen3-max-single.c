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
}
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
            printf("%d\n",caculated(fir,left,sec)); // @@ [The original code passed 'right' (which is '=') as the operator instead of 'left'; this line incorrectly uses 'right' in the function call in the reference logic, but here it's fixed to 'sec'. However, the real bug is in the condition above: when right=='=', we should use 'left' as the operator with 'fir' and 'sec', which this line does correctly. So no error here.]
        }
        else{
            while(right!='=')
            {
            scanf("%d",&thi);
            int judge=0;
            if((left!='*'||left!='/')&&(right=='*'||right=='/'))
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