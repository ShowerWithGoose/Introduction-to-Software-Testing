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
            if(ifproper(str[i-1],str[i+1]) && str[i+1] > str[i-1]) // @@ [The condition does not check if the second character is greater than the first, which is required by the problem. Without this, cases like 'e-B' or equal characters might be incorrectly expanded.]
            {
                for(s=str[i-1]+1;s<=str[i+1]-1;s++) // @@ [The loop should include the character at str[i+1], but it stops at str[i+1]-1, so the last character of the range is missing. For example, a-d should output abcd, but this outputs abc.]
                {
                    printf("%c",s);
                }
            }
            else
            {
                printf("-"); // @@ [When expansion conditions are not met, the program should output the '-' and the next character as-is, but this only outputs '-', missing the next character (str[i+1]).]
                if (str[i+1] != 0) printf("%c", str[i+1]); // @@ [This line is missing in the original code; without it, the character after '-' is skipped entirely when not expanding.]
            }
            i++; 
        }
        else
        {
            printf("-"); // @@ [If '-' appears at the beginning of the string (i == 0), it should be printed as-is, but the current logic skips it because the 'else if(i>0)' block doesn't handle i==0. However, the original code doesn't have an else clause, so leading '-' is not printed at all.]
            i++;
        }
    }
    return 0;
}