#include<stdio.h>
#include<string.h>
int main()
{
	char ch[10000];
	int i,j,len;
	gets(ch);
	len=strlen(ch);
	for(i=0;i<len;i++)
	{
		if(ch[i]=='-')
		{
			if((ch[i-1]>='A' && ch[i-1]<='Z' && ch[i+1]>='A' && ch[i+1]<='Z')||(ch[i-1]>='a' && ch[i-1]<='z' && ch[i+1]>='a' && ch[i+1]<='z')||(ch[i-1]>='0' && ch[i-1]<='9' && ch[i+1]>='0' && ch[i+1]<='9'))
			{
				if(ch[i-1]<ch[i+1])
				{
					for(j=1;j<(ch[i+1]-ch[i-1]);j++)
					{
						printf("%c",ch[i-1]+j);
					}
				}
				else printf("%c",ch[i]);
			}
			else printf("%c",ch[i]);
		}
		else printf("%c",ch[i]);
	}
	return 0;
}



