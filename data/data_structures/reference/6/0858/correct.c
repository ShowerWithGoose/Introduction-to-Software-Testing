#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int op[512];
int stack[128];
char temp[1024];
char tempnum[8];
int getNum(char[]);
void EmptyArray(char[]);
int POW10(int);
int main()
{
    int i = 0, j = 0, k = 0;
    gets(temp);
    while(temp[i]!='\0')
    {
        tempnum[k] = temp[i];
        i++;
        k++;
        if(temp[i]==' ')
        {
            op[j] = getNum(tempnum);
            j++;
            EmptyArray(tempnum);
            k = 0;
            i++;
        }
    }
    op[j] = getNum(tempnum);
    /*for (j = 0; op[j] != -1;j++)
    {
        printf("%d ", op[j]);
    }*/
    j = 0;
    i = 0;
    while(op[i]!=-1)
    {switch (op[i])
    {
    case 1:
        if (j == 100)
        {
            printf("error ");
            i += 2;
        }
        else
        {
            i++;
            j++;
            stack[j] = op[i];
            i++;
        }
        break;
    case 0:
        if (j == 0)
        {
            printf("error ");
            i++;
        }
        else
        {
            j--;
            printf("%d ", stack[j + 1]);
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
