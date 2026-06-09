#include<stdio.h>
#include<string.h>
char insert[100],str_1[100];
int num[100],num_1[100];
char fuhao[100];
int cc(int x,int y,char m)
{
	if(m=='*') return x*y;
	else if(m=='/') return x/y;
}
int main()
{
	int i,j,k,ans=0;
	gets(insert);
	for(i=0,j=0;insert[i]!='=';i++)
	{
		if(insert[i]!=32)
		{
			str_1[j]=insert[i];
			j++;
		}
	}
	for(i=0,j=0;str_1[i]!='\0';i++)
	{
		if(str_1[i]>='0'&&str_1[i+1]>='0')
		{
			num[j]=num[j]*10+str_1[i]-'0';
		}
		else if(str_1[i]>='0'&&str_1[i+1]<'0')
		{
			num[j]=num[j]*10+str_1[i]-'0';
			j++;
		}
		else if(str_1[i]<'0')
			fuhao[j-1]=str_1[i];
	}
	if(fuhao[0]=='\0') printf("%d",num[0]);
	else
	{

	for(i=0;i<j-1;i++)
	{
		if(fuhao[i]=='-')
			num[i+1]=-num[i+1];
	}
	for(i=0,k=0;i<j;)
	{
		if(i==0&&((fuhao[i]=='+')||(fuhao[i]=='-')))
		{
			num_1[k]=num[i];
			i++;
			k++;
			continue;
		}
		if(fuhao[i]=='*'||fuhao[i]=='/')
		{
			num_1[k]=num[i];
			for(i;fuhao[i]=='*'||fuhao[i]=='/';i++)
			{
				num_1[k]=cc(num_1[k],num[i+1],fuhao[i]);
			}
			i++;
		}
		else if(i>1&&(fuhao[i-1]=='+'||fuhao[i-1]=='-')&&(fuhao[i]=='+'||fuhao[i]=='-'))
		{
			num_1[k]=num[i];
			i++;
		}
		else if(i==j-1&&(fuhao[i-1]=='+'||fuhao[i-1]=='-'))
		{
			num_1[k]=num[i];
			i++;
		}
		k++;
	}
	for(k=k-1;k>=0;k--)
		ans+=num_1[k];
	printf("%d",ans);	
	}

	return 0;
}

