#include <stdio.h>
#include <string.h>
int cal(char s[]) 
{
	int i=0,res = 0, fres = 1, num = 0;
	char top = '+', fop = '*';
	while(s[i]!='=') 
	{
		if (s[i] == ' ') 
		{
			i++;
			continue;
		}
		if (isdigit(s[i])) 
		{
			num = num * 10 + (s[i] - '0');
		} 
		else 
		{
			if (s[i] == '+' || s[i] == '-') 
			{
				fres = fop == '*' ? fres * num : fres / num;
				res = top == '+' ? res + fres : res - fres;
				top = s[i];
				fres = 1;
				fop = '*';
			}
			else
			{
				fres = fop == '*' ? fres * num : fres / num;
				fop = s[i];
			}
			num = 0;
		}
		i++;
	}
	fres = fop == '*' ? fres * num : fres / num;
	res = top == '+' ? res + fres :res - fres;
	return res;
}
int main()
{
	char s[100005];
	gets(s);
	printf("%d",cal(s));
}

