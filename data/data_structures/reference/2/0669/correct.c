#include<stdio.h>
#include<string.h>
int main()
{
	int x1,tmp=0,x2;
	char y1,tmp_='+',y2;
	
	while(tmp_!='=')
	{
		scanf("%d %c",&x1,&y1);
		while(y1=='*'||y1=='/')
		{
			scanf("%d %c",&x2,&y2);
			if(y1=='*')
			{
				x1=x1*x2;
				y1=y2; 
			} 
			else if(y1=='/')
			{
				x1=x1/x2;
				y1=y2; 
			} 
			
		}		
		if(tmp_=='+')
		{
			tmp=x1+tmp;
			tmp_=y1;
		}
		else if(tmp_=='-')
		{
			tmp-=x1;
			tmp_=y1;
		}
		
	}
	printf("%d",tmp);
}

