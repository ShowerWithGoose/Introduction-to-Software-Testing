#include <stdio.h>
#include <string.h>
char a[1000];
char b[1000];
int judge(char x, char y)
{
    if (x >= y)
        return 0;
    else
    {
        if ((x >= '0' && y <= '9') || (x >= 'a' && y <= 'z') || (x >= 'A' && y < +'Z'))
            return 1;
        else
            return 0;
    }
}
int main()
{
    int i;
    int j;
    int k;
    int flag = 0;
    char start, end;
    gets(a);
    for (i = 0, j = 0; a[i] != '\0'; i++)
    {
        if (a[i + 1] == '-')
        {
            start = a[i], end = a[i + 2];
            k = 0;
            if (judge(start, end))
            {
                while (k <= end - start - 1)
                {
                    b[j++] = start + k;
                    k++;
                }
                i += 1;
                flag++;
            }
            else
                b[j++] = a[i];
        }
        else
            b[j++] = a[i];
    }
    puts(b);
    // getchar();
    return 0;
}
//第一次出现了头尾重复的情况
// ADEa-g-m02输出是ADEabcdefgghijklmm02
//感觉是k这个地方0的问题，改成1没有解决
//后来发现问题来在于a-g-m，
// a-g也会出现重复，后来发现重复都发生再末尾
//你在处理-的时候不要加到末尾就行了
//后来发现是你有错误，运行的是上一次的代码（下雨了）
//把k<=end-start改成k<=end-start-1就好了
