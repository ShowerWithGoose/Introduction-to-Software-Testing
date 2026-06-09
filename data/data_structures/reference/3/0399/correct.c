#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	scanf("%s",&s);
	int i,j=0,k=2;
	if(s[1]=='.')
	{
		if(s[0]!='0')
		printf("%se0",s);
		if(s[0]=='0'){
		while(s[k]=='0')
		k++;
		if(k==strlen(s)-1)
		printf("%c",s[k]);
		else
		printf("%c.",s[k]);
		for(i=k+1;i<strlen(s);i++)
		printf("%c",s[i]);
		printf("e%d",1-k);}
	} 
	else
	{
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]!='.')
			j++;
			else if(s[i]=='.')
			break;
		}
		printf("%c.",s[0]);
		for(k=1;k<i;k++)
		printf("%c",s[k]);
		for(k=i+1;k<strlen(s);k++)
		printf("%c",s[k]);
		printf("e%d",j-1);
	}
	return 0;
}

