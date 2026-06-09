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
            if(ifproper(str[i-1],str[i+1]) && str[i+1] > str[i-1]) // @@ The original code only checks if characters are of the same type, but fails to check if the end character is greater than the start character. For "B-e", 'B' and 'e' are not the same type, so ifproper returns 0, which is correct. However, looking at the provided buggy output "Be" for input "B-e", it seems the logic for handling the hyphen and subsequent characters is flawed in a different way or the provided "Buggy Output" implies the hyphen was skipped but expansion didn't happen correctly? Wait. If input is B-e: str[0]='B', str[1]='-', str[2]='e'. i=0: prints 'B'. i=1: is '-'. i>0 is true. ifproper('B', 'e') checks if both are upper, both lower, or both digit. 'B' is upper, 'e' is lower. Returns 0. So the if block is skipped. Then i++ makes i=2. Loop continues. i=2: 'e' is not '-', prints 'e'. Output "Be". The expected output is "B-e". The error is that when expansion conditions are NOT met (either wrong type or end <= start), the hyphen and the following character should still be printed. The current code simply skips the hyphen processing block entirely without printing the hyphen or advancing past the next character correctly in the "else" case of the expansion check. Specifically, if `ifproper` is false, it does nothing, then increments `i`. This consumes the '-' but doesn't print it, and the next iteration prints the char after '-'. It needs to print '-' and the next char if expansion is invalid.
            {
                for(s=str[i-1]+1;s<=str[i+1]-1;s++)
                {
                    printf("%c",s);
                }
            }
            else // @@ Missing else block to handle cases where expansion is not performed. In these cases, the '-' and the following character must be output unchanged.
            {
                printf("-%c", str[i+1]);
            }
            i++; 
        }
        else // @@ Missing handling for when '-' is the first character (i==0). Though problem says input contains expansion symbol, usually implies valid format, but robustness suggests handling. More importantly, the loop structure `i++` inside the `else if(i>0)` block combined with the outer `while` might skip characters or fail to print the hyphen if not handled.
        {
             printf("%c", str[i]);
             i++;
        }
    }
    return 0;
}