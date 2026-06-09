#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.')
    {
        if (c[0] == '0')
        {
            int j = 0, cnt = 0;
            for (int i = 2; c[i] != '\0'; i++)
            {
                if (c[i] == '0') cnt++;
                else break;
            }
            cnt++;
            printf("%c", c[cnt + 1]); // @@ The index calculation is incorrect. For input like "0.001", cnt becomes 3 after the loop and increment, so c[cnt+1] = c[4] which is out of bounds or wrong digit. Should use c[2+cnt] or adjust logic.
            if(c[cnt + 2] != '\0') printf("."); // @@ Similarly, index c[cnt+2] may be out of bounds or incorrect.
            for(int i = cnt + 2; c[i] != '\0'; i++) // @@ Starting index is wrong; should start from the first non-zero digit after the decimal point.
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt); // @@ The exponent should be cnt (number of zeros after decimal point plus one), but the reference program uses num1+1. Here cnt already includes the increment, so it might be off by one depending on input.
        }
        else
        {
            printf("%se0", c); // @@ This prints the entire input including the decimal point, but the base should have only one digit before the decimal point. For example, "1.23" should become "1.23e0", but this prints "1.23e0" which is correct only if the input has exactly one digit before the decimal. However, the problem allows multiple digits before decimal (e.g., "12.34"), and this case should be handled in the else branch, not here.
        }
    }
    else
    {
        int cnt,flag = 0;
        for(cnt = 0; c[cnt] != '\0'; cnt++)
        {
            if(c[cnt] == '.')
            {
                break;
            }
            if(c[cnt] != '0' && cnt > 0)
            {
                flag = 1;
            }
        }
        printf("%c", c[0]);
        if(flag) printf(".");
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') // @@ This condition removes all zeros, but the problem states there are no trailing zeros after the decimal point. However, zeros between non-zero digits should be kept (e.g., "102.3" should become "1.023e2", but this would remove the zero, giving "1.23e2"). Also, for integers like "100", this would remove all zeros, producing "1e2" which is correct, but for "10.0" (though not allowed per spec), it would fail.
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1);
    }
    return 0;
}