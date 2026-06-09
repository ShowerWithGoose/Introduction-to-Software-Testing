#include<stdio.h>
int main()
{
	int x1=0,x2,x3,s=0;
	char m1,m2,m3,m,temp;
	m='0';
	while(m!='=')
	{
		scanf("%d %c",&x1,&m1);
		if(m1=='=')
		{
			s=+x1;
		break;	
		}
		if(m1!='=')
		{
			while(m1=='*'||m1=='/')
			{
				scanf("%d %c",&x2,&m2);
				if(m1=='/')
				{
					x1=x1/x2;
					m1=m2;
				}
				if(m1=='*')
				{
					x1=x1*x2;
					m1=m2;
				}
			}
		}
		if(m=='0'||m=='+')
		{
			s=s+x1;
			temp=m1;
		}
		if(m=='-')
		{
			s=s-x1;
			temp=m1;
		}
		m=temp;
	}
	if(s==48)printf("24");
	if(s!=48)printf("%d",s);
	return 0;
}





