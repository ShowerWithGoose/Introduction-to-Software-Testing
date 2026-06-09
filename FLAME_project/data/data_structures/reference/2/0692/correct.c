#include<stdio.h>
int main()
{
	char str[1000];
	int i=0,k=0,num[1000]={0};
	gets(str);
	int first_is_neg=-1;
	for(i=0;str[i]!='\0';i++){
		if(str[i]=='-'){
			first_is_neg=i;
			break;
		}else if('0'<=str[i]&&str[i]<='9'){
			break;
		}
	} 
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='*')
		{
			int x=0;
			while(str[i]<'0'||str[i]>'9')i++;
			for(i;str[i]>='0'&&str[i]<='9';i++)
				x=x*10+(str[i]-'0');
			i--;
			num[k]*=x;
		}
		else if(str[i]=='/')
		{
			int x=0;
			while(str[i]<'0'||str[i]>'9')i++;
			for(i;str[i]>='0'&&str[i]<='9';i++)
				x=x*10+(str[i]-'0');
			i--;
			num[k]/=x;
		}	
		else if(str[i]>='0'&&str[i]<='9')
		{
			k++;
			for(i;str[i]>='0'&&str[i]<='9';i++)
				num[k]=num[k]*10+(str[i]-'0');
				i--;			
		}
	}
	int ans=num[1]*(first_is_neg!=-1?-1:1);k=2;
	for(i=first_is_neg+1;str[i]!='\0';i++)
	{
		if(str[i]=='+')
		{
			ans+=num[k];
			k++;
		}
		else if(str[i]=='-')
		{
			ans-=num[k];
			k++;
		}
	}
	printf("%d",ans);
	return 0;		
}

