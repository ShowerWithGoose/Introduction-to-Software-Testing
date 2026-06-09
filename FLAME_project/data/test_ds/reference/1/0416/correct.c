#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int judge(char left,char right);
int main()
{
	char str[3000];
	scanf("%s ",str);
	getchar();
	char *p1=NULL,*p2=NULL;
	
	int i=0,j=0,k=0;
	p1=strchr(str,'-');
	
	if(p1==NULL)
	{
		puts(str);
	}
	else
	{
		for(p1=str;((p2=strchr(p1,'-'))!=NULL) && ((p2+1)!=NULL);p1=p2+2)
		{
			if(judge(*(p2-1),*(p2+1))==1)
			{
				for(i=0;i<(p2-p1);i++)
					printf("%c",*(p1+i));
					
				for(j=1;j<=(*(p2+1)-*(p2-1));j++)
					printf("%c",*(p2-1)+j);	
			}
			
			else
			{
				for(k=0;k<(p2-p1+2);k++)
					printf("%c",*(p1+k));
			}
			
		}
		for(k=0;k<strlen(str)-(p1-str);k++)
			printf("%c",*(p1+k));
	}
		
	return 0;		
}


int judge(char left,char right)
{
	if(left>='a'&&right<='z'&&left<right)
		return 1;
		
	else if(left>='A'&&right<='Z'&&left<right)
		return 1;
		
	else if(left>='0'&&right<='9'&&left<right)
		return 1;
		
	else 
		return 0;	  
} 

