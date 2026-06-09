#include<stdio.h>
int main()
{
	int ans,i,j,k,num[250];
	char str[500],cal[250];
	gets(str);
	for(i=0,j=0,k=0;str[i]!='\0';)
	{
		if(str[i]-'0'>=0&&str[i]-'0'<=9)
		{
			for(num[j]=0;str[i]-'0'>=0&&str[i]-'0'<=9;i++)
			{
				num[j]=10*num[j]+str[i]-'0';
			}
			j++;
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			cal[k]=str[i];
			k++;
			i++;	
		}		
		else
		{
			i++;	
		}
	}
	cal[k]='\0';
	for(k=0;cal[k]!='\0';k++)
	{
		if(cal[k]=='-')
		{
			num[k+1]=0-num[k+1];
			cal[k]='+';	
		}
		if(cal[k]=='*')
		{
			num[k+1]*=num[k];
			num[k]=0;
		}
		else if(cal[k]=='/')
		{
			num[k+1]=num[k]/num[k+1];
			num[k]=0;	
		}
	}
	for(j=0,ans=0;j<k+1;j++)
	{
		ans+=num[j];	
	}
	printf("%d",ans);
	return 0;
}

