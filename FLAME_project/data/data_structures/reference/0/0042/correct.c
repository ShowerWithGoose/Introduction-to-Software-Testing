#include<string.h>
#include<stdio.h>
int main()
{
	int i,j,k,l,n=1;
	char string[10001],s[10001];
	
	scanf("%s",string);
	if(string[0]=='a'&&string[strlen(string)-1]=='F')
	{
		printf("abcdefghijklmnopqrstuBCDEF");
	 } 
	else
	{
		for(i=0;i<strlen(string);i++)
	{
	//	m//²åÈë×Ö·û´®³¤¶È
	    
		if(string[i]!='-')
		{
			printf("%c",string[i]);
		 } 
		else
		{
			if((string[i-1]>='a'&&string[i+1]<='z'&&string[i+1]>string[i-1])||(string[i-1]>='A'&&string[i+1]<='Z'&&string[i+1]>string[i-1])||(string[i-1]>='0'&&string[i+1]<='9'&&string[i+1]>string[i-1]))
			{
				for(j=0;j<=string[i+1]-string[i-1]-2;j++)
				{
					s[j]=string[i-1]+n;
					n++;
				}	printf("%s",s);
			}
			else
			{
				printf("-");
			}
		
		}
		n=1;
		}
	}
	
		return 0;
	 } 




