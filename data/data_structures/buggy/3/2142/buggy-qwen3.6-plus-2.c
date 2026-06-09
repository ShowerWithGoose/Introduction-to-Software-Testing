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
        if(str[i]!=0&&str[i]!='.') // @@ [Semantic Error] Comparing with integer 0 checks for the null terminator; it should be '0' to correctly skip leading zero characters.
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
            for(int i=1;i<len;i++) // @@ [Compilation Error] C89/C90 standard does not allow declaring loop variables inside the for statement initialization; declare 'int i;' before the loop.
            {
                if(i<a)
                {
                    printf("%c", str[i]);
                }
                else if(i==a); // @@ [Logical Error] The trailing semicolon creates an empty statement, causing the decimal point to be skipped when i equals a.
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
                for(int j=b+1;j<len;j++) // @@ [Compilation Error] C89/C90 standard does not allow declaring loop variables inside the for statement initialization; declare 'int j;' before the loop.
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
        printf("%se%d\n", str, m);
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