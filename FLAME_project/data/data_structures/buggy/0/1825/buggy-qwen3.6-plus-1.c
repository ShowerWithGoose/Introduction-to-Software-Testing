#include <stdio.h>
int main()
{
    char s[1000]={0};
    int i=0;
    while(scanf("%c",&s[i])!=EOF)
    {
        i++;
    }
    int j;
    for(j=0;j<=i;j++)
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ The condition checks if the next character is within the valid range (e.g., <= '9'), but fails to check if the previous character is also within that same specific range (e.g., >= '0'). For example, in "a-u", 'a' is not >= '0', so the first part fails correctly, but logic relies on short-circuiting or specific ordering. More critically, the condition `s[j-1]>='0' && s[j+1]<='9'` allows cases like '0'-'z' if not carefully bounded by type. However, the main issue here is likely logical redundancy or missing strict type matching. Actually, looking at the failed case `a-uB-F`, the output `abcdefghijklmnopqrstuuBCDEFF` suggests double printing. Let's look closer. The loop prints `s[j]` if it's not '-'. If it is '-', it checks expansion. If expanded, it prints the middle chars. It does NOT print the start char `s[j-1]` inside the expansion block, but `s[j-1]` was already printed in the previous iteration of the loop because `s[j-1]` is not '-'. This is correct. Wait, the expected output for `a-u` is `abcdefghijklmnopqrstu`. The code prints `a` (when j points to a), then when j points to `-`, it prints `b` through `u`. This results in `a...u`. This seems correct for the first part. Why `uu`? Ah, when j points to `u` (the char after `-`), `s[j]` is `u`, which is not `-`, so it prints `u` again. The expansion logic prints up to `s[j+1]` (which is `u`). Then the loop continues to `j+1` (which is `u`) and prints it again. So the end character of the expansion is printed twice: once by the expansion loop, and once by the main loop when it processes that character.
            {
                int n=1;
                while(s[j-1]+n<=s[j+1])
                {
                    printf("%c",s[j-1]+n);
                    n++;
                }
            }
            else
            printf("%c",s[j]);
        }
    }
    return 0;
}