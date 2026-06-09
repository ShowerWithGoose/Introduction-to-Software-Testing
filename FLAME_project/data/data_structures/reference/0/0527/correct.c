#include<stdio.h>
#include<string.h>
int main()
{
	char c[100];
	char ch;
	scanf("%s",&c);
	int i=0,j=0;
	while(i<strlen(c))
	{ 
		if(c[i]=='-')
		{
			if(c[i-1]>='a'&&c[i-1]<='z'&&c[i-1]<c[i+1]&&c[i+1]<='z'&&c[i+1]>='a')
			{
				for(ch=c[i-1]+1;ch<c[i+1];ch++)
				{
					printf("%c",ch);
				}
			}
			else if(c[i-1]>='0'&&c[i-1]<='9'&&c[i+1]>='0'&&c[i-1]<c[i+1]&&c[i+1]<='9')
			{
				for(ch=c[i-1]+1;ch<c[i+1];ch++)
				{
					printf("%c",ch);
				}
			}
			else if(c[i-1]>='A'&&c[i-1]<='Z'&&c[i+1]>='A'&&c[i-1]<c[i+1]&&c[i+1]<='Z')
			{
				for(ch=c[i-1]+1;ch<c[i+1];ch++)
				{
					printf("%c",ch);
				}
			}
			else printf("%c",c[i]);
		}
		else printf("%c",c[i]);
		i++;	
	}
	return 0;
}



