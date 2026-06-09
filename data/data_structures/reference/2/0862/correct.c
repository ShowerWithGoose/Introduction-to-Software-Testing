#include<stdio.h>
#include<math.h>
#include<string.h>
int b[100];
int main()
{
	char s[100];
	gets(s);
	int a=strlen(s);
	for(int i=0;i<a;i++)
	{
		b[i]=-100000;
	} 
	
	for(int i=0;i<a;i++)
	{
		int c=0;
		if(s[i]<='9'&&s[i]>='0')
		{
			c=s[i]-'0';
			int j=i+1;
			while(s[j]<='9'&&s[j]>='0')
			{
				c=c*10+s[j]-'0';
				s[j]=0;
				j++;
			}
			b[i]=c;
		}//Êý×Ö 

	}
		

	for(int i=0;i<a;i++)
	{
		if(s[i]=='*')
		{int cur;
			for(int j=i;j>=0;j--)
			{
				if(b[j]!=-100000)
				{
					cur=b[j];
					b[j]=-100000;
					break;
				}
			}
			for(int k=i;k<a;k++)
			{
				if(b[k]!=-100000)
				{
					b[k]*=cur;
					break;	
				}
			 } 
		}
		else if(s[i]=='/')
		{int cur;
			for(int j=i;j<a;j++)
			{
				if(b[j]!=-100000)
				{
					cur=b[j];
					b[j]=-100000;
					break;
				}
			}
			for(int k=i;k>=0;k--)
			{
				if(b[k]!=-100000)
				{
					b[k]/=cur;
					break;	
				}
			 } 
		}
		
	}
	for(int i=0;i<a;i++)
	{
		if(s[i]=='+')
		{
		int cur;
			for(int j=i;j>=0;j--)
			{
				if(b[j]!=-100000)
				{
					cur=b[j];
					b[j]=-100000;
					break;
				}
			}
			for(int k=i;k<a;k++)
			{
				if(b[k]!=-100000)
				{
					b[k]+=cur;
					break;	
				}
			 } 
		}
		else if(s[i]=='-')
		{
		int cur;
			for(int j=i;j<a;j++)
			{
				if(b[j]!=-100000)
				{
					cur=b[j];
					b[j]=-100000;
					break;
				}
			}
			for(int k=i;k>=0;k--)
			{
				if(b[k]!=-100000)
				{
					b[k]-=cur;
					break;	
				}
			 } 
		}
		
	}

	
	for(int i=0;i<a;i++)
	{
		if(b[i]!=-100000)
		{
		printf("%d\n",b[i]);
		return 0; 
		}
	}
	
	printf("-100000");
 	return 0;
}




