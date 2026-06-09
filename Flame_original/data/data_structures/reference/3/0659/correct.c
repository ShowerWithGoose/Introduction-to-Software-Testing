#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[105];
int main()
{
	fgets(s, 104, stdin);
	int num = 0,start = 0, len = strlen(s);
	for(int i = 0;i<len-1;i++)
	{
		if(s[i] == '0')
			continue;
		if(s[i]!='0' && s[i]!= '.')
		{
			if(start!=0)
				continue;
			start = i + 1;
			if(s[0]=='0')
				start = i - 1;
		}
		if(s[i]=='.')
			num = i - 1;
	}
	
	if(s[0] == '0')
    {
        if (start + 2 >= len - 1)
            printf("%c", s[start + 1]);
        else
            printf("%c.", s[start + 1]);
        for (int i=start + 2; i < len - 1; i++)
        {
            printf("%c", s[i]);
        }
        printf("e-%d", abs(start - num));
    }
	if (s[0] != '0')
    {
        printf("%c.", s[start - 1]);
        for (int i = start; i < len - 1; i++)
        {
            if (s[i] == '.')
                continue;
            printf("%c", s[i]);
        }
        printf("e%d", abs(start - num - 1));
    }
    return 0;
}

