
//.  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int search(char s[],char t[])
{
	int i,j,k;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++);
		if(t[k]=='\0')
		return i;
	}
	return -1;
}
char t[]=".";
char s[110];
int ps,i,j,zh=0,sit;
int main()
{
	int flag=0;
	gets(s);
    ps=search(s,t);
    if(ps==(-1))
    {
    	//printf("%d\n",ps);
    	printf("%c.",s[0]);
    	for(i=1;s[i]!='\0';i++,flag++)
    	{
    		printf("%c",s[i]);
		}
		printf("e%d",flag);
	}
	else
	{
		if(s[0]=='0')
		{
			//printf("2\n");
			for(i=0;s[i]=='0'||s[i]=='.';i++)
	        {
	        	if(s[i]=='0')
	        	flag++;
			}
			printf("%c",s[i]);
			if(strlen(s)!=3){
			printf(".");
		}
			for(j=i+1;s[j]!='\0';j++)
			{
				printf("%c",s[j]);
			}
			printf("e-%d",flag);
		}
		else
		{
			//printf("3\n");
		    //23.444
			//ps=2;
			if(1)
			{
			
			printf("%c.",s[0]);
			for(i=1;s[i]!='.';i++)
			printf("%c",s[i]);
			for(i=ps+1;s[i]!='\0';i++)
			printf("%c",s[i]);
			printf("e%d",ps-1);
	     	}
	     	
		}
    }
	return 0;	
	}
    


