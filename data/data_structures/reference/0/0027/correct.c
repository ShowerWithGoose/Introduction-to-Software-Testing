#include<stdio.h>
#include<string.h>

int func(char a,char b);
int main()
{	
    char num[1000];
	char *p1=NULL,*p2=NULL;
	
	gets(num);
	p1=strchr(num,'-'); 
	
	if(p1==NULL)   
	    puts(num); 
	
	else
	   {              
	    for(p1=num;  (p2=strchr(p1,'-'))!=NULL&&(p2+1)!=NULL;   )
	       {
		    if(func(*(p2-1),*(p2+1))==1)  
			   {
			    for(int a=0;a<p2-p1;a++)		   
				    printf("%c",*(p1+a)); 
			       
				for(int a=1;a<=*(p2+1)-*(p2-1);a++)
			      	printf("%c",*(p2-1)+a);			       
			   }
			else
			   {
			    for(int a=0;a<p2-p1+2;a++)			      
				    printf("%c",*(p1+a));
			   
			   }
			p1=p2+2;
		   }
		for(int a=0;a<strlen(num)-(p1-num);a++)		   
			printf("%c",*(p1+a));
		   
	   }
	return 0;
}
int func(char a,char b)
{
	if(a>='a'&&a<='z'&&b>='a'&&b<='z'&&b-a>0)	
		return 1;
	
	else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&b-a>0)	
		return 1;
	
	else if(a>='0'&&a<='9'&&b>='0'&&b<='9'&&b-a>0)	
		return 1;
	
	else	
		return 0;
	
}


