#include<stdio.h>
#include<string.h>
int main()
{
	char s[100005];
	gets(s);
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i+1]!='-'&&s[i]!='-')
		printf("%c",s[i]);
		else if(s[i+1]=='-'&&s[i]!='-')
				if(((i+1)!=0)&&((i+1)!=strlen(s)-1))
				{
					if((s[i]>='a'&&'z'>=s[i])&&(s[i+2]>='a'&&'z'>=s[i+2])&&s[i]<s[i+2])
					{
						int j,k;
						for(j=s[i],k=s[i+2];j<k;j++)
						printf("%c",j);
					}
					else if((s[i]>='A'&&'Z'>=s[i])&&(s[i+2]>='A'&&'Z'>=s[i+2])&&s[i]<s[i+2])
					{
						int j,k;
						for(j=s[i],k=s[i+2];j<k;j++)
						printf("%c",j);
					}
					else if((s[i]>='0'&&'9'>=s[i])&&(s[i+2]>='0'&&'9'>=s[i+2])&&s[i]<s[i+2])
					{
						int j,k;
						for(j=s[i],k=s[i+2];j<k;j++)
						printf("%c",j);
					}
					else 
					printf("%c%c",s[i],s[i+1]);
				}
		
	}
	return 0;
}

