#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
    char a[100] = { 0 };
    gets(a); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in some environments like newer C standards or certain compilers, 'gets' is removed entirely causing compilation error]
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
            while (n != j+1)
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