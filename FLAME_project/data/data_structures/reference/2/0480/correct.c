#include <stdio.h>
#include<string.h>
//#include<process.h>

int main()
{
    char s[10000];
    int i,j,len,ans = 0,a = 0,record = 0,fuhao[1000],shuzi[1000],k,m,fuhaoshu,shuzishu,deal[1000],otnum = 0,newr = 0;//计数;
    gets(s);
    //
    len = strlen(s);
    for(i = j = 0;i <= len;i++)
    {
        if(s[i] != ' ')
            s[j++] = s[i];
    }
    //
    //1.除去空格
    //
    //printf("jiedian1\n");
    len = j;
    for(k = 0 , m = 0;k < len ;k++)
    {
        if(s[k] == '+')
        {
            fuhao[m] = 1;
            m++;
        }
        else if(s[k] == '-')
        {
            fuhao[m] = 2;
            m++;
        }
        else if(s[k] == '*')
        {
            fuhao[m] = 3;
            m++;
        }
        else if(s[k] == '/')
        {
            fuhao[m] = 4;
            m++;
        }
        else if(s[k] == '=')
        {
            fuhao[m] = 6;
            m++;
        }
    }
    //
    //2.标记符号种类，并且计算数量
    //
    //printf("jiedian2\n");
    fuhaoshu = m;
    shuzishu = m;
    m = k = 0;
    //printf("fuhaoshu:%d\n",fuhaoshu);
    record = 0;
    for(k = m = 0;k < len;k++)
    {
        if(s[k] <='9'&&s[k] >= '0'&&record == 0)
        {
            record++;
            a = s[k] - '0';
        }
        else if(s[k] <='9'&&s[k] >= '0'&&record != 0)
        {
            a = s[k] + 10*a - '0';
        }
        else
        {
            shuzi[m++] = a;
            a = 0;
            record = 0;
        }

    }

    //
    //3.将高位的数字符号变成int型。
    //
   // printf("jiedian3\n");
    ans = shuzi[0];
    record = 0;
    for(k = 0,i = 0;k < fuhaoshu;k++)
    {
        if((fuhao[k] == 3||fuhao[k] == 4)&&record == 0)
        {
            newr++;
            if(fuhao[k] == 3)
            {
                a = shuzi[k]*shuzi[k+1];
                                            shuzi[k+1] = 0;
                fuhao[k] = 5;
            }
            if(fuhao[k] == 4)
            {
                a = shuzi[k]/shuzi[k+1];
                                            shuzi[k+1] = 0;
                fuhao[k] = 5;
            }
            if(fuhao[k+1] == 1||fuhao[k+1] == 2||fuhao[k+1] == 6)
            {
                deal[i] = a;
                i++;
                k++;
                continue;
            }
            record++;
            continue;
        }
        else if(fuhao[k] == 3||fuhao[k] == 4)
        {
            newr++;
            if(fuhao[k] == 3)
            {
                a = a*shuzi[k+1];
                                        shuzi[k+1] = 0;
                fuhao[k] = 5;
            }
            if(fuhao[k] == 4)
            {
                a = a/shuzi[k+1];
                                        shuzi[k+1] = 0;
                fuhao[k] = 5;
            }
            if(fuhao[k+1] == 1||fuhao[k+1] == 2||fuhao[k+1] == 6)
            {
                deal[i] = a;
                i++;
                k++;
                record = 0;
            }

        }
        else if((fuhao[k] == 1||fuhao[k] == 2||fuhao[k] == 6)&&newr == 0)
            {
                if(shuzi[k] == 0)
                    continue;
                deal[i] = shuzi[k];
                i++;
            }
        else if(fuhao[k] == 1||fuhao[k] == 2||fuhao[k] == 6)
            {
                 if(shuzi[k] == 0)
                    continue;
                deal[i] = shuzi[k];
                i++;
            }

        if(fuhao[k] == 1||fuhao[k] ==2)
        {
            otnum++;
        }
    }
    //
    //4.将所有优先度高的运算先进行，然后所有乘除运算的结果存到数列中。
    //
    //printf("jiedian4\n");

    record = 0;
    ans = deal[0];
    for(k = 0,i = 1;k < fuhaoshu;k++)
    {
           if(fuhao[k] == 1)
            {
                ans = ans + deal[i];
                i++;
            }
            if(fuhao[k] == 2)
            {
               ans = ans - deal[i];
                i++;
            }

    }
    //
    //5.进行加减运算，得到结果。
    //
    //printf("jiedian5\n");
    printf("%d",ans);

    return 0;

}

