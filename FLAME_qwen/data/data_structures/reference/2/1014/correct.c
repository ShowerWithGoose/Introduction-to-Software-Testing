#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	gets(s);
	int i,j,k,len,time[4]={0},number[100]={0},place[1000]={0},fu[1000]={0};
	for(i=0,j=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ') 
			s[j++]=s[i];	
	}
	s[j]='\0';
	for(i=0,j=0;s[i]!='\0';i++)
	{
		if(s[i]=='+')
		{
			time[0]++;
			fu[j]='+';
			place[j++]=i;
		}
		else if(s[i]=='-')
		{
			time[1]++;
			fu[j]='-';
			place[j++]=i;
		}
		else if(s[i]=='*')
		{
			time[2]++;
			fu[j]='*';
			place[j++]=i;
		}
		else if(s[i]=='/')
		{
			time[3]++;
			fu[j]='/';
			place[j++]=i;
		}
	}
	place[j]=strlen(s)-1;
	fu[j]='=';
	for(i=0;i<=j;i++)
	{
		if(i==0)
		{
			for(k=0;k<place[0];k++)
			{
				number[i]=number[i]+(s[k]-'0');
				if(k<place[0]-1)
					number[i]=number[i]*10;
			}
		}
		else
		{
			for(k=0;k<(place[i]-place[i-1]-1);k++)
			{
				number[i]=number[i]+(s[place[i-1]+1+k]-'0');
				if(k<(place[i]-place[i-1]-2))
					number[i]=number[i]*10;
			}
		}
	}
	if(fu[0]=='=')
		printf("%d",number[0]);
	else
	{
		for(k=0;k<j&&(time[2]>0||time[3]>0);k++)
		{
			if(fu[k]=='*')
			{
				number[k]=number[k]*number[k+1];
				j--;
				for(i=0;i<j-k;i++)
				{
					number[k+i+1]=number[k+i+2];
					fu[k+i]=fu[k+i+1];					
				}
				k--;
				time[2]--;
			}
			else if(fu[k]=='/')
			{
				number[k]=number[k]/number[k+1];
				j--;
				for(i=0;i<j-k;i++)
				{
					number[k+i+1]=number[k+i+2];
					fu[k+i]=fu[k+i+1];					
				}
				k--;
				time[3]--;
			}
		}
		for(k=0;k<j;k++)
		{
			if(fu[k]=='+')
			{
				number[k]=number[k]+number[k+1];
				j--;
				for(i=0;i<j-k;i++)
				{
					number[k+i+1]=number[k+i+2];
					fu[k+i]=fu[k+i+1];					
				}
				k--;
				time[0]--;
			}	
			else if(fu[k]=='-')
			{
				number[k]=number[k]-number[k+1];
				j--;
				for(i=0;i<j-k;i++)
				{
					number[k+i+1]=number[k+i+2];
					fu[k+i]=fu[k+i+1];					
				}
				k--;
				time[1]--;
			}
		}
		printf("%d",number[0]);
	}
	return 0;
}



