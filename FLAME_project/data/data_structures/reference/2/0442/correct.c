#include <stdio.h>
#include <string.h>
#define ll long long
int a[1001];char b[1001];int topa=0,topb=0;
int op[256];
int main ()
{
	op['-'] = op['+'] = 1;
	op['*'] = op['/'] = 2;
	char ss[1001];
	char s[1001];
	gets(ss);
	int i,j;
	for( i=0,j=0;i<strlen(ss);i++)
	{
		if(ss[i] != ' ') s[j++] =ss[i];
	}
	s[j] = '\0';
	int p=0;
//	int top =0;
	int sum = 0;
	while(s[p]!='=')
	{
		if(s[p] <='9'&&s[p] >='0')
		{
			int num = 0;
			while(s[p]<= '9' && s[p] >='0')
			{
				num = num*10 + s[p] - '0';
				p++;
			}
			a[topa++] = num;
		}
		else{
			b[topb++] = s[p++];
		}
		if (op[b[topb-1]] ==2)
		{
			int num = 0;
			while(s[p]<= '9' && s[p] >='0')
			{
				num = num*10 + s[p] - '0';
				p++;
			}
			if (b[topb-1] == '*')
			a[topa-1] *= num;
			if (b[topb-1] == '/')
			a[topa-1] /= num;
			b[--topb] ='\0';
		} 
	}
	sum = a[0];
	int ii = 1;
	int jj=0;
	while (ii < topa && jj <topb)
	{
		char o = b[jj++];
		if (o == '+')
		sum = a[ii] + sum;
		else if(o == '-')
		sum = sum - a[ii];
		ii++;
	}
	printf("%d",sum);
}

