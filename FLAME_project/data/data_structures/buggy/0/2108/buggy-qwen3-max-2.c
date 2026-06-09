#include <stdio.h>
#include <string.h>
int ifproper(char c1,char c2)
{
    if(48<=c1&&c1<=57&&48<=c2&&c2<=57)
    {
        return 1;
    }
    else if(97<=c1&&c1<=122&&97<=c2&&c2<=122)
    {
        return 1;
    }
    else if(65<=c1&&c1<=90&&65<=c2&&c2<=90)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    char str[100],s;
    int i=0,j;
    gets(str);
    while(str[i]!=0)
    {
        if(str[i]!=45) 
        {
            s=str[i];
            printf("%c",s);
            i++;
        }
        else if(i>0)
        {
            if(ifproper(str[i-1],str[i+1]) && str[i+1] > str[i-1]) // @@ [The condition does not check if the second character is greater than the first, which is required by the problem. Without this, cases like 'e-B' or equal characters might be incorrectly expanded. However, in this specific test case B-e, the real issue is that B (uppercase) and e (lowercase) are different types, but ifproper returns 0, so expansion shouldn't happen. But the bigger issue is below:]
            {
                for(s=str[i-1]+1;s<=str[i+1]-1;s++) // @@ [The loop condition should be s <= str[i+1], not s <= str[i+1]-1. This causes the last character of the range to be omitted. However, in the test case B-e, since ifproper returns 0, this loop isn't entered. The actual bug causing "Be" instead of "B-e" is that when '-' is encountered and ifproper returns false, the code does NOT output the '-' and the next character properly.]
                {
                    printf("%c",s);
                }
            }
            else
            {
                printf("-%c", str[i+1]); // @@ [This else block is missing! The current code only handles the expansion case. When ifproper returns false, it skips outputting '-' and the following character, leading to omission of '-' and possibly the next char. In the test case "B-e", after printing 'B', it sees '-', checks ifproper('B','e') which returns 0, then just increments i without printing '-' or 'e', resulting in only "B" printed so far. But wait—the observed buggy output is "Be", meaning 'e' was printed later. Let's trace: i points to '-', enters else if(i>0), ifproper fails, so it does nothing except i++. Then next iteration, i now points to 'e', which is != '-', so it prints 'e'. So '-' is skipped entirely. Hence, the core error is that when a '-' is found but not expandable, the code must output '-' immediately, and then the next character will be handled normally—but in this logic, by skipping '-', and then later printing the next char as a normal char, you get "Be" instead of "B-e". The fix requires printing '-' in the non-expandable case.]
            }
            i++; 
        }
        else
        {
            printf("-"); // @@ [If '-' appears at the beginning (i==0), it should just be printed, but also the next character needs to be considered. However, the main issue remains the missing handling of non-expandable '-'.]
            i++;
        }
    }
    return 0;
}