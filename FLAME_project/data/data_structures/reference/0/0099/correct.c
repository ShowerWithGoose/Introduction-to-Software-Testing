#include<stdio.h>
#include<string.h>
char str[1000100];
int main()
{
	scanf("%s",&str);
	int l=strlen(str),i,j;
	for(i=0;i<l;i++)
	{
		if(str[i]=='-'&&i+1<l)
			{
				if(str[i-1]<='z'&&str[i-1]>='a')
					{
					if(str[i+1]<='z'&&str[i+1]>='a'&&str[i+1]>str[i-1])
							{
						for( j=str[i-1]-'a'+1;j<str[i+1]-'a';j++)
									{
										printf("%c",j+'a');
									}
							}
						else
						printf("-");
					}
				if(str[i-1]<='Z'&&str[i-1]>='A')
					{
						if(str[i+1]<='Z'&&str[i+1]>='A'&&str[i+1]>str[i-1])
							{
								for( j=str[i-1]-'a'+1;j<str[i+1]-'a';j++)
									{
										printf("%c",j+'a');
									}
							}
						else printf("-");
					}
				if(str[i-1]<='9'&&str[i-1]>='0')
					{
						if(str[i+1]<='9'&&str[i+1]>='0'&&str[i+1]>str[i-1])
						{
							for( j=str[i-1]-'a'+1;j<str[i+1]-'a';j++)
									{
										printf("%c",j+'a');
									}
						}
						else printf("-");
					}
			}
		else
		printf("%c",str[i]);
	}
}

