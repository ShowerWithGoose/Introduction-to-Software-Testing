#include <stdio.h>
#include <math.h>
#include <string.h>
char s[5000];
char fuhao[5000];
int num[5000];
int tmp=0;
int i,j,k,a=1;
int qushu()
{
    int num = 0;
    for(; isdigit(s[i]); i++)
    {
        num *= 10;
        num +=s[i] - '0';
    }
    i--;
    return num;
}
int main()
{
    gets(s);
    for(; s[i] != '='; i++)
    {
        if(isdigit(s[i]))
            num[a] = qushu();
        else if(s[i] == '+'||s[i] == '-'||s[i] == '*'||s[i] == '/')
            fuhao[a++] = s[i];
    }
    for(i=1; i<a; i++)
    {
        if(fuhao[i] == '*')
        {
            if(tmp == 0)
            {
                num[i] *= num[i+1];
                tmp = i;
            }
            else
                num[tmp] *= num[i+1];
        }
        else if(fuhao[i] == '/')
        {
            if(tmp == 0)
            {
                num[i] /= num[i+1];
                tmp = i;
            }
            else
                num[tmp] /= num[i+1];
        }
        else
            tmp = 0;
    }
    int sum = num[1];
    for(i=1; i<a; i++)
    {
        if(fuhao[i] == '+')
            sum += num[i+1];
        else if(fuhao[i] == '-')
            sum -= num[i+1];
    }
    printf("%d",sum);
    return 0;
}

