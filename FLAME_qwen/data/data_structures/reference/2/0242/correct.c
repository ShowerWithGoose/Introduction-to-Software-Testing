#include<stdio.h>
#include<string.h>
char s[999], mark[999], count[999];
int num[999], m = 0, ja, marknum[999], result;
void deleter(char s[]) {
	int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ')
			s[j++] = s[i];
	}
	s[j] = '\0';
}
int atoi(char s[]) {
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
int main() {
	gets(s);
	deleter(s);
	for (int i = 0, j = 0, k = 0; s[i] != '\0'; i++) { //记录数字，记录符号
		if (s[i] == '+') {
			mark[j++] = '+';
			k = 0;
			num[m++] = atoi(count);
			for (int l = 0; count[l] != '\0'; l++) {
				count[l] = '\0';
			}
		} else if (s[i] == '-') {
			mark[j++] = '-';
			k = 0;
			num[m++] = atoi(count);
			for (int l = 0; count[l] != '\0'; l++) {
				count[l] = '\0';
			}
		} else if (s[i] == '*') {
			mark[j++] = '*';
			k = 0;
			num[m++] = atoi(count);
			for (int l = 0; count[l] != '\0'; l++) {
				count[l] = '\0';
			}
		} else if (s[i] == '/') {
			mark[j++] = '/';
			k = 0;
			num[m++] = atoi(count);
			for (int l = 0; count[l] != '\0'; l++) {
				count[l] = '\0';
			}
		} else if (s[i] == '=') {
			mark[j++]='=';
			k = 0;
			num[m++] = atoi(count);
		} else {
			count[k++] = s[i];
		}
	}
	for (int i = 0; mark[i] != '\0'; i++) { //对应符号和数字,乘除先行
		if (mark[i] == '*'||mark[i]=='/') {
			for (ja = 1; mark[i + ja] == '*'||mark[i + ja] == '/'; ja++);
			marknum[i]=num[i];
			for (int j = 0; j <= ja; j++) {
				if(mark[i+j]=='*')
				marknum[i] *= num[i + j+1];
				
			}
			for(int j=0;j<=ja;j++)
			{
				if(mark[i+j]=='/')
				marknum[i]/=num[i+j+1];

			}
			for (int j = 1; j <= ja; j++) {
				num[i + j] = 0;
			}
			i+=ja-1;
		}  else if (mark[i] == '+') {
			marknum[i] = num[i];
		} else if (mark[i] == '-') {
			marknum[i] = num[i];
		}
		else if(mark[i]=='=')
		{
			marknum[i]=num[i];
		}
	}
	result=marknum[0];
	for(int i=0;mark[i]!='=';i++)
	{
		if(mark[i]=='-')
		{
			result-=marknum[i+1];
		}
		else if(mark[i]=='+')
		{
			result+=marknum[i+1];
		}
	}
/*	for(int q=0;q<m;q++)
			{
			    printf("%d  ",num[q]);
				printf("%c\n",mark[q]);
			}
*/
     printf("%d",result);
}




