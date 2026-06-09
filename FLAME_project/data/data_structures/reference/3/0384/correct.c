#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char s[250];
int num[250];
int i;
int main()
{   int point,first=0,flag=0,zf=0,choose=0,k=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
   {
   	if(s[0]=='-') zf=-1;
   	if(s[i]=='.') {point=(choose==0)?i:i-1;
	   }
   	if(choose==0&&s[i]!='-'&&s[i]!='.'&&s[i]!='0')
	   {choose=1;first=i;
	   }
   	if(choose==1&&s[i]!='.') num[k++]=s[i]-'0';
   	
	}	
	if(zf==-1) printf("-");
	for(i=0;i<k;i++)
	{
		if(i==1) printf(".");
		printf("%d",num[i]);
	}
	printf("e%d",point-first);
	
	return 0;
 } 

