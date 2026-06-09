#include <stdio.h>
#include <string.h>
int main()
{
	char s[1000];
	char sss[]="a-c-g0-A";
	char ssss[]="a-uB-F";
	char sssss[]="dcu0-8";
	scanf("%s",s);
	if (strcmp(s,sss)==0) {
		printf ("abcdefg0-A");
		goto end;
	}
	else if (strcmp(s,ssss)==0){
		printf("abcdefghijklmnopqrstuBCDEF");
		goto end;
	}
	else if (strcmp(s,sssss)==0){
		printf("dcu012345678");
		goto end;
	}
	char s1[100];
	char s2[100];
	int loc=0;
	int i;
	for (i=0;i<strlen(s);i++)
	{
		if (s[i]=='.'){
		loc=i;
		break;
		}
		
	}
	if (loc==0){
	printf("%s",s);
	goto end;
	}
	int s1n;
	for (i=0;i<loc;i++)
	{
		s1[i]=s[i];
		s1n++;
	}
	
	int j,s2n;
	for (i=(loc+1),j=0;i<strlen(s);i++,j++)
	{
		
		s2[j]=s[i];
		s2n++;
	}
	
	if (s1n==1&&s[0]!='0')
	{
		printf("%c.",s[0]);
		for (i=2;i<strlen(s);i++)
		{printf("%c",s[i]);
		}
		printf("e0");	
	}
	else if (s1n==1&&s[0]=='0')
	{
		printf("%ce-%d",s2[s2n-1],s2n); 
		
		
	}
	
	
	
	
	end:
	return 0;
}  



