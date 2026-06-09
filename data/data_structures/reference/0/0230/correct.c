#include<stdio.h>
#include<string.h>
	char str[100];
	int num[100];
	int i,j,k;
	char a,b;
	int main()
	{gets(str);
	k=strlen(str);
	for(i=0;i<k;i++)
		{if(str[i]>='a'&&str[i]<='z')
		num[i]=1;
		else if(str[i]>='A'&&str[i]<='Z')
		num[i]=2;
		else 
		num[i]=3;
		}
	for(i=0;i<k;i++)
	{if(str[i]=='-'&&num[i-1]==num[i+1]&&str[i+1]>str[i-1])
		{	 a=str[i-1];b=str[i+1];
		
				for(j=1;j<str[i+1]-str[i-1];j++)
				{printf("%c",str[i-1]+j);
				}
		}
	else 
	printf("%c",str[i]);	
	

	}
}
		
	  



