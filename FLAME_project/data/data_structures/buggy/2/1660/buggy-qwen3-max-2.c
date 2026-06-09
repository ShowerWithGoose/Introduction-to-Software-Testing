#include <stdio.h>
char s[1000000];
int num[100000];
int num2[100000];
char flag[100000];
int ans = 0;
int sua(int a, int b, char f)
{
    if (f == '+')
    {
        return a + b;
    }
    else if (f == '-')
    {
        return a - b;
    }
    else if (f == '*')
    {
        return a * b;
    }
    else if (f == '/')
    {
        return a / b;
    }
}
int main()
{
    gets(s);
    int j = 0;
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {

        while (s[i] >= '0' && s[i] <= '9')
        {
            num[j++] = s[i] - '0';

            i++;
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'||s[i]=='=')
        {
            flag[k++] = s[i]; // k个符号（包括等号），下标到k-1
        }

        num[j++] = 10; // k个数字 @@ [This line adds a delimiter (10) after every token, including after non-digit characters. This causes incorrect parsing when there are consecutive operators or spaces, and especially when '=' is encountered. It also inserts too many delimiters, leading to wrong number reconstruction.]
    }
    flag[k]='\0';
    int numS = j;
    j = 0;
    int end = j;
    for (int i = 0; i < k; i++)
    {
        int one = 1;
        j = end;
        int ff = j;
        while (num[j] != 10)
        {

            one *= 10;
            j++;
        }
        end = j + 3; // @@ [Arbitrary offset "+3" is incorrect. It should be "j + 1" to move past the current delimiter (10). This causes reading beyond valid digits and corrupts number parsing.]
        j = ff;
        one /= 10;
        while (one != 1)
        {
            num2[i] += num[j++] * one;
            one /= 10;
        }
        num2[i] += num[j++];
        // printf("%d\n",num2[i]);
        // printf("%d\n",k);
    }
    // printf("%d\n",num2[k-1]);
    // int numFlag=k-1;//运算符号个数
    for (int i = 0; flag[i] != '\0'; i++)
    {
        if (flag[i] == '*' || flag[i] == '/')
        {
            num2[i + 1] = sua(num2[i], num2[i + 1], flag[i]);
            //printf("%d\n",num2[i+1]);
            num2[i] = 0;
        }
    }
    //printf("aa");
    for (int i = 0; flag[i] != '\0'; i++)
    {
        //printf("%c",flag[i]);
        if (flag[i] == '+' || flag[i] == '-')
        {
            int ii = i;
            while (num2[i + 1] == 0)
            {
                i++;
            }
            i++;
            //printf("%d\n",num2[i]);
            //printf("%d%c%d=",num2[ii],flag[ii],num2[i]);
            num2[i] = sua(num2[ii], num2[i], flag[ii]);
            //printf("%d\n",num2[i]);
            i--;
        }
    }
    printf("%d\n", num2[k - 1]); // @@ [The final result is assumed to be in num2[k-1], but due to incorrect handling of operator precedence and overwriting during left-to-right evaluation of + and -, the result may not be stored there. Also, the algorithm fails to accumulate all terms correctly after processing * and /.]
    return 0;
}