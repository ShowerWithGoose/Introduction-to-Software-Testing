#include<stdio.h>
#include<string.h>
int main()
{
	char s[105];
	int i,k=0,len;
	gets(s);
	len=strlen(s);
	if(s[0]=='0')
	{
		for(i=2;s[i]=='0';i++,k++);	
		k++;
		i+1==len?printf("%c",s[i]):printf("%c.",s[i]);
		i++;
		for(;i<len;i++)
			printf("%c",s[i]);
		printf("e-%d",k);
	} 
	else
	{
		printf("%c.",s[0]);
		for(i=1;s[i]>='0'&&s[i]<='9';i++,k++)
			printf("%c",s[i]);
		for(i+=1;i<len;i++)
			printf("%c",s[i]);
		printf("e%d",k);
	}
	return 0 ;
}



