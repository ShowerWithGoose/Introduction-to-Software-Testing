//
//  main.c
//  example1c
//
//  Created by  on 2022/3/3.
//

/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1005//gouma???
int num[MAXN], temp, left[MAXN], right[MAXN];
char fuhao[MAXN];
int main()
{
    char s[MAXN];
    int i, j, mark, len, power, n=0, temp=0;
    gets(s);
    //先把空格都删掉
    for (i=j=0; s[i]!='\0'; i++)
    {
        if (s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    len=j-1;//到这里已经把所有空格删除
    //printf("%s, %d\n", s, len);//
    for (i=j=mark=0; i<=len; i++)
    {
        if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='=')//i是这个运算符的位置
        {
            fuhao[n]=s[i];
            for (j=i-1, power=0; j>=mark; j--, power++)//把这个运算符前的数存到num[n]里
            {
                //printf("%d, %d, %lf\n", s[j]-'0', power, pow(10.0, (double)power));//
                num[n]+=(s[j]-'0')*pow(10.0, (double)power);
            }
            //printf("%d, %d: %d, %c\n", i, n, num[n], fuhao[n]);//
            mark=i+1;//mark是这个运算符之后的数字的开始位置
            n++;
        }
    }
    n--;
    for (i=0; i<=n; i++)
    {
        if (fuhao[i]=='*' || fuhao[i]=='/')
        {
            
            if (fuhao[i]=='*')
            {
                num[i]*=num[i+1];
            }
            else
            {
                num[i]/=num[i+1];
            }
            fuhao[i]=fuhao[i+1];
            for (j=i+1; j<n; j++)
            {
                num[j]=num[j+1];
                fuhao[j]=fuhao[j+1];
            }
            num[n]='\0';
            n--;
            i--;
        }
    }
    temp=num[0];
    for (i=0; i<=n; i++)
    {
        if (fuhao[i]=='+')
        {
            temp+=num[i+1];
        }
        if (fuhao[i]=='-')
        {
            temp-=num[i+1];
        }
    }
    printf("%d\n", temp);
    return 0;
}

