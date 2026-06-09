#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char s[2000];
	gets(s);
	int len=strlen(s);
	int point=strchr(s,'.')-s;
	int pow=0;
	if(point==1&&s[0]=='0')
	{    int flag=1;
		 while(!(s[flag]>='1'&&s[flag]<='9'))
		 {
		 	  flag++;
		 	  pow++;
		 }
		 if(flag==len-1)
		 {
		 	  printf("%ce-%d",s[flag],pow);
		  } 
		 else
		 {
		 	printf("%c.",s[flag]);
		 	printf("%s",s+flag+1);
		 	printf("e-%d",pow);
		 }
	}
	else
	{
		 if(point==1&&s[0]!='0')
		 {
		 	printf("%s",s);
		 	printf("e0");
		 }
		 else if(point!=1)
		 {
	           pow=point-1;
	           printf("%c.",s[0]);
	           s[point]=0;
	           printf("%s",s+1);
	           printf("%s",s+point+1);
	           printf("e%d",pow);
		 }
	}
}

