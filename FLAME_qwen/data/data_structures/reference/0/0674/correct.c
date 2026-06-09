#include <stdio.h>
int main( )
{
	char a[100];
	char b[100];
	int j = 0;
	scanf("%s", a);
	for (int i = 0; a[i]!= '\0'; ++i)
	{
		if (a[i+1]!='-')
			b[j++] = a[i];
		else
		{
			if (a[i]>='0'&&a[i]<='9'&&a[i+2]>='0'&&a[i+2]<='9')
			{
				for (char c = a[i]; c < a[i+2]; ++c)
				{
					b[j++] = c;
				}
				i++;
			}
			else if (a[i]>='a'&&a[i]<='z'&&a[i+2]>='a'&&a[i+2]<='z')
			{
				for (char c = a[i]; c < a[i+2]; ++c)
				{
					b[j++] = c;
				}
				i++;
			}
			else if (a[i]>='A'&&a[i]<='Z'&&a[i+2]>='A'&&a[i+2]<='Z')
			{
				for (char c = a[i]; c < a[i+2]; ++c)
				{
					b[j++] = c;
				}
				i++;
			}
			else
			{
				b[j++] = a[i];
			}
		}
	}
	b[j] = '\0';
	printf("%s\n", b);
	return 0;
}
