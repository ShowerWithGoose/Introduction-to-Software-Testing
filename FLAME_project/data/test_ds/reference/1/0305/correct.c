#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define PI 3.14159265
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
char ch[10005];
int main()
{
	int i,len;
	scanf("%s",ch);
	len=strlen(ch);
	printf("%c",ch[0]);
	for(i=1;i<len-1;i++)
	{
		if(ch[i]!='-')
		printf("%c",ch[i]);
		else if((ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i+1]-ch[i-1]>0)||(ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i+1]-ch[i-1]>0)||(ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i+1]-ch[i-1]>0))
		{
			ch[i]=ch[i-1]+1;
		while(ch[i]!=ch[i+1])
			{
				printf("%c",ch[i]);
				ch[i]++;
			}
		}
		else
		printf("-");
	}
	printf("%c",ch[len-1]);
	return 0;
}

