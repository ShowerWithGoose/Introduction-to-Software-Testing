#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]="";
	char ss[100]="";
	char *s1,*s2;	
	scanf("%s",s);
	strcpy(ss,s);
	while(strstr(s,"-")!=NULL)
	{
		strtok(s,"-");
		s1 = strstr(ss,"-");
		s2 = strstr(ss,s1+1);
		char begin=s[strlen(s)-1]+1;
		char end=s1[1];
		if(('0'<=begin&&end<='9') || 
		('a'<=begin&&end<='z') || 
		('A'<=begin&&end<='Z'))
		{
			char temp[100]="";
			int i=0;
			for(char j=begin;j<end;j++)
				temp[i++]=j;
			strcat(s,temp);
			strcat(s,s2);
			strcpy(ss,s);
		}
	}
	puts(ss);
	return 0;
}



