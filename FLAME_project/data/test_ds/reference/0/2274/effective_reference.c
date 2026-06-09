#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s1[100002];
int main()
{
    char s[102];
    gets(s);
    int len = strlen(s),j=0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '-')
        {
            if (islower(s[i - 1]) && islower(s[i + 1]) && s[i - 1] < s[i + 1])
            {
                        for (int l = 1; l < s[i + 1] - s[i-1]; l++)
                        {
                                s1[j++] = s[i-1] + l;
                        }
            }
                
            else if (isdigit(s[i - 1]) && isdigit(s[i + 1]) && s[i - 1] < s[i + 1])
            {
                
                        for (int l = 1; l < s[i + 1] - s[i - 1]; l++)
                        {
                            
                                s1[j++] = s[i-1] + l;
                        }
               
            }
            else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1])
			{
            	for (int l = 1; l < s[i + 1] - s[i-1]; l++)
                        {
                            
                                s1[j++] = s[i-1] + l;
                        }
			}
            
            else s1[j++] = s[i];
        }
        else s1[j++] = s[i];

        
    }
    for (int i = 0; i < j; i++)
        printf("%c", s1[i]);
    return 0;
}

