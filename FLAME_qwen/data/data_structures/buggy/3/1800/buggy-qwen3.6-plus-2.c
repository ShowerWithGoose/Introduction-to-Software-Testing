#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
    char a[100] = { 0 };
    gets(a);
    int n = strlen(a);
    int i = 0;
    for (; i < n; i++)
    {
        if (a[i] == '.')
            break;
    }
    if (i == 1 && a[0] == '0')
    {
        while (a[i + 1]=='0')
            i++;
        i++;
        if (n == i+1)
            printf("%c", a[i]);
        else
        {
            printf("%c.", a[i]);
            int j = i + 1;
            while (n != j+1) // @@ [The condition n != j+1 incorrectly stops the loop when j reaches n-1, causing the last digit to be skipped; it should be j < n to print all remaining digits]
                printf("%c", a[j++]);
        }
        printf("e%d", 1 - i);
    }
    else
    {
        printf("%c.", a[0]);
        for (int j = 1; j < n; j++)
        {
            if (j == i)
                continue;
            printf("%c", a[j]);
        }
        printf("e%d", i - 1);
    }
    return 0; 
}