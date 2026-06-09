#include<stdio.h>
#include<string.h>
int main()
{
	char s[100000];
	int n;
	gets(s);
	for (int i=0,j=0;i<strlen(s);i++)
	{
		if (s[i]!='-'&&s[i+1]!='-')
			printf("%c",s[i]);
		else
		{
			if ((s[i]>='a'&&s[i]<='z')&&(s[i+2]>='a'&&s[i+2]<='z')&&(s[i]<s[i+2]))
				{
					for(n=s[i+2]-s[i],j=0;n>0;n--,j++)
						printf("%c",s[i]+j);
						i++;
				
				}
			else if ((s[i]>='0'&&s[i]<='9')&&(s[i+2]>='0'&&s[i+2]<='9')&&(s[i]<s[i+2]))
							{
								for(n=s[i+2]-s[i],j=0;n>0;n--,j++)
									printf("%c",s[i]+j);
								i++;
							
							}
			else if ((s[i]>='A'&&s[i]<='Z')&&(s[i+2]>='A'&&s[i+2]<='Z')&&(s[i]<s[i+2]))
							{
								for(n=s[i+2]-s[i],j=0;n>0;n--,j++)
									printf("%c",s[i]+j);
								i++;}
			else
			    printf("%c",s[i]);
							
							}
		}
	return 0;
}



