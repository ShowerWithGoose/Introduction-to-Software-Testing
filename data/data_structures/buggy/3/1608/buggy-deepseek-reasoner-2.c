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
            printf("%c", c[cnt + 1]);
            if(c[cnt + 2] != '\0') printf(".");
            for(int i = cnt + 2; c[i] != '\0'; i++)
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt);
        }
        else
        {
            printf("%se0", c);
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
            if(c[cnt] != '0' && cnt > 0) // @@ The flag is set only when a non-zero digit appears in the integer part after the first digit. This is insufficient: the decimal point should always be printed because there are always fractional digits. For inputs like "10.23" (second digit '0'), flag remains 0, causing the decimal point to be omitted.
            {
                flag = 1;
            }
        }
        printf("%c", c[0]);
        if(flag) printf("."); // @@ The decimal point should be printed unconditionally since the original number always has a fractional part and the base must have a fractional component in scientific notation (except when the base is an integer, which only occurs if the fractional part is empty, but the input guarantees at least one digit after the decimal point).  Thus, the condition is wrong.
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') // @@ This condition filters out zeros, but zeros in both the integer part (after the first digit) and the fractional part are significant and must be printed. The correct condition should only skip the decimal point character. For example, "10.23" should become "1.023" not "123".
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1);
    }
    return 0;
}