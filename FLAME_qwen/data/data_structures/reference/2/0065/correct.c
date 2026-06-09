#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void squeezchr(char s[], char c);
int aandsf(int n[], char s[]);
int squeeznum(int s[], int a);
int main()
{
    char str[5000], tra[1000];
    int n[2600], i = 0, j = 0, k = 0;
    char b[2600];
    gets(str);
    squeezchr(str,' ');
    do
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            tra[j] = str[i];
            i++;
            j++;
        }
        else
        {
            j = 0;
            n[k] = atoi(tra);
            b[k] = str[i];
            memset(tra, 0, sizeof(tra));
            k++;
            i++;
        }
    }while(str[i] != '\0');
    for (i = 0; i < k - 1;i++)
    {
        if(b[i] != '*' && b[i] != '/')
            continue;
        else if(b[i]=='*')
        {
            n[i + 1] = n[i] * n[i + 1];
            n[i] = -2;
        }
        else
        {
            n[i + 1] = n[i] / n[i + 1];
            n[i] = -2;
        }
    }
    squeezchr(b, '*');
    squeezchr(b, '/');
    squeeznum(n, k - 1);
    printf("%d", aandsf(n, b));
}
int aandsf(int n[], char s[])
{
    int i,sum;
    sum = n[0];
    for(i = 0; s[i] != '=';i++)
    {
        if(s[i]=='+')
            sum += n[i+1];
        else
            sum -= n[i+1];
    }
    return sum;
}
void squeezchr(char s[], char c)
{
    int i,j;
    for(i=j=0;s[i]!='\0';i++)
    {
        if(s[i]!=c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}
int squeeznum(int s[], int a)
{
    int i,j;
    for(i=j=0;i < a+1;i++)
    {
        if(s[i]!= -2)
            s[j++] = s[i];
    }
    return j;
}


