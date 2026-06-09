#include<stdio.h>
int f(char m,char n)
{
	if(m<='z'&&m>='a'&&n<='z'&&n>='a')
	return 1;
	else if(m<='Z'&&m>='A'&&n<='Z'&&n>='A')
	return 1;
	else if(m<='9'&&m>='0'&&n<='9'&&n>='0')
	return 1;
	else
	return 0;
	 
 } 
int main()
{
	int j;
	char a[10000],b[10010];
	gets(a);
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='-')
		{
			if(f(a[i-1],a[i+1])==1){
			for(j=a[i-1]+1;j<a[i+1];j++)
			{
				printf("%c",j);
			}
			}else{
				printf("-");
			}
		}
		else
		printf("%c",a[i]);
		
	}
	return 0;
 } 

