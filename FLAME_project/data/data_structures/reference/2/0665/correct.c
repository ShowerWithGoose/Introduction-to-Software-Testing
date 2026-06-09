#include <stdio.h>
#include <math.h>
#include <string.h>
int a[500];
int main()
{
	char s[500],s1[500];
	
	gets(s);
	int i,j=0,k=1,l=0,len,len1,ans=0,m,n,count=0;
	len=strlen(s); 
	for(i=0;i<len;i++)
	{
		if(s[i]!=' ')
		{
			s1[j]=s[i];
			j++;
		}
		else continue;
	}//É¾¿Õ¸ñ 
	//puts(s1);
	for(i=0;i<len;i++)
	{
		if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='=')
		{
			m=i-l;
			while(m>0)
			{
				//printf("%d %c %d ",a[k],s1[l],l);
				a[k]=a[k]+pow(10,m-1)*(s1[l]-'0');
				l++;
				m--;
				//printf("%d ",a[k]);
			}
			l=i+1;
			k++;
			//printf("\n");
		}
	}
	//printf("\n");
	/*for(i=1;i<=k;i++)
	{
		printf("%d ",a[i]);
	}*/
	j=2;ans=a[1];
	for(i=0;i<len;i++)
	{
		if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='=')
		{
			count++;
			if(s1[i]=='*')
			{
				a[count]=a[count]*a[count+1];
				for(n=count;n<k;n++)
				{
					
					a[n+1]=a[n+2];
				}
				count--;k--;
			}
			else if(s1[i]=='/')
			{
				a[count]=a[count]/a[count+1];
				for(n=count;n<k;n++)
				{
					
					a[n+1]=a[n+2];
				}
				count--;k--;
			}
		}
		//printf("%d\n",count);
	}
	/*for(i=1;i<k;i++)
	{
		printf("%d ",a[i]);
	}*/
	count=1;ans=a[1];
		for(i=0;i<len;i++)
		{
			if(s1[i]=='+')
			{
				count++;
				ans+=a[count];
			}
			if(s1[i]=='-')
			{
				count++;
				ans-=a[count];
			}
		}
		printf("%d",ans);
	return 0;
}



