#define _CRT_SECURE_NO_WARNINGS
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define NumberOf(a) (sizeof(a)/sizeof(a[0]))
#define eps 1e-7
#define ll long long
#define maxn 1000000005
#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[10001];
    int location[10001] = { -2};
    gets(s);
    int l = strlen(s);
    int i,j=1,k,p;
    for (i = 0; i < l; i++)
    {
        if (s[i] == '-')
        {
            location[j++] = i;
        }
    }
    for (i = 1; i <j; i++)
    {
        for (k = location[i-1]+2; k < location[i]; k++)
        {
            printf("%c", s[k]);
        }
        if ((s[location[i] - 1] >= 'a' && s[location[i] + 1] <= 'z') || (s[location[i] - 1] >= '0' && s[location[i] + 1] <= '9') || (s[location[i] - 1] >= 'A' && s[location[i] + 1] <= 'Z')) // @@ 条件判断错误：缺少对左右字符范围上限和左<右的检查，且缺少else分支导致非展开时'-'丢失
        {
            for (p = 1; p <= s[location[i] + 1] - s[location[i] - 1]; p++)
            {
                printf("%c", s[location[i] - 1] + p);
            }
        }
    }
    for (i = location[j-1]+2; i < l; i++) // @@ 当最后一个字符为'-'时，此循环起始位置错误，导致遗漏输出'-'，且可能越界访问
    {
        printf("%c", s[i]);
    }
}