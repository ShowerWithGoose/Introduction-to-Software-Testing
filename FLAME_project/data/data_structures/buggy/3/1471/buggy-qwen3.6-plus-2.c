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
    if (line[i + 1] == 0) // @@ The condition checks if the character AFTER the first non-zero digit is null. If the input is "0.0...0X" where X is the last char, line[i+1] is 0. This part handles single significant digit correctly. However, the else block has issues.
        printf("%ce-%d", line[i], flag1 + 1);
    else//line[i+1]!=0
    {
        printf("%c.", line[i]);
        while (line[i] != 0) // @@ This loop increments i BEFORE printing. So it prints line[i+1], line[i+2]... until null. It misses printing line[i] itself? No, line[i] was printed before the dot. Wait. printf("%c.", line[i]) prints the digit and a dot. Then the loop starts. Inside loop: i++ then print. So it prints the next characters. This seems logically okay for printing the rest of the string.
        {
            i++;
            printf("%c", line[i]);
        }
        getchar(); // @@ This reads a character from stdin. There is no extra input. This will likely hang or consume unexpected input, but more importantly, it doesn't affect the output string directly unless it blocks. However, the main issue is usually logic. Let's look closer at the output.
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