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
            while (n != j+1)
                printf("%c", a[j++]);
        }
        printf("e%d", 1 - i); // @@ Error: The exponent calculation is incorrect. For numbers like 0.001, the exponent should be negative and based on the number of leading zeros after the decimal point, but this formula does not correctly compute it. For example, input "0.001" should output "1e-3", but this code outputs "1e-2".
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
        printf("e%d", i - 1); // @@ Error: When the number has only one digit before the decimal point (e.g., "1.23"), the exponent should be 0, but this code outputs "e0" correctly. However, for numbers like "12.34", the exponent should be 1, but this code outputs "e1" correctly. The issue is that for numbers like "0.123", the code goes to the else branch (since i != 1 or a[0] != '0'), but the exponent calculation i-1 is wrong. For "0.123", i=1, so it prints "0.123e0", but the correct output should be "1.23e-1". The logic for handling numbers starting with "0." is flawed.
    }
    return 0; 
}