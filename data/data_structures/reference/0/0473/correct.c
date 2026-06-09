#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char ch[1000010];
int len;
int ok(int i)
{
	if(ch[i] != '-') return 0;
	if(i == 1 || i == len) return 0;
	if(ch[i-1] >= ch[i+1]) return 0;
	if(ch[i-1] >= 'a' && ch[i-1] <= 'z')
	{
		if(ch[i+1] >= 'a' && ch[i+1] <= 'z') return 1;
		return 0;
	}
	else if(ch[i-1] >= 'A' && ch[i-1] <= 'Z')
	{
		if(ch[i+1] >= 'A' && ch[i+1] <= 'Z') return 1;
		return 0;
	}
	else if(ch[i-1] >= '0' && ch[i-1] <= '9')
	{
		if(ch[i+1] >= '0' && ch[i+1] <= '9') return 1;
		return 0;
	}
	else return 0;
}
int main()
{
	scanf("%s",ch+1);
	len=strlen(ch+1);
	for(int i=1;i<=len;i++)
	{
		if(!ok(i)) 
		{
			printf("%c",ch[i]);
			continue;
		}
		
		for(int j=ch[i-1]+1;j<=ch[i+1]-1;j++) printf("%c",j);
		
	}
	return 0;
}

