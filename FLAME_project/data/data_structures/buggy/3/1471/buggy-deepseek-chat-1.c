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
        while (line[i] != 0) // @@ This loop prints the null terminator and continues past the end of the string; should use index-based loop with len1
        {
            i++;
            printf("%c", line[i]);
        }
        getchar(); // @@ This getchar() is unnecessary and may cause input buffering issues; should be removed
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
    printf("e0");
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
    gets(line);
    int len = strlen(line);
    if(line[0] == '0')
        case1(len);
    else if(line[0] != '0' && line[1] == '.')
        case2(len);
    else
        case3(len);
    return 0;
}