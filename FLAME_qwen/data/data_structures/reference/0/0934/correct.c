#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s1[100002];
int main()
{
    char s[102];
    gets(s);
    int l = strlen(s),t=0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '-')
        {
            if (islower(s[i - 1]) && islower(s[i + 1]) && s[i - 1] < s[i + 1])
            {
                        for (int j = 1; j < s[i + 1] - s[i-1]; j++)
                        {
                                s1[t++] = s[i-1] + j;
                        }
            }
                
            else if (isdigit(s[i - 1]) && isdigit(s[i + 1]) && s[i - 1] < s[i + 1])
            {
                
                        for (int j = 1; j < s[i + 1] - s[i - 1]; j++)
                        {
                            
                                s1[t++] = s[i-1] + j;
                        }
               
            }
            else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1])
			{
            	for (int j = 1; j < s[i + 1] - s[i-1]; j++)
                        {
                            
                                s1[t++] = s[i-1] + j;
                        }
			}
            
            else s1[t++] = s[i];
        }
        else s1[t++] = s[i];

        
    }
    for (int i = 0; i < t; i++)
        printf("%c", s1[i]);
    return 0;
}

