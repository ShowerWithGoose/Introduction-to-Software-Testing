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
        if(str[i]!=0&&str[i]!='.')
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
            printf("%c.", str[0]); // @@ Error: For input like "0.9", a=1, b=1, so a>b is false, this branch is not taken. But the logic here assumes the first digit is non-zero, which fails for numbers like "0.9" where the first digit is '0'.
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
                printf("%c.", str[b]); // @@ Error: For input "0.9", b=1 (index of '9'), this prints "9." but should print "9" without decimal point since the base is an integer (one significant digit). Also, the exponent calculation m=b-a=0, so output is "9.e0", but expected is "9e-1".
                for(int j=b+1;j<len;j++)
                {
                    printf("%c", str[j]);
                }
            }
            else
            {
                printf("%c", str[b]);
            }
            printf("e-%d\n", m); // @@ Error: The exponent should be negative only when the decimal point is before the first non-zero digit. Here m=0, so it prints "e-0", but expected is "e-1". The exponent calculation is incorrect for cases where the first non-zero digit is after the decimal point.
        }
    }
    else
    {
        m=len-1;
        printf("%se%d\n", str, m); // @@ Error: This branch handles cases where there is no decimal point, but the problem always has a decimal point. For input like "0.9", a=1 (position of '.'), so this branch is not taken. However, the logic is flawed for other cases.
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