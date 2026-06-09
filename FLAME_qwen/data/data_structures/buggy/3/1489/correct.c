#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char n[105],m[105],p[105];
int main()
{
	int i = 0, j, e = -1;
	gets(n);
	if (n[i] == '0')
	{
		i += 2;
		for (; n[i] == '0'; i++);
		e = i - 1;
		m[0] = n[i++];
		m[1] = '.';
		for (j = 2; n[i] != NULL; i++,j++)
			m[j] = n[i];
		if (j == 2)
		{
			m[1] = 'e';
			m[2] = '-';
		}
		else
		{
			m[j] = 'e';
			m[j + 1] = '-';
		}
	}
	else 
	{
		m[0] = n[0];
		m[1] = '.';
		for (j = 2,i=1; n[i] != NULL; i++)
		{
			if(n[i]=='.')
				e = i-1;
			else
				m[j++] = n[i];			
		}
		if (j == 2)
			m[1] = 'e';
		else
			m[j] = 'e';
	}
	if (e == -1)
	{
		e = strlen(m)-2;
		if (e == 0)
			sprintf(p, "%d", e);
		else
		{
			sprintf(p, "%d", e-1);
			for (; m[e] == '0' || m[e] == '.'; e--);
			m[e + 1] = 'e';
			m[e + 2] = '\0';
		}
	}
	else
		sprintf(p, "%d", e);
	strcat(m, p);
	puts(m);
	return 0;
}
