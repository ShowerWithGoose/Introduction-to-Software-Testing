#include <stdio.h>
#include <string.h>
char s[100001];
int tag[100001];
void print(char a,char b,int i)
{
	if(!tag[i]) printf("%c",a);
	a++;
	while(a<=b)
	{
		printf("%c",a);
		a++;
	}
}
int main()
{
	char c;
	scanf("%s",s);
	int i,j,k,len=strlen(s);
	for(i=0;i<len;++i)
	{
		if(s[i+1]=='-' && i<(len-2))
		{
			if((s[i]>='a'&&s[i]<='z')&&(s[i+2]>='a'&&s[i+2]<='z'))
			{
				print(s[i],s[i+2],i);
				tag[i] = tag[i+1] = tag[i+2] = 1;
			}
			else if((s[i]>='A'&&s[i]<='Z')&&(s[i+2]>='A'&&s[i+2]<='Z'))
			{
				print(s[i],s[i+2],i);
				tag[i] = tag[i+1] = tag[i+2] = 1;
			}
			else if((s[i]>='0'&&s[i]<='9')&&(s[i+2]>='0'&&s[i+2]<='9'))
			{
				print(s[i],s[i+2],i);
				tag[i] = tag[i+1] = tag[i+2] = 1;
			}
			else
			{
				if(!tag[i]) printf("%c",s[i]);
			}
		}
		else
		{
			if(!tag[i]) printf("%c",s[i]);
		}
	}
	printf("\n");
	return 0;
}



