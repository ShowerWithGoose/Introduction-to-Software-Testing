#include <stdio.h>
#include <string.h>
#define NUM 0
#define SUB 1
#define SUP 2
#define UKN 3
int ctype(char c);
void expand(const char *src, char *dest);
int main()
{
	char src[1024], dest[1024];
	
	memset(src, 0, sizeof(src));
	memset(dest, 0, sizeof(dest));
	gets(src);
	expand(src, dest);
	puts(dest);
	return 0;
}
int ctype(char c)
{
	if(c >= '0' && c <= '9') return NUM;
	if(c >= 'a' && c <= 'z') return SUB;
	if(c >= 'A' && c <= 'Z') return SUP;
	return UKN;
}
void expand(const char *src, char *dest)
{
	int i, j;
	char ch;
	
	for (i = 0, j = 0; src[i] != '\0'; i++)
	{
		dest[j++] = src[i];
		if (src[i + 1] == '-' && ctype(src[i]) == ctype(src[i + 2]) && ctype(src[i]) != UKN)
		{
			for (ch = src[i] + 1; ch < src[i + 2]; ch++) dest[j++] = ch;
			i++;
		}
	}
	dest[j] = '\0';
}

