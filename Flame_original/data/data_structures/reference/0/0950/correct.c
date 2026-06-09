#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
int main()
{
	char org[1000], out[1000];
	scanf("%s", org);
	int i, j;
	for(i = 0, j = 0; org[i] != '\0'; i++, j++)
	{
		if(org[i] == '-' && org[i - 1] < org[i + 1])
		{
			int flag = 0;
			if(isdigit(org[i - 1]) && isdigit(org[i + 1]))
				flag = 1;
			else if(islower(org[i - 1]) && islower(org[i + 1]))
				flag = 1;
			else if(isupper(org[i - 1]) && isupper(org[i + 1]))
				flag = 1;
			if(flag)
			{
				int rec = org[i - 1] + 1;
				for(; rec < org[i + 1]; j++)
					out[j] = rec++;
				i++;
			}
		}
		out[j] = org[i];
	}
	out[j] = '\0';
	puts(out);
	return 0;
}


