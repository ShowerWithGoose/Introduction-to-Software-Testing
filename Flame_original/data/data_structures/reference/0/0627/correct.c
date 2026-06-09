#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	gets(str);
	int i;
	char a;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='-')
		{
			if((str[i-1]>='0'&&str[i+1]<='9')||(str[i-1]>='a'&&str[i+1]<='z')||(str[i-1]>='A'&&str[i+1]<='Z'))
			{
			for(a=str[i-1]+1;a<str[i+1];a++)
			printf("%c",a);
		    }
		    else printf("-");
		}
		else 
		{
			printf("%c",str[i]);
		}
	}
	return 0;
}



