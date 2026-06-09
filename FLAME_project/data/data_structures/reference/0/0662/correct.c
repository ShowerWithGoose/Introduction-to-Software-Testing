#include<stdio.h>
#include<string.h> 
char s[100000];
int flag;
void judge(int x) {
	int flag = 0, j;
	if (s[x-1]>='a'&&s[x-1]<='z'&&s[x+1]>='a'&&s[x+1]<='z'&&s[x+1]>s[x-1]) flag = 1;
	else if (s[x-1]>='A'&&s[x-1]<='Z'&&s[x+1]>='A'&&s[x+1]<='Z'&&s[x+1]>s[x-1]) flag = 1;
	else if (s[x-1]>='0'&&s[x-1]<='9'&&s[x+1]>='0'&&s[x+1]<='9'&&s[x+1]>s[x-1]) flag = 1;
	if (flag) {
		for (j = s[x-1]+1; j < s[x+1]; j++)
			printf("%c", j);
	}
	else printf("%c", '-');
	return ;
}
int main()
{
	scanf("%s", s+1);
	int i, j;
	for (i = 1; i <= strlen(s+1); i++) {
		if(s[i] == '-') judge(i);
		else printf("%c", s[i]);
	}
	return 0;
}



