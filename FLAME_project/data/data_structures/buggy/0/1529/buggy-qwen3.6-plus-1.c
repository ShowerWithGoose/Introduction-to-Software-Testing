#include <stdio.h>
#include <string.h>
char s[]={}; // @@ The array size is 0, which leads to undefined behavior when writing input data. It should be large enough to hold the input string, e.g., char s[1000];
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
            else // @@ Missing else block to print the '-' character when expansion conditions are not met (e.g., different types like 'B' and 'e', or invalid range). Without this, the '-' is silently dropped.
            {
                printf("-");
            }
        }
    }
    return 0;    
}