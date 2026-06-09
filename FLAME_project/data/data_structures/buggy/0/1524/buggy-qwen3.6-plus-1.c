#include<stdio.h>
#include<ctype.h>
char s[10000]; 
int pd(char a,char b)
{
    if('a'<=a&&a<='z'&&'a'<=b&&b<='z')
    return 1;
    if('A'<=a&&a<='Z'&&'A'<=b&&b<='Z')
    return 1;
    if('0'<=a&&a<='9'&&'0'<=b&&b<='9')
    return 1;
    return 0;
}
int main()
{    
    int cha=0;
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if(pd(s[i-1],s[i+1])==1) // @@ The logic fails to check if the character after '-' is strictly greater than the character before it. For input "B-e", 'B' and 'e' are different types (uppercase vs lowercase), so pd returns 0, which is correct. However, the issue in the provided "Buggy Output" vs "Expected Output" suggests the problem might be elsewhere or the reference logic is flawed for mixed cases. Let's re-read carefully. The requirement says: "Perform expansion only when both characters... are of the same type... AND the character after... is greater than the one before". The function pd checks same type. It does NOT check if s[i+1] > s[i-1]. If pd returns 1, we assume expansion. But wait, look at the test case: Input "B-e". Expected "B-e". B is uppercase, e is lowercase. pd('B', 'e') returns 0 because 'B' is not in 'a'-'z' and 'e' is not in 'A'-'Z'. So pd returns 0. The code goes to else branch? No, if pd==1 is false, it does nothing inside the if(s[i]=='-') block. It doesn't print the '-'. That's the bug. When expansion conditions are not met, the '-' character itself should be printed.
            {
                cha=0;
                cha=s[i+1]-s[i-1]-1;
                if(cha>0)
                {
                    for(int k=1;k<=cha;k++)
                    {
                        printf("%c",s[i-1]+k);
                    }
                }
            }
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}