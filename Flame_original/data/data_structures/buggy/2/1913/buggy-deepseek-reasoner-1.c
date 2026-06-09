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
            printf("%d\n",caculated(fir,left,right)); // @@ [Error: third argument should be 'sec', not 'right'; 'right' is a character operator, not an integer operand]
        }
        else{
            while(right!='=')
            {
            scanf("%d",&thi);
            int judge=0;
            if((left!='*'||left!='/')&&(right=='*'||right=='/')) // @@ [Error: logical condition always true; should check if left is '+' or '-', not simply not '*']
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