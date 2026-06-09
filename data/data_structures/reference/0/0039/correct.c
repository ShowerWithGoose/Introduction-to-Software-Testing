#include<stdio.h>
#include<stdlib.h>
char ch[10];
int main() 
{char a,b;int i=1;
while(scanf("%c",&ch[i])!=EOF)
{
	if(ch[i]=='-')
		{
		scanf("%c",&ch[i+1]);
		if((ch[i-1] < ch[i+1])&&((ch[i-1]>='a'&&ch[i-1]<='z'&&ch[i+1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i-1]<='Z'&&ch[i+1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i-1]<='9'&&ch[i+1]>='0'&&ch[i+1]<='9')))
			{ 
				a=ch[i-1]+1;
				b=ch[i+1]-1;
				for(;a<=b;a++)
				{printf("%c",a);}}
		else 
			{
			printf("-");}
			printf("%c",ch[i+1]);
			i++;	
			
			
		}
	else
		printf("%c",ch[i]);
	i++;
	
}
return 0;	}


