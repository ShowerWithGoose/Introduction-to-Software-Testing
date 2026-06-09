#include <stdio.h>
#include <string.h>
#include <ctype.h>

int l ,pos=0;
char s[1000000];
int que[100000],q_pos = 0;
int sta[100000], s_pos = 0;

void push()
{
	que[++q_pos] = sta[s_pos--]-1000;
}

int main()
{
	int i,j,k,l;
	gets(s);
	l = strlen(s);
	for(i = 0; i < l; i++)
	{
		if(isdigit(s[i]))
		{
			int cur = 0;
			while(isdigit(s[i]))
				cur = cur*10+s[i]-'0',i++;
			que[++q_pos] = cur;
		}
		char c = s[i];
		if(c=='+'||c=='-')
		{
			while(s_pos >= 1)
				push();
			sta[++s_pos] = c;
		}
		if(c=='*'||c=='/')
		{
			while(s_pos >= 1 && (sta[s_pos]=='*' || sta[s_pos]=='/'))
				push();
			sta[++s_pos] = c;
		}
	}
	while(s_pos >= 1)
		push();
	
	for(i = 1; i <= q_pos; i++)
	{
		if(que[i] < 0)
		{
			char c = que[i]+1000;
			if(c == '+')
				sta[s_pos-1] += sta[s_pos]; 
			if(c == '-')
				sta[s_pos-1] -= sta[s_pos]; 
			if(c == '*')
				sta[s_pos-1] *= sta[s_pos]; 
			if(c == '/')
				sta[s_pos-1] /= sta[s_pos]; 
			s_pos--;
		}
		else
		{
			sta[++s_pos] = que[i];
		}
	}
	
	for(i = 1; i <= s_pos; i++)
		printf("%d ", sta[i]);
	
//	for(i = 1; i <= q_pos; i++)
//		printf("%d ", que[i]);
	

	
	

	return 0;
} 


