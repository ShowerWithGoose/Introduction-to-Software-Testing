#include <stdio.h>
int expand_x(char s2[], char x, char y, int j)	//定义函数用以对三种情形扩展 
{
	int i;
	for(i = 1; i < y - x; i++)
		s2[j++] = x + i;
	return j;
}
int main()
{
	int N = 300, i, j;
	char s1[N], s2[N];
	fgets(s1, N, stdin);
	for(i = 0, j = 0; s1[i+2] != '\0'; i++)
	{
		s2[j++] = s1[i];
		if(s1[i+1] == '-')
		{
			if(s1[i] >= '0' && s1[i] < s1[i+2] && s1[i+2] <= '9')
			{
				j = expand_x(s2, s1[i], s1[i+2], j);
				i = i + 1;
				continue;
			}
			if(s1[i] >= 'a' && s1[i] < s1[i+2] && s1[i+2] <= 'z')
			{
				j = expand_x(s2, s1[i], s1[i+2], j);
				i = i + 1;
				continue;
			}
			if(s1[i] >= 'A' && s1[i] < s1[i+2] && s1[i+2] <= 'Z')
			{
				j = expand_x(s2, s1[i], s1[i+2], j);
				i = i + 1;
				continue;
			}
		}	//对可能出现的三种情形分别进行判断并处理 
	}
	s2[j++] = s1[i++];
	s2[j] = s1[i];
	fputs(s2, stdout);
	return 0; 
}

