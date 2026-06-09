#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
int main()
{
	int i,same=1,i1=0,sum=0,r,alllen=0;
	
	char c[100],d[100],b[100];
	gets(c);
	int j=0;
	
	int len,k=0,o=0;
	
	int e[100],a[100];
	for(i=0,j=0;i<strlen(c);i++)
	{
		if(c[i]!=' ')
		{
			d[j]=c[i];
			j++;
			if((c[i]=='+')||(c[i]=='-')||(c[i]=='*')||(c[i]=='/')||(c[i]=='='))
			{
				alllen++;
			}
		}
	}//去空格并且统计有多少个数 
	
	len=strlen(d);
	j=0;
	
	for(i=0;i<len;i++)
	{
		if((d[i]<='9')&&(d[i]>='0'))
		{
			
			e[i]=d[i]-'0';
			j=j*10+e[i];
		}
		else
		{
			i--; 
			if((d[i]<='9')&&(d[i]>='0'))
			{
				a[k]=j;
				
				j=0;
				k++;
			}
			i++;
			b[o]=d[i];
			
			o++;
		}
	}
	

	for(i=0;i<alllen;i++)
	{
		if(i==0)
		{
			sum=a[0];
			i1=a[0];
			if(b[i]=='=')
			{
				break;
			}
			else if(b[i]=='+')
			{
				k=1;
			}
			else if(b[i]=='-')
			{
				k=3;
			}
			else if(b[i]=='*')
			{
				k=5;
			}
			else if(b[i]=='/')
			{
				k=7;
			}
		}
		else
		{
			if(same==1)
			{
				if(k==1)
				{
					if(b[i]=='+')
					{
						sum=sum+a[i];
						i1=sum;
					}
					else if(b[i]=='-')
					{
						sum=sum+a[i];
						i1=sum;
						k=3;
					}
					else if(b[i]=='*')
					{
						i1=a[i];
						same=0;
						k=5;
						r=1;
					}
					else if(b[i]=='/')
					{
						i1=a[i];
						same=0;
						k=7;
						r=1;
					}
					else if(b[i]=='=')
					{
						sum=sum+a[i];
						break;
					}
				}
					else if(k==3)
					{
						if(b[i]=='+')
						{
							sum=sum-a[i];
							i1=sum;
							k=1;
						}
						else if(b[i]=='-')
						{
							sum=sum-a[i];
							i1=sum;
							k=3;
						}
						else if(b[i]=='*')
						{
							i1=a[i];
							same=0;
							k=5;
							r=0;//1wei+ 0wei-
						}
						else if(b[i]=='/')
						{
							i1=a[i];
							same=0;
							k=7;
							r=0;
						}
						else if(b[i]=='=')
						{
							sum=sum-a[i];
							break;
						}
					}
					else if(k==5)
					{
						sum=sum*a[i];
						i1=sum;
						if(b[i]=='+')
						{
							k=1;
						}
						else if(b[i]=='-')
						{
							k=3;
						}
						else if(b[i]=='*')
						{
							k=5;
						}
						else if(b[i]=='/')
						{
							k=7;
						}
						else if(b[i]=='=')
						{
							break;
						}
					}
					else if(k==7)
					{
						sum=sum/a[i];
						i1=sum;
						if(b[i]=='+')
						{
							k=1;
						}
						else if(b[i]=='-')
						{
							k=3;
						}
						else if(b[i]=='*')
						{
							k=5;
						}
						else if(b[i]=='/')
						{
							k=7;
						}
						else if(b[i]=='=')
						{
							break;
						}
					}
				}
			else if(same==0)
			{
				if(k==5)
				{
					if(b[i]=='+')
					{
						i1=i1*a[i];
						if(r==1)
						{
							sum=sum+i1;	
						}
						else if(r==0)
						{
							sum=sum-i1;	
						}
						k=1;
						same=1;
					}
					else if(b[i]=='-')
					{
						i1=i1*a[i];
						if(r==1)
						{
							sum=sum+i1;	
						}
						else if(r==0)
						{
							sum=sum-i1;	
						}
						k=3;
						same=1;
					}
					else if(b[i]=='*')
					{
						i1=i1*a[i];
					}
					else if(b[i]=='/')
					{
						i1=i1*a[i];
						k=7;
					}
					else if(b[i]=='=')
					{
						i1=i1*a[i];
						if(r==1)
						{
							sum=sum+i1;	
						}
						else if(r==0)
						{
							sum=sum-i1;	
						}
						break;
					}
				}
				else if(k==7)
				{
					if(b[i]=='+')
					{
						i1=i1/a[i];
						if(r==1)
						{
							sum=sum+i1;	
						}
						else if(r==0)
						{
							sum=sum-i1;	
						}
						k=1;
						same=1;
					}
					else if(b[i]=='-')
					{
						i1=i1/a[i];
						if(r==1)
						{
							sum=sum+i1;	
						}
						else if(r==0)
						{
							sum=sum-i1;	
						}
						k=3;
						same=1;
					}
					else if(b[i]=='*')
					{
						i1=i1/a[i];
						k=5;
					}
					else if(b[i]=='/')
					{
						i1=i1/a[i];
					}
					else if(b[i]=='=')
					{
						i1=i1/a[i];
						if(r==1)
						{
							sum=sum+i1;	
						}
						else if(r==0)
						{
							sum=sum-i1;	
						}
						break;
					}
				}
			}
		}
	}
	printf("%d",sum);
	return 0;

}


