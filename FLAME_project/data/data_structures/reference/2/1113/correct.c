#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
char figure[100];
char character1[100];
int number[100];
int changenum(int start, int end) {//将字符转为数字
	int sum = 0, c = 1;
	int cnt = end - start;
	for (int i = 0; i <= cnt; i++) {
		sum = sum + (figure[end - i]-'0') * c;
		c = c * 10;
	}
	return sum;
}
int PlusAndDiv(int s,int e) {
	int anwser; int flag3 = s;
	for (; figure[s] != '*' && figure[s] != '/'&&s<=e; s++);
	anwser = changenum(flag3, s - 1); flag3 = s; s++;
	while (s <= e) {
		for (; figure[s] != '*' && figure[s] != '/' && s <= e; s++);
		if (figure[flag3] == '*') anwser = anwser * changenum(flag3+1, s - 1), flag3 = s ;
		else if (figure[flag3] == '/') anwser = anwser / changenum(flag3+1, s - 1), flag3 = s;
		s++;
	}
	return anwser;
}
void killblank(char *ch) {

	char* c;//指向字符串的字符处
	while (*ch != ' ')
	{
		if (*ch == '\0')
		{
			//字符串中没有空格,直接返回
			return;
		}
		ch++;
	}//将blank指针指向第一个空格位置
	//让c指针指向出现空格后的第一个字符串
	c = ch + 1;
	while (c == ' ')
	{
		c++;
	}
	while (*c != '\0')
	{
		if (*c != ' ')
		{
			//将空格换为后面出现的字符，换过去的字符置为空格
			*ch = *c;
			*c = ' ';
			ch++;
		}
		c++;
	}
	*ch = '\0';
	return;
}
int main()
{
	gets(figure);
	killblank(figure);
	int i = 0; int answer = 0; int flag1 = 0; int flag2 = 0; int cnt = 0;
	while (figure[i] != '=') {
		for (; figure[i] != '+' && figure[i] != '-'&&figure[i]!='='; i++);
		character1[flag2++] = figure[i];
		number[cnt++] = PlusAndDiv(flag1, i - 1);
		flag1 = i + 1;
		if (figure[i] != '=') i++;
	}
	answer = number[0];
	for (int j = 0; j < cnt; j++) {
		if (character1[j] == '+') answer = answer + number[1 + j];
		else if (character1[j] == '-') answer = answer - number[1 + j];
	}
	printf("%d", answer);
	return 0;
}


