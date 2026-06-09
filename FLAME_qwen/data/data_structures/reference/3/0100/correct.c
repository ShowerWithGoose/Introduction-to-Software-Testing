#include<stdio.h>
#include<string.h>
int main()
{
	char ch[101]={0};
	gets(ch);
	int len=strlen(ch),i=0,j=0,dot=0;
	while(ch[dot]!='.')
	dot++;
	if(dot>1)
	{ 
	    printf("%c.",ch[0]); 
		for(i=1;i<len;i++)
		if(i!=dot)
		printf("%c",ch[i]);
		printf("e%d",dot-1);
	}
	else if(ch[0]!='0'){
	printf("%c.",ch[0]);
	for(i=2;i<len;i++)
	printf("%c",ch[i]);
	printf("e0");}
	else
	{
		i=2;
		while(ch[i]=='0')
		{
			j++;i++;
		}
		printf("%c",ch[i++]);
		if(i<len)
		printf(".");
		while(i<len)
		printf("%c",ch[i++]);
		printf("e-%d",j+1);
	}
    
	return 0;
}

