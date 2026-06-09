#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[110];
int main()
{
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers]
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
                            printf("%ce-%d",s[j],j-1);
                            break; // @@ [Missing 'break' causes multiple outputs if more non-zero digits follow]
                        }
                    }
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
        }
    }
    return 0;
}