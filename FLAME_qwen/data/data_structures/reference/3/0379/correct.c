#include <stdlib.h>
#include<stdio.h>
#include <string.h>
char str[105];
int i; 
int main()
{
    fgets(str, 104, stdin);
    int spot= 0, numb= 0;
    for (i = 0; i < strlen(str) - 1; i++)
    {
        if(str[i]=='0')
        	continue;
        
		if (str[i] != '0' && str[i] != '.')
        {
            if(numb!=0)
            	continue; 
            
			numb = i + 1;
            if (str[0] == '0')
                numb = i - 1;
        }
        if (str[i] == '.')
            spot = i - 1;
    }
    if (str[0] == '0')
    {
        if (numb >= strlen(str) - 3)
            printf("%c", str[numb + 1]);
        else
            printf("%c.", str[numb + 1]);
        for (i = numb + 2; i < strlen(str) - 1; i++)
        {
            printf("%c", str[i]);
        }
        printf("e-%d", abs(numb - spot));
    }
  
    else
    {
        printf("%c.", str[numb - 1]);
        for (i = numb; i < strlen(str) - 1; i++)
        {
            if (str[i] == '.')
                continue;
            printf("%c", str[i]);
        }
        printf("e%d", abs(numb - spot - 1));
    }
    return 0;
}

