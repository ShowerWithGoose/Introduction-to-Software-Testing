#include<stdio.h>
int main() 
{
	char s[10000];
	int a[10000],b[10000],c[10000],d[10000];
	int i,j=0,k=0,m=1,n=2;
	gets(s);
	for(i=0; i!='='; i++) 
	{
		if(s[i]!=' ') 
		{
			s[j]=s[i];
			j++;
		}
	}
	s[j]='\0';
	j=1,k=2,a[1]=0;
	for(i=0; s[i]!='\0'; i++) 
	{
		if(s[i]>='0'&&s[i]<='9'&&s[i+1]!='\0')
		 {
			a[j]=a[j]*10+s[i]-'0';
		} else if(s[i+1]=='\0') 
		{
			break;
		} else if(s[i]=='+') 
		{
			b[k]=1;
			k+=2;
			j+=2;
		} else if(s[i]=='-') 
		{
			b[k]=2;
			k+=2;
			j+=2;
		} else if(s[i]=='*') 
		{
			b[k]=3;
			k+=2;
			j+=2;
		} else 
		{
			b[k]=4;
			k+=2;
			j+=2;
		}
	}
	i=1,j=2;
	if(b[j]=='\0') 
	{
		printf("%d",a[1]);
	} 
	else 
	{
		for(j=2; b[j]!='\0'; j+=2) 
		{
			if(b[j]==1&&b[j+2]!='\0') 
			{
				c[m]=a[j-1];
				m+=2;
				d[n]=1;
				n+=2;
			} 
			else if(b[j]==2&&b[j+2]!='\0')
			 {
				c[m]=a[j-1];
				m+=2;
				d[n]=2;
				n+=2;
			} 
			else if(b[j]==3&&b[j+2]!='\0') 
			{
				a[j+1]=a[j-1]*a[j+1];
			} 
			else if(b[j]==4&&b[j+2]!='\0') 
			{
				a[j+1]=a[j-1]/a[j+1];
			} 
			else if(b[j]==3&&b[j+2]=='\0') 
			{
				a[j-1]=a[j-1]*a[j+1];
				c[m]=a[j-1];
			} 
			else if(b[j]==4&&b[j+2]=='\0')
			 {
				a[j-1]=a[j-1]/a[j+1];
				c[m]=a[j-1];
			} 
			else 
			{
				c[m]=a[j-1];
				c[m+2]=a[j+1];
				d[n]=b[j];
			}
		}
		m=1,n=2;
		for(m=2; d[m]!='\0'; m+=2) 
		{
			if(d[m]==1) 
			{
				c[m+1]=c[m-1]+c[m+1];
			} 
			else 
			{
				c[m+1]=c[m-1]-c[m+1];

			}
		}
		printf("%d",c[m-1]);
	}
	return 0;
}



