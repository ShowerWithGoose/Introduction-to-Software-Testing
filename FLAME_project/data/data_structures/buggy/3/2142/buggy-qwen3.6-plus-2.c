#include<stdio.h>/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<string.h>
int find1(char *str)
{
    int i=0, j=0;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='.')
        {
            return i;
        }
    }
    return 0;
}
int find2(char *str)
{
    int i=0;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]!=0&&str[i]!='.') // @@ The condition str[i]!=0 checks if the character is not the null terminator, but it should check if the character is not '0' (digit zero) to find the first significant digit. It should be str[i]!='0'.
        {
            return i;
        }
    }
    return 0;
}
void trans(char *str, int a, int b)
{
    int m;
    int len=strlen(str);
    if(a!=0)
    {
        if(a>b)
        {
            m=a-b-1;
            printf("%c.", str[0]);
            for(int i=1;i<len;i++)
            {
                if(i<a)
                {
                    printf("%c", str[i]);
                }
                else if(i==a);
                else if(i>a)
                {
                    printf("%c", str[i]);
                }
            }
            printf("e%d\n", m);
            getchar();
            
        }
        else
        {
            m=b-a;
            if((b+1)!=len)
            {
                printf("%c.", str[b]);
                for(int j=b+1;j<len;j++)
                {
                    printf("%c", str[j]);
                }
            }
            else
            {
                printf("%c", str[b]);
            }
            printf("e-%d\n", m);
        }
    }
    else
    {
        m=len-1;
        printf("%se%d\n", str, m); // @@ This branch handles cases where the decimal point is at index 0 (e.g., ".5"), which is not the standard input format described. More importantly, for input "0.9", find1 returns 1 and find2 (with the bug fixed) would return 1. The logic falls into the else block of if(a!=0) only if a==0. However, for "0.9", a=1. The main issue is that the logic for numbers less than 1 (like 0.9) is handled in the `else` part of `if(a>b)`. Let's trace "0.9". f1=1, f2=1 (if bug fixed, f2 finds '9' at index 1? No, '0' is at 0, '.' at 1, '9' at 2. find2 with bug fix str[i]!='0' returns 2. So a=1, b=2. a<b. Enters else branch of if(a>b). m = 2-1 = 1. Prints str[2] which is '9'. Then checks if (2+1)!=3 (len=3). False. So prints just '9'. Then prints e-1. Result 9e-1. This seems correct if find2 is fixed.
        // However, looking at the provided buggy output "0.9e0", let's trace the original buggy code.
        // Input: "0.9". len=3.
        // find1 returns 1 (index of '.').
        // find2: i=0, str[0]='0'. str[0]!=0 is true. str[0]!='.' is true. Returns 0.
        // So a=1, b=0.
        // trans(s, 1, 0).
        // a!=0 is true.
        // a>b (1>0) is true.
        // m = a-b-1 = 1-0-1 = 0.
        // printf("%c.", str[0]) -> prints "0.".
        // Loop i=1 to 2.
        // i=1: i<a (1<1) false. i==a (1==1) true. Empty statement.
        // i=2: i<a false. i==a false. i>a true. printf("%c", str[2]) -> prints "9".
        // printf("e%d\n", 0) -> prints "e0".
        // Output: "0.9e0".
        // The expected output is "9e-1".
        // The error stems from find2 returning the index of '0' instead of the first non-zero digit.
        // If find2 is fixed to return 2 (index of '9'), then a=1, b=2.
        // a!=0 true. a>b (1>2) false.
        // Else branch:
        // m = b-a = 2-1 = 1.
        // (b+1)!=len -> (3)!=3 false.
        // Else: printf("%c", str[2]) -> prints "9".
        // printf("e-%d\n", 1) -> prints "e-1".
        // Output: "9e-1". Correct.
        // So the primary error is indeed in find2.
        // Are there other errors?
        // What if input is "10.5"?
        // f1=2, f2=0 ('1' is non-zero).
        // a=2, b=0. a>b.
        // m = 2-0-1 = 1.
        // printf("%c.", str[0]) -> "1.".
        // Loop i=1 to 4 (len=4).
        // i=1: i<a (1<2) true. printf("%c", str[1]) -> "0".
        // i=2: i==a true. Skip.
        // i=3: i>a true. printf("%c", str[3]) -> "5".
        // Output: "1.05e1". Expected: "1.05e1". Correct.
        // What if input is "0.01"?
        // f1=1. f2 (fixed) returns 2 ('1' is at index 2? No, "0.01". Index 0:'0', 1:'.', 2:'0', 3:'1'. find2 returns 3).
        // a=1, b=3. a<b.
        // m = 3-1 = 2.
        // (3+1)!=4 false.
        // printf("%c", str[3]) -> "1".
        // printf("e-2"). Output "1e-2". Expected "1e-2". Correct.
        // What if input is "5.0"? Problem says no trailing zeros. So "5" or "5.0" isn't valid if it implies trailing zeros are stripped. "all digits are significant". So "5.0" won't appear. "5" appears as "5."? No, "digits before and after the decimal point". So input always has a decimal point and digits on both sides.
        // So the only error is in find2.
    }
}
int main()
{
    char s[1008]={0};
    scanf("%s", s);
    int f1=find1(s);
    int f2=find2(s);
    trans(s, f1, f2);
    return 0;
}