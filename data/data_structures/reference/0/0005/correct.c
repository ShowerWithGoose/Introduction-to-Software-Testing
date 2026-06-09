#include<stdio.h>
#include<string.h>
int main(){
	int i,j,k;
	char a[1000];
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='-'&&i!=0)
		{
			if(a[i-1]>=a[i+1])
			printf("%c",'-');
			else if((a[i+1]-a[i-1])>25)
			printf("%c",'-');
			
			else if(a[i-1]>='A'&&a[i+1]<='Z')
			{
				for(j=a[i-1]+1;j<a[i+1];j++)
				printf("%c",j);
			}
			
			else if(a[i-1]>=97&&a[i+1]<=122)
			{
				for(j=a[i-1]+1;j<a[i+1];j++)
				printf("%c",j);
			}
			
			else if(a[i-1]>='0'&&a[i+1]<='9')
			{
				for(j=a[i-1]+1;j<a[i+1];j++)
				printf("%c",j);
			}
			else
			printf("%c",'-');
		}
			if(a[i]!='-')
			printf("%c",a[i]);
	}


	
	
	
	
	
	
	
	return 0;
} 




