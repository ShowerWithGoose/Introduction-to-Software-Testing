#include <stdio.h>
#include <string.h>
#define NUM 0
#define SUB 1
#define SUP 2
#define UKN 3
int ctype(char c);
void expand(const char *src, char *dst);
int main()
{
	char src[1024], dst[1024];
	
	memset(src, 0, sizeof(src));
	memset(dst, 0, sizeof(dst));
	gets(src);
	expand(src, dst);
	puts(dst);
	return 0;
}
int ctype(char c)
{
	if(c >= '0' && c <= '9') return NUM;
	if(c >= 'a' && c <= 'z') return SUB;
	if(c >= 'A' && c <= 'Z') return SUP;
	return UKN;
}
void expand(const char *src, char *dst)
{
	int i, j;
	char k;
	
	for (i = 0, j = 0; src[i] != '\0'; i++)
	{
		dst[j++] = src[i];
		if (src[i + 1] == '-' && ctype(src[i]) == ctype(src[i + 2]) && ctype(src[i]) != UKN)
		{
			for (k = src[i] + 1; k < src[i + 2]; k++) dst[j++] = k;
			i++;
		}
	}
	dst[j] = '\0';
}

