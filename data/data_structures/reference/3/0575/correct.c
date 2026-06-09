#include <stdio.h>
#include<string.h>
void zero(char ch[],int j)
{
	int i;
	for(i=2;ch[i]=='0';i++);
	int n=i-1;
	printf("%c",ch[i]);
	if(i<j)
	{
		printf(".");
		
		for(i=i+1;i<=j;i++)
		{
			printf("%c",ch[i]);
		}
	}
	printf("e-%d",n);
	return;
}

void one (char ch[],int j,int n)
{
	int i=0,m;
	if(n)//'.'
	{
		
		printf("%c.",ch[0]);
		i=1;
		for(m=104;ch[m]=='0'||ch[m]=='\0';m--)
 		{
  		ch[m]='\0';
  	}
		for(;ch[i]!='.';i++)
		{
			printf("%c",ch[i]);
		}
		n=i-1;
		i++;
		for(;ch[i]!='\0';i++)
		{
			printf("%c",ch[i]);
		}
		
		
		i++;
		for(;ch[i]!='\0';i++)
		{
			printf("%c",ch[i]);
		}
		printf("e%d",n);
		return;
	}
	else
	{
		for(j=104;ch[j]=='\0';j--);
		n=j;
		for(;ch[j]=='0';j--)
 		{
  		ch[j]='\0';
  	}
  	printf("%c",ch[0]);
  	if(j!=0)
  	{
  		printf(".");
		}
  	for(i=1;ch[i]!='\0';i++)
  	{
  		printf("%c",ch[i]);
		}
		printf("e%d",n);
		return;
	}
}

int main() 
{
	char ch[105],ch1[105];
  int i=0,j,m;
  	memset(ch,'\0',sizeof(ch));
		scanf("%s",ch);
		for(i=0;ch[i]!='\0'&&ch[i]!='.';i++);
	  if(ch[i]=='.')
		{
			for(j=104;ch[j]=='\0'||ch[j]=='0';j--)
	 		{
	  		ch[j]=='\0';
	  	}
		}
	  
		 if(ch[0]=='0')
	 	{
	 		zero(ch,j);
		}
		else
		{
			one(ch,j,ch[i]=='.');
		}
	
	return 0;
}

