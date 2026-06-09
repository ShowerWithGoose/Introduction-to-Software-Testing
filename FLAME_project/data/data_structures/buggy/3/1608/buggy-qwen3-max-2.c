#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.') // @@ [This condition assumes the decimal point is always at index 1, which fails for numbers like "87899.999...", where '.' is not at position 1.]
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
            printf("%c", c[cnt + 1]); // @@ [Incorrect indexing: after counting leading zeros starting from index 2, the first non-zero digit is at index 2 + cnt, not cnt + 1. Also, this skips the correct first significant digit.]
            if(c[cnt + 2] != '\0') printf(".");
            for(int i = cnt + 2; c[i] != '\0'; i++)
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt);
        }
        else
        {
            printf("%se0", c); // @@ [This prints the original number as-is with "e0", but scientific notation requires normalization to one non-zero digit before the decimal point. For example, "5.3" should become "5.3e0", but "12.3" would incorrectly remain "12.3e0". However, this branch only triggers when c[1]=='.', so it's for single-digit before decimal, but still doesn't handle trailing digits correctly in all cases. But the main issue is the outer condition.]
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
        if(flag) printf("."); // @@ [The 'flag' logic is flawed: it only checks if there's a non-zero digit after the first digit before the decimal point, but scientific notation always requires a decimal point unless there are no digits after the first one. According to the problem, if it's a decimal, it must have one digit before and after the decimal point. So even if trailing digits include zeros (which are significant per problem), they must be printed. This code skips all '0' digits after the decimal point due to the condition in the next loop.]
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') // @@ [This skips all '0' digits anywhere after the first character, including significant zeros that are part of the input (e.g., the '0's in "87899.9999999999000999" are significant and must appear in the mantissa). The problem states: "all digits are significant (i.e., there are no trailing zeros after the decimal point)" — meaning every digit provided is significant, including internal or trailing zeros before the end. So removing any '0' is wrong.]
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1);
    }
    return 0;
}