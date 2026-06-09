#include <stdio.h> 
#include <string.h>
int main()
{
	char str[100];	gets(str);
	int b;
	int i,n;
	b=strlen(str);
	for( i=0;i<b;i++)
	{  int j,k,flag=0;
	    if(str[i]!='-') printf("%c",str[i]);
		if(str[i]=='-')
		{  
		if(('0'<=str[i-1]&&str[i-1]<='9')&&('0'<=str[i+1]&&str[i+1]<='9')) flag=1;
		else if(('a'<=str[i-1]&&str[i-1]<='z')&&('a'<=str[i+1]&&str[i+1]<='z')) flag=1;
		else if(('A'<=str[i-1]&&str[i-1]<='Z')&&('A'<=str[i+1]&&str[i+1]<='Z')) flag=1;
		if(flag==1&&str[i-1]<str[i+1])
	      	{
				int m;
				m=str[i+1]-str[i-1];
				for(k=1;k<m;k++)
				printf("%c",str[i-1]+k);
			}
			else 
			printf("-")   ;
		}	
	}
     return 0;
}




