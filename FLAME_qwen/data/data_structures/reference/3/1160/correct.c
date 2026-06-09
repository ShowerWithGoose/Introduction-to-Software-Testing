#include <stdio.h>
#include <string.h>

int main()
{
	char in[1000];
	char ou[1000] = {'\0'};
	gets(in);
	int len = strlen(in);
	int i = 0;
	int j = 0;
	int e = -1;
	if (in[i] == '-')
	{
		ou[0] = '-';
		i++;
		j++;
	}
	int flag = 0;			// tells if it's 0.xxx
	if (in[i] == '0')
	{
		i++;
		flag = 1;
	}
	else
	{
		ou[j] = in[i];
		i++;
		e++;
		ou[j + 1] = '.';
		j += 2;
		while (in[i] != '.')
		{
			ou[j] = in[i];
			i++;
			j++;
			e++;
		}
	}
	i++;
	switch (flag)
	{
	case 0:
		while (i < len)
		{
			ou[j] = in[i];
			i++;
			j++;
		}
		break;
	case 1:
		while (in[i] == '0')
		{
			i++;
			e--;
		}
		ou[j] = in[i];
		i++;
		j++;
		if (i < len)
		{
			ou[j] = '.';
			j++;
		}
		while (i < len)
		{
			ou[j] = in[i];
			i++;
			j++;
		}
	default:
		break;
	}
	printf("%se%d",ou,e);
	
	

	return 0;
}


