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
                for(s=str[i-1]+1;s<=str[i+1]-1;s++) // @@ [The loop should go up to str[i+1], not str[i+1]-1. This causes the last character of the range to be omitted. For example, a-d becomes abc instead of abcd.]
                {
                    printf("%c",s);
                }
            }
            else
            {
                printf("-"); // @@ [When expansion conditions are not met, the program must output the '-' and the next character. However, this else block is missing; the current code skips printing '-' and the following character in non-expansion cases.]
                printf("%c", str[i+1]);
            }
            i++; 
        }
        else
        {
            printf("-"); // @@ [If '-' appears at the beginning (i == 0), it should be printed as-is, but the current code skips it because the else-if(i>0) doesn't handle i==0.]
            i++;
        }
    }
    return 0;
}