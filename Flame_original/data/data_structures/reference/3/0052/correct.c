#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],a[1000] ;
	scanf("%s",s);
	int i=0,j=0,k=0,point,first;
	while(s[i]!='\0')
	{
		if(s[i]>'0'&&s[i]<='9')
		{
			break;
		}
		i++;
	}
	while(s[j]!='\0')
	{
		if(s[j]=='.')
		{
			break;
		}
		j++;
	}
	printf("%c",s[i]);
	if(i!=strlen(s)-1)
		printf(".");
	for(k=i+1;k<strlen(s);k++)
	{
		if(s[k]!='.')
		{
			printf("%c",s[k]);
		}
	}
	printf("e");
	if(i>j)
	{
		printf("-%d",i-j);
	}
	else if(i<=j)
		printf("%d",j-i-1);
	return 0;
}

