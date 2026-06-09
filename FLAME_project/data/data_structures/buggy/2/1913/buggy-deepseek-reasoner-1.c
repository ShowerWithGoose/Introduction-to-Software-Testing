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
            printf("%d\n",caculated(fir,left,right)); // @@ Error: third argument should be 'sec' (an integer), not 'right' (a character). This causes undefined behavior or incorrect computation.
        }
        else{
            while(right!='=')
            {
            scanf("%d",&thi);
            int judge=0;
            if((left!='*'||left!='/')&&(right=='*'||right=='/')) // @@ Error: logical condition is always true. Intended condition should be ((left=='+'||left=='-') && (right=='*'||right=='/')). This causes incorrect operator precedence handling, leading to wrong results and eventually division by zero.
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