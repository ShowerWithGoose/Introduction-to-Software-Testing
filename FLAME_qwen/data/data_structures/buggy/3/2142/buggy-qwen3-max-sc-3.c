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
        if(str[i]!=0&&str[i]!='.') // @@ [The condition `str[i]!=0` is always true because any character (including '0') has a non-zero ASCII value. It should check for `'0'` character instead of numeric zero. This causes incorrect identification of the first non-zero digit.]
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
            getchar(); // @@ [Unnecessary `getchar()` may cause issues in automated judging systems expecting only the scientific notation output without extra input consumption.]
            
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
        printf("%se%d\n", str, m); // @@ [When there's no decimal point (a == 0), the number is an integer, but this prints the whole string as base, which may have more than one digit. Scientific notation requires only one significant digit in the base.]
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