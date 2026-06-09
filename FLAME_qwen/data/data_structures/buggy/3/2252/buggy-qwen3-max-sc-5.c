#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    int j;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')
        {
            if(i==1)
            {
                if(s[i-1]=='0')
                {
                    for (j=i+1;s[j]!='\0';j++)
                    {
                        if(s[j]!='0')
                        {
                            printf("%ce-%d",s[j],j-1); // @@ [Missing handling for digits after the first non-zero digit; also, loop continues printing multiple times instead of breaking after first non-zero]
                            break; // @@ [Missing break causes multiple outputs if more non-zero digits exist]
                        }
                    }
                    // @@ [No output if all digits after decimal are zero, leading to no output in some cases]
                }
                else if(s[i-1]!='0')
                {
                    printf("%se0",s);
                }
            }
            else if(i>1)
            {
                printf("%c.",s[0]);
                for (int p=1;s[p]!='\0';p++)
                {
                    if(s[p]=='.')
                    {
                        continue;
                    }
                    else
                    {
                        printf("%c",s[p]);
                    }
                }
                printf("e%d",i-1);
            }
            return 0; // @@ [Missing return after handling '.'; without it, if input has no '.', nothing is printed and program falls through]
        }
    }
    // @@ [If input has no decimal point (though problem says it does), this code prints nothing]
    return 0;
}