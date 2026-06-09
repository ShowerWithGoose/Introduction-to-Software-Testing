#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num[512];
int stack[128];
char s[1024];
char res[8];
int getNum(char[]);
void EmptyArray(char[]);
int POW10(int);
int main()
{
    int i = 0, num_tt = 0, k = 0;
    gets(s);
    while(s[i]!='\0')
    {
        res[k] = s[i];
        i++;
        k++;
        if(s[i]==' ')
        {
            num[num_tt] = getNum(res);
            num_tt++;
            EmptyArray(res);
            k = 0;
            i++;
        }
    }
    num[num_tt] = getNum(res);
    /*for (j = 0; op[j] != -1;j++)
    {
        printf("%d ", op[j]);
    }*/
    num_tt = 0;
    i = 0;
    while(num[i]!=-1)
    {switch (num[i])
    {
    case 1:
        if (num_tt == 100)
        {
            printf("error ");
            i += 2;
        }
        else
        {
            i++;
            num_tt++;
            stack[num_tt] = num[i];
            i++;
        }
        break;
    case 0:
        if (num_tt == 0)
        {
            printf("error ");
            i++;
        }
        else
        {
            num_tt--;
            printf("%d ", stack[num_tt + 1]);
            i++;
        }
        break;
        }}
    
    system("pause");
    return 0;
}
int getNum(char s[])
{
    int res = 0;
    int length;
    int flag;
    int i;
    length = strlen(s);
    flag = length;
    if(s[0]!='-')
    {
        for (i = 0; i < flag; i++)
        {
            res += (s[i]-'0') * POW10(length - 1);
            length--;
        }
        return res;
    }
    else if(s[0]=='-')
    {
        for (i = 1; i < flag;i++)
        {
            res += (s[i]-'0') * POW10(length - 2);
            length--;
        }
        res *= -1;
        return res;
    }
    return -1;
}
void EmptyArray(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] = '\0';
    }
}
int POW10(int n)
{
    if(n==0)
        return 1;
    else
    {
        return 10 * POW10(n - 1);
    }
}
