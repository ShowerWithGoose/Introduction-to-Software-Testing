#include <stdio.h>
#include <math.h>
#include <string.h>

typedef long long LL;

char s[100005];
LL stk_out[100005], stk_in[100005];//-1 = +  -2 = -  -3 = *  -4 = /
int top_out = 0, top_in = 0;

void re_space()
{
    char tmp[100005];
    int len1 = strlen(s), len2 = 0;
    for (int i = 0; i < len1; i ++ )
        if (s[i] != ' ')
            tmp[len2++] = s[i];
    tmp[len2] = '\0';
    strcpy(s, tmp);
}
int readin(int x)
{
    if (s[x] >= '0' && s[x] <= '9')
    {
        LL num = 0;
        int wei = 0;
        for (int i = x; s[i] != '='; i ++ )
        {
            if (!(s[i] >= '0' && s[i] <= '9'))
                break;
            num = num * 10 + (s[i] - '0');
            wei ++;
        }
        stk_out[++ top_out] = num;
        return wei;
    }
    if (s[x] == '+')
    {
        while(top_in > 0)
            stk_out[++ top_out] = stk_in[top_in --];
        stk_in[++ top_in] = -1;
    }
    if (s[x] == '-')
    {
        while(top_in > 0)
            stk_out[++ top_out] = stk_in[top_in --];
        stk_in[++ top_in] = -2;
    }
    if (s[x] == '*')
    {
        while(stk_in[top_in] == -3 || stk_in[top_in] == -4)
            stk_out[++ top_out] = stk_in[top_in --];
        stk_in[++ top_in] = -3;
    }
    if (s[x] == '/')
    {
        while(stk_in[top_in] == -3 || stk_in[top_in] == -4)
            stk_out[++ top_out] = stk_in[top_in --];
        stk_in[++ top_in] = -4;
    }
    return 1;

}
void cal()
{
    top_in = 0;
    LL num1, num2;
    for (int i = 1; i <= top_out; i ++ )
    {
        if (stk_out[i] >= 0)
            stk_in[ ++ top_in] = stk_out[i];
        else
        {
            LL tmp;
            num1 = stk_in[top_in -- ];
            num2 = stk_in[top_in -- ];
            switch(stk_out[i])
            {
                case -1:
                    tmp = num1 + num2;
                    break;
                case -2:
                    tmp = num2 - num1;
                    break;
                case -3:
                    tmp = num2 * num1;
                    break;
                case -4:
                    tmp = num2 / num1;
                    break;
            }
            stk_in[ ++ top_in] = tmp;
        }
    }
}

int main()
{
    gets(s);
    re_space();
    for (int i = 0; s[i] != '=';)
        i += readin(i);
    while(top_in > 0)
        stk_out[++ top_out] = stk_in[top_in --];
    cal();
    printf("%lld", stk_in[1]);
    
    return 0;
}


