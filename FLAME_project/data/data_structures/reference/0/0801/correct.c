// 2022-03-03
// 作业week1 Problem01
//
// 从键盘输入包含扩展符'-'的字符串，将其扩展为等价的完整字符，例如将a-d扩展为abcd，并输出扩展后的字符串。
// 要求：只处理[a-z]、[A-Z]、[0-9]范围内的字符扩展，即只有当扩展符前后的字符同时是小写字母、大写字母或数字，
// 并且扩展符后的字符大于扩展符前的字符时才进行扩展，其它情况不进行扩展，原样输出。
// 例如：a-R、D-e、0-b、4-B等字符串都不进行扩展。
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isNeedExpand(char *ptrOfCheckHyphen, char *begin, char *end);
void putStringPart(char *ptrOfProcessHyphen, char **ptrOfCharAfterLastHyphen);

int main()
{
    char *input;
    char ipt[1000] = {'\0'};
    input = ipt;
    unsigned long long inputLength = 0;
    fgets(input, 1000, stdin);
    inputLength = strlen(input);

    char *hyphenIndex, *ptrOfCharAfterLastHyphen;
    hyphenIndex = input;
    ptrOfCharAfterLastHyphen = input;
    for (hyphenIndex = strchr(hyphenIndex, '-'); hyphenIndex != NULL; hyphenIndex = strchr(hyphenIndex + 1, '-'))
    {
        if (isNeedExpand(hyphenIndex, input, input + inputLength - 1))
        {
            putStringPart(hyphenIndex, &ptrOfCharAfterLastHyphen);
        }
    }
    printf("%s", ptrOfCharAfterLastHyphen);
    putchar('\n');
    return 0;
}

bool isNeedExpand(char *ptrOfCheckHyphen, char *begin, char *end)
{
    char charBefore, charAfter;
    charBefore = *(ptrOfCheckHyphen - 1);
    charAfter = *(ptrOfCheckHyphen + 1);
    if (ptrOfCheckHyphen == begin || ptrOfCheckHyphen == end)
    {
        return false;
    }
    if (charBefore >= charAfter)
    {
        return false;
    }
    if (charBefore >= '0' && charBefore < '9')
    {
        if (charAfter <= '9')
        {
            return true;
        }
    }
    if (charBefore >= 'A' && charBefore < 'Z')
    {
        if (charAfter <= 'Z')
        {
            return true;
        }
    }
    if (charBefore >= 'a' && charBefore < 'z')
    {
        if (charAfter <= 'z')
        {
            return true;
        }
    }
    return false;
}

void putStringPart(char *ptrOfProcessHyphen, char **ptrOfCharAfterLastHyphen)
{
    char charBefore, charAfter;
    charBefore = *(ptrOfProcessHyphen - 1);
    charAfter = *(ptrOfProcessHyphen + 1);
    *ptrOfProcessHyphen = '\0';
    printf("%s", *ptrOfCharAfterLastHyphen);
    for (char chr = charBefore + 1; chr <= charAfter - 1; ++chr)
    {
        putchar(chr);
    }
    *ptrOfCharAfterLastHyphen = ptrOfProcessHyphen + 1;
    return;
}


