#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
    char a[100] = { 0 };
    gets(a); // @@ [gets() is unsafe and may cause buffer overflow; also, it's removed in C11 and later standards, but the main issue is that the program fails to handle the case where the input has no decimal point or has leading zeros correctly]
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
        printf("e%d", 1 - i); // @@ [The exponent calculation is incorrect for numbers like 0.001; it should be -(i-1) or similar, but the logic here is flawed]
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
        printf("e%d", i - 1); // @@ [For numbers with more than one digit before the decimal point (e.g., 12.34), this incorrectly outputs the first digit as the base and the exponent as i-1, but the base should include all non-zero digits before the decimal point, and the exponent should be the number of digits before the decimal minus 1]
    }
    return 0; 
}