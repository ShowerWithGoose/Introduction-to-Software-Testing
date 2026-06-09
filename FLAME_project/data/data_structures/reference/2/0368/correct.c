#include <stdio.h>
#include <string.h>
char ch[10000],u[1000],u2[1000];
int num[10000]={0},num2[10000]={0};

int main()
{
	gets(ch);
	int i,j=0,k=0,ans,l=0;
	for(i=0;ch[i]!='\0';i++)
	{
		if(ch[i]!=' ')
		{
			ch[j]=ch[i];
			j++;
		}
	}
	ch[j]='\0';
	j=0;
	for(i=0;ch[i]!='=';i++)
	{
		while(ch[i]>='0' && ch[i]<='9')
		{
			num[j]*=10;
			num[j]+=ch[i]-'0';
			i++;
			if(ch[i]=='+' || ch[i]=='-'|| ch[i]=='*' || ch[i]=='/' || ch[i]=='=')
			{
	//			printf("%d\n",num[j]);
				j++;
			}
		}
		if(ch[i]=='+' || ch[i]=='-'|| ch[i]=='*' || ch[i]=='/')
		{
			u[k]=ch[i];
			k++;
		}
		if(ch[i]=='=')
			break;	
	}
	u[k]='=';
	//printf("%d\n",j);
	k=0;
	for(i=0;i<=j-1;i++)
	{
	//	printf("%d\n",num[i]);
		if(u[k]=='=')
		{
			if(k>0 && (u[k-1]=='+' || u [k-1]=='-'))
			{
				num2[l]=num[i];
				l++;
			}
			else if(k==0)
			{
				num2[l]=num[i];
				l++;
			 } 
			break;
		}
		if(u[k]=='+' || u[k]=='-')
		{
			if(k>0 && (u[k-1]=='*' || u[k-1]=='/'))
			{
				u2[l-1]=u[k];
				k++;
			}
			else
			{
				num2[l]=num[i];
		//		printf("%d\n",num2[l]);
				u2[l]=u[k];
				l++;
				k++;
			}
		}
		else
		{
			if(u[k]=='*')
			{
				if(k>0 && (u[k-1]=='+' || u[k-1]=='-'))
				{
					num2[l]=num[i]*num[i+1];
		//			printf("%d\n",num2[l]);
					l++;
				}
				else if(k==0)
				{
					num2[l]=num[i]*num[i+1];
					l++;
				}
				else
				{
					num2[l-1]*=num[i+1];
		//			printf("%d\n",num2[l-1]);
				}
				k++;
			}
			else
			{
				if(k>0 && (u[k-1]=='+' || u[k-1]=='-'))
				{
					num2[l]=num[i]/num[i+1];
		//			printf("%d\n",num2[l]);
					l++;
				}
				else if(k==0)
				{
					num2[l]=num[i]/num[i+1];
					l++;
				}
				else
				{
					num2[l-1]/=num[i+1];
		//			printf("%d\n",num2[l-1]);
				}
				k++;
			}
		}
	}
	ans=num2[0];
	for(i=0;i<=l-1;i++)
	{
		if(u2[i]=='+')
			ans+=num2[i+1];
		else
			ans-=num2[i+1];
	}
	printf("%d",ans);
	return 0;
}

