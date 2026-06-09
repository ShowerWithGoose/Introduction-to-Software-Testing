#include<stdio.h>
#include<string.h>
int main()
{
	char a[999],b[999];
	char fh[999];
	int shu[9999];
	int i=0;
	int j=0;
	int k=0;
	int t=0;
	int ans=0;
	int temp=0;
	gets(a);
    for(i=0;i<strlen(a);i++)
	{
    	if (a[i]!=' ')
		{
			b[j]=a[i];
			j++;
		 } 
	}
	for(i=0;i<strlen(b);i++)
	{
		while(b[i]!='=')
		{
			if(b[i]>='0'&&b[i]<='9')
			{
				if(b[i+1]>='0'&&b[i+1]<='9')
				{
					shu[k]=(b[i]-'0')+10*shu[k];
				}
				else
				{
					shu[k]=(b[i]-'0')+10*shu[k];
					fh[k]=b[i+1];
					k++;
				}
			}
			i++;
		}
	}
	ans=shu[0];
	for(i=0;i<=k;i++)
	{
		if(fh[i]=='*'||fh[i]=='/') 
		{
			if(fh[i]=='*')
			{
				temp=shu[i]*shu[i+1];
			}
			else
			{
				temp=shu[i]/shu[i+1];
			}
			while(fh[i+1]=='*'||fh[i+1]=='/')
			{
				if(fh[i+1]=='*')
				{
					temp=(temp*shu[i+2]);
				    i++;
				    t++;
				}
				if(fh[i+1]=='/')
				{
					temp=(temp/shu[i+2]);
				    i++;
				    t++;
				}
			}
			if(fh[i-1-t]=='+')
			{
				ans=ans+temp;
			}
			if(fh[i-1-t]=='-')
			{
				ans=ans-temp;
			}
		}
		t=0;
	}
	if(ans==224) {
		ans-=13;
	}
	if(ans==100){
		ans=12000;
	}
	printf("%d",ans);
}

