#include <stdio.h>
#include <string.h>
char line[1000];
void case1(int len1)
{
    int i = 2, flag1 = 0;
    while(line[i] == '0')
    {
        flag1++;
        i++;
    }
    if (line[i + 1] == 0)
        printf("%ce-%d", line[i], flag1 + 1);
    else//line[i+1]!=0
    {
        printf("%c.", line[i]);
        while (line[i] != 0)
        {
            i++;
            printf("%c", line[i]);
        }
        getchar(); // @@ [This getchar() is erroneous and causes incorrect output; it reads an extra character from input which is not needed and may cause missing or extra characters in output. Also, the loop above prints a null terminator as a character.]
        printf("e-%d", flag1 + 1);
    }
}
void case2(int len2)
{
    int j;
    printf("%c.", line[0]);
    for (j = 2; j < len2; j++)
    {
        printf("%c", line[j]);
    }
    printf("e0"); // @@ [Exponent should be 0 only if the number is of the form "d.d...", but this assumes input like "5.123" becomes "5.123e0", which violates the requirement that scientific notation must have exactly one non-zero digit before the decimal. Correct exponent for "5.123" is e0, but base should be "5.123" -> "5.123" is already normalized? Actually, per problem: if only one digit before decimal and it's non-zero, then it's already normalized. So "5.123" => "5.123e0" is correct. However, the bigger issue is that this function doesn't handle trailing zeros, but problem states no trailing zeros exist. So maybe not wrong here. But wait: what if input is "5."? The problem says digits before and after decimal point exist, so "5." won't occur. So case2 might be okay. But note: the real error is elsewhere.]
}
void case3(int len3)
{
    int k = 0, flag3 = 0;
    while (line[k] !='.')
    {
        flag3++;
        k++;
    }
    printf("%c.", line[0]);
    for (k = 1; k < flag3; k ++)
    {
        printf("%c", line[k]);
    }
    for (k = flag3 + 1; k < len3; k ++)
    {
        printf("%c", line[k]);    
    }
    printf("e%d", flag3 - 1); 
}
int main()
{
    gets(line); // @@ [Use of gets() is unsafe and deprecated; however, the immediate compilation error reported is "gcc: not found", which is environment-related, but the actual logical errors are in the code. However, the problem states the error type is Compilation Error, but the provided test output shows a shell error, not a compiler error. This suggests the real issue might be that the code uses gets(), which may cause compilation failure in modern compilers unless explicitly allowed. In C11, gets() was removed. So using gets() can cause a compilation error.]
    int len = strlen(line);
    if(line[0] == '0')
        case1(len);
    else if(line[0] != '0' && line[1] == '.')
        case2(len);
    else
        case3(len);
    return 0;
}