#include<stdio.h>
void func(char x,char y);
int main()
{
	char s[10000];
	char x,y,z;
	int i;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		printf("%c",s[i]);
		if(s[i+1]!='-') continue;
		if(s[i]>='a'&&s[i]<s[i+2]&&s[i+2]<='z'||s[i]>='A'&&s[i]<s[i+2]&&s[i+2]<='Z'||s[i]>='0'&&s[i]<s[i+2]&&s[i+2]<='9')
		{
			func(s[i],s[i+2]);
			i++; 
		}
		
	}
	return 0;
}

void func(char x,char y)
{	
	int j;
	for(j=1;x+j<y;j++)
	{
		printf("%c",x+j);
	}
}


