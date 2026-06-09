/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
void printExp(char a, char b), move(), endl();
int i = 0, j = 0;
char s[3], c, d;
int main()
{
	while (~scanf("%c", &c))
	{
		if (c == '\n')
		{
			endl();
			i = 0;
			continue;
		}
		s[i] = c;
		if (i < 2)
		{
			i++;
			continue;
		}
		if (s[1] == '-' && s[0] < s[2])
			if (s[0] >= 'a' && s[0] < 'z' && s[2] > 'a' && s[2] <= 'z')
				printExp(s[0], s[2]);
			else if (s[0] >= 'A' && s[0] < 'Z' && s[2]>'A' && s[2] <= 'Z')
				printExp(s[0], s[2]);
			else if (s[0] >= '0' && s[0] < '9' && s[2] > '0' && s[2] <= '9')
				printExp(s[0], s[2]);
			else
				move();
		else
			move();
	}
	endl();
	return 0;
}
void printExp(char a, char b)
{
	while (a < b)
		printf("%c", a++);
	s[0] = s[2];
	s[1] = s[2] = '\0';
	i = 1;
	return;
}
void move()
{
	printf("%c", s[0]);
	s[0] = s[1];
	s[1] = s[2];
	s[2] = '\0';
}
void endl()
{
	printf("%c%c\n", s[0], s[1]);
	s[0] = s[1] = s[2] = '\0';
}



