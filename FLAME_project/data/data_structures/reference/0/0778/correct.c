#include <stdio.h>
#include <string.h>
char ch[1005];
int main()
{
	scanf("%s",ch);
	int len=strlen(ch);
	for(int i=0;i<len;i++)
	{
		if(i+2<=len-1&&ch[i+1]=='-')//i是起始 
		{
			int mark=i; //mark是要扩展的字符串末尾 
			while(mark+2<=len-1&&ch[mark+1]=='-')
			{
				if(ch[mark]<ch[mark+2]&&((ch[mark]>=48&&ch[mark+2]<=57)||(ch[mark]>=65&&ch[mark+2]<=90)||(ch[mark]>=97&&ch[mark+2]<=122)))
				mark=mark+2;
				else
				break; 
			}
			if(mark==i)
			printf("%c",ch[i]);
			else
			{
				for(int j=ch[i];j<=ch[mark];j++)
				printf("%c",j);
				i=mark;
			}
		}
		else
		printf("%c",ch[i]);
	}
	return 0;
}

