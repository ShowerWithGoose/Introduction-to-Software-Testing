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
        if(str[i]!=0&&str[i]!='.') // @@ [The condition `str[i]!=0` is incorrect; it should check for non-'0' digit, i.e., `str[i]!='0'`. This causes the function to return 0 immediately since `str[0]` is never null in a valid string.]
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
            getchar(); // @@ [Unnecessary `getchar()` may interfere with output and is not part of required output format. Also, logic for printing mantissa is flawed—it prints extra digits and skips handling of decimal removal properly.]
            
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
        printf("%se%d\n", str, m); // @@ [When there's no decimal point (a==0), the input is an integer, but this prints the whole number as base, violating the requirement that base must have only one significant digit.]
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