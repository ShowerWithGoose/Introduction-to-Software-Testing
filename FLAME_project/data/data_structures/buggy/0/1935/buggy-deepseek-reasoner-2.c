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
        if ((s[location[i] - 1] >= 'a' && s[location[i] + 1] <= 'z') || (s[location[i] - 1] >= '0' && s[location[i] + 1] <= '9') || (s[location[i] - 1] >= 'A' && s[location[i] + 1] <= 'Z')) // @@ 条件判断错误：只检查了一侧的范围下界和另一侧的上界，未确保两侧字符属于同一类型（如大写、小写、数字）。对于"B-e"，条件为假，导致不展开，且没有else分支输出'-'和右侧字符，造成输出缺失。
        {
            for (p = 1; p <= s[location[i] + 1] - s[location[i] - 1]; p++)
            {
                printf("%c", s[location[i] - 1] + p);
            }
        }
    }
    for (i = location[j-1]+2; i < l; i++) // @@ 起始索引错误：location[j-1]是最后一个'-'的位置，加2会跳过'-'及其后的第一个字符（如'e'），导致该字符未被输出。应改为 location[j-1]+1 且需输出'-'本身，但整体输出逻辑缺失了对'-'的处理。
    {
        printf("%c", s[i]);
    }
}