#include<stdio.h>
#include<string.h>
int main()
{
	char s[1010],a;
	scanf("%s", s);
	int len,i;
	len=strlen(s);
	for(i=0;i<len;i++){
		if(i==len-2||i==len-1)
			printf("%c", s[i]);
		else
		{
			if((s[i]>='a'&&s[i]<='z')&&s[i+1]=='-'&&(s[i+2]>='a'&&s[i+2]<='z')&&s[i]<s[i+2])
			{
				printf("%c",s[i]);
				for(a=s[i]+1;a<=s[i+2]-1;a++)
					printf("%c",a);
				i+=1;
			}
			else if((s[i]>='A'&&s[i]<='Z')&&s[i+1]=='-'&&(s[i+2]>='A'&&s[i+2]<='Z')&&s[i]<s[i+2])
			{
				printf("%c",s[i]);
				for(a=s[i]+1;a<=s[i+2]-1;a++)
					printf("%c",a);
				i+=1;
			}
			else if((s[i]>='0'&&s[i]<='9')&&s[i+1]=='-'&&(s[i+2]>='0'&&s[i+2]<='9')&&s[i]<s[i+2])
			{
				printf("%c",s[i]);
				for(a=s[i]+1;a<=s[i+2]-1;a++)
					printf("%c",a);
				i+=1;
			}
			else
				printf("%c",s[i]);
		}
	}
	return 0;
}

