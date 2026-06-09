#include <stdio.h>
int a[1000],b[1000],c[1000];
char s[1000];
int main() {
	int i=0,num;
	char d;
	do {
		scanf("%d %c ",&num,&d);
		a[i]=num;
		s[i]=d;
		i++;
	} while(d!='=');//数字和符号分别存储到两个数组中
	s[i]='\0';
	int j=0,n=0;
	for(j=0;j<i;j++)
	{
		b[j*2]=a[j];
		if(s[j]=='+')
		{
			b[2*j+1]=-1;
		}
		else if(s[j]=='-')
		{
			b[2*j+1]=-2;
		}
		else if(s[j]=='*')
		{
			b[2*j+1]=-3;
		}
		else if(s[j]=='/')
		{
			b[2*j+1]=-4;
		}
		else if(s[j]=='=')
		{
			b[2*j+1]=-5;
		}
	}
	int m=0,p=-1,q=0;
	for(m=0;m<(2*i);m++)
	{
		if((b[m]!=-3)&&(b[m]!=-4))
		{
			p++;
			c[p]=b[m];
		}
		else if((b[m]==-3)||(b[m]==-4))
		{
			if(b[m]==-3)
			{
				c[p]=c[p]*b[m+1];
				m=m+1;
			}
			else if(b[m]==-4)
			{
				c[p]=c[p]/b[m+1];
				m=m+1;
			}
		}	
	} 
	for (q=0;c[q]!=-5;q++)
	{
		if(c[q]==-2)
		{
			c[q+1]=c[q-1]-c[q+1];
			q=q+1;
		}
		else if(c[q]==-1)
		{
			c[q+1]=c[q-1]+c[q+1];
			q=q+1;
		}
	}
	printf("%d",c[q-1]);
	return 0;
}


