#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
char opt[12315];
int topa,topb;
char s[12315];
long long stack[12315];
int main()
{
    int i;
    long long m;
    scanf("%[^=]",&s);
    int len = strlen(s);
    for(i = 0; i < len; i++)
    {
        m = 0;
        if(s[i] == ' ')
         continue;
        if(s[i] >= '0' && s[i] <='9')
        {
            while(s[i] >= '0' && s[i] <='9') m = m*10 + s[i++] - '0';
            stack[++topa] = m;
            i--;
        }
        else
        {
            char opts = s[i];
            if( (opt[topb] == '*'|| opt[topb] == '/')&&topa>=2&&topb>=1)
            {if(opt[topb] == '*')
            m = stack[topa-1]*stack[topa];
                else
                m = stack[topa-1]/stack[topa];
                topa--;
                topb--;
                stack[topa] = m;
            }
            opt[++topb] = opts;             }

    }
    if((opt[topb] == '*' || opt[topb] == '/' )&&topa>=2 && topb>=1)
    {
        if(opt[topb]== '*') m = stack[topa-1]*stack[topa];
        else m = stack[topa-1]/stack[topa];
        topa--;
        topb--;
        stack[topa] = m;
    }
    m = stack[1];
    for(i = 1; i< topa; i++)
    {
        if(opt[i]== '+') m = m + stack[i+1];
        else m = m - stack[i+1];
    }
    printf("%lld",m);
    return 0;
}

