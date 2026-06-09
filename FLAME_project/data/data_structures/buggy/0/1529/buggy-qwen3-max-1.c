#include <stdio.h>
#include <string.h>
char s[]={}; // @@ [The array s is declared with empty initializer, which results in zero size. This leads to undefined behavior when reading input via scanf("%s", s). It should be declared with a fixed size, e.g., char s[1000];]

int main()
{
    scanf("%s", s);
    int y=strlen(s);
    for(int i=0; i<y; i++)
    {
        if(s[i]!='-')
        {
            printf("%c", s[i]);
        }
        if(s[i]=='-')
        {
            if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++)
                {
                    printf("%c", s[i-1]+j);
                }
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++)
                {
                    printf("%c", s[i-1]+j);
                }
            }
            else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++)
                {
                    printf("%c", s[i-1]+j);
                }
            }
            else
            {
                printf("-"); // @@ [When the '-' does not meet expansion conditions (e.g., B-e), the program fails to output the '-' because there's no else clause printing it. The reference program includes an else block that prints '-', but this code omits it, causing '-' to be skipped entirely in such cases.]
            }
        }
    }
    return 0;    
}