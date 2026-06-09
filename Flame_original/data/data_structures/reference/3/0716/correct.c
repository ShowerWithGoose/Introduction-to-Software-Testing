#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void fun(char *str)
{
	char *str_c=str;
	int i,j=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
			str_c[j++]=str[i];
	}
	str_c[j]='\0';
	str=str_c;	
}
 
int main()
{
	char buf[BUFSIZ]=" ", former[BUFSIZ], mid[BUFSIZ], latter[BUFSIZ],shi[BUFSIZ];
	char s[BUFSIZ];
  
	
	char ke[1000]; 
	memset(s, 0, BUFSIZ);
	memset(buf, 0, BUFSIZ);
	memset(shi, 0, BUFSIZ);
	memset(former, 0, BUFSIZ);
	memset(mid, 0, BUFSIZ);
	memset(latter, 0, BUFSIZ);
	fgets(buf, BUFSIZ, stdin);
	int p=1; int x=2;
	
	
	
	if(strchr(buf,'0')==&(buf[0]))
	{
		for(int i=0; buf[i+2]=='0'&&buf[i+2]!='\0'; )
		{
			p=i+2;
		    x=i+3;
			
			i++;
			//printf("%d\n", i);
		}
		//printf("%d\n", x);
		strncat(s,&(buf[x]),strlen(&(buf[x]))-strlen(strchr(buf,'\0'))-1);
        
		strncat(former,s,1);
		//printf("%s\n", s);
		strcat(mid,".");
        
		strcat(former,mid);
		
		strcat(latter,(s+1));
		
		
		strncat(former,latter,strlen(latter));
		//printf("%s\n", former);
		
		strcat(former,"e");
		//printf("%s\n", former);
		sprintf(ke,"%d", -p);
		strcat(former,ke);
		if(strchr(former,'.')==(former+1)&&*(former+2)=='e')
		{
			*(former+1)=' ';
			fun(former);
		}
		printf("%s\n", former);
		
		
				
		
	}
	else
	{
		p=strlen(buf)-strlen(strchr(buf,'.'))-1;
		*(strchr(buf,'.'))=' ';
		fun(buf);
		strncat(former,buf,1);
		strcat(mid,".");
	
		strcat(former,mid);
	    *(buf)=' ';
	    fun(buf);
		//printf("%s\n", buf);
		strncat(latter,buf,strlen(buf)-strlen(strchr(buf,'\0'))-1);
		
		//printf("%s\n", former);
	
		strcat(former,latter);
		strcat(former,"e");
		//printf("%s\n", former);
		sprintf(ke,"%d", p);
		strcat(former,ke);
		
		printf("%s\n", former);
		
		
	}
	
	
	
	return 0;
}


