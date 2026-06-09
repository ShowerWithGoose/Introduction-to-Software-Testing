//1_2
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char s[105];
	scanf("%s",s);
	int po=-1,fi=-1,flag=1;
	for(int i=0;i<strlen(s)&&(fi==-1||po==-1);i++)
	{
		if(s[i]=='.') po=i;
		if(s[i]!='0'&&s[i]!='.'&&flag) fi=i,flag=0;
	}
	printf("%c",s[fi]);
	if(fi!=strlen(s)-1)printf(".");
	for(int i=fi+1;i<strlen(s);i++) if(s[i]!='.') printf("%c",s[i]);
	if(po>fi) fi++;
	printf("e%d\n",po-fi);
	return 0;
}


