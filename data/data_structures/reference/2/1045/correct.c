#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
int num[100000];
char sh[1000000];
char op[100000];
int i = 0;
int j = 0;
int Fun(int a, int b, char c)
{
    if (c == '*')
        return a * b;
    else if (c == '/')
        return a / b;
    else if (c == '-')
        return a - b;
    else
        return a + b;
}
void F1(void)
{
    int len = strlen(sh);
    for (int k = 0; k < len; k++)
    {
        if (isdigit(sh[k]))
        {
            num[i++] = atoi(sh + k);
            while (isdigit(sh[k]))
                k++;
        }
        if (sh[k] == '+' || sh[k] == '-' || sh[k] == '*' || sh[k] == '/')
            op[j++] = sh[k];
    }
    for (int k = 0, h = 0; k < j; k++, h++)
    {
        if (op[k] == '*' || op[k] == '/')
        {
            num[h + 1] = Fun(num[h], num[h + 1], op[k]);
            num[h] = 0;
        }
    }
    for (int k = 0, h = 0; h < i; k++, h++)
    {
        if (op[k] == '+' || op[k] == '-')
        {
            int m = h + 1;
            while(num[m] == 0)
                m++;
            num[m] = Fun(num[h], num[m], op[k]);
        }
        else if(num[h] != 0)
            num[h + 1] = num[h];
    }
    printf("%d\n", num[i]);
}
int main()
{
    gets(sh);
    F1();
    //printf("%d\n", j);
    return 0;
}
