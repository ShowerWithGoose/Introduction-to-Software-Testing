#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char ch[110],in[110];
int len,pos1,pos2;
int main()
{
	gets(ch+1);
	len = strlen(ch+1);
	int ok=1;
	for(int i=1;i<=len;i++)
	{
		if(ch[i] == '.')
		{
			pos1 = i;
			continue;
		}
		if(ok)
		{
			if(ch[i] == '0') continue;
			ok=0;
			pos2=i;
			in[++in[0]] = ch[i]; 
		}
		else in[++in[0]] = ch[i];
	}
	int e = pos1 - pos2;
	if(e > 0) e--;
	printf("%c",in[1]);
	if(in[0] > 1) printf(".");
	for(int i=2;i<=in[0];i++) printf("%c",in[i]);
	printf("e%d",e);
	return 0;
}

