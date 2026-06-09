#include<stdio.h>
char s[500]; 
char op[200];
int num[200];
int number[100];
int main()
{
	int i,j=0,k=0;
	int result;
	gets(s);
	for(i=0;s[i]!='=';i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') 
			op[j++]=s[i];
		else if(s[i]>='0'&&s[i]<='9')
		{
			if(s[i-1]>='0'&&s[i-1]<='9') 
			{
				k=k-1;
				num[k]=10*num[k]+s[i]-'0';
				k++;
			}
			else
				num[k++]=s[i]-'0';
		} 
	}
	k=0;
	for(i=0;num[i]!='\0';i++)
	{
		j=0;
		number[k]=num[i];
		if(op[i]=='*')
		{
			if(op[i+1]=='+'||op[i+1]=='-')
			{
				number[k]=num[i]*num[i+1];
				i++;
			}
			else
			{
				while(op[i+j]=='*'||op[i+j]=='/') 
				{
					if(op[i+j]=='*')
						number[k]*=num[i+j+1];
					else if(op[i+j]=='/')
						number[k]/=num[i+j+1];
					j++;
				}
				i=i+j;
			}
		}	
		else if(op[i]=='/')
		{
			if(op[i+1]=='+'||op[i+1]=='-')
			{
				number[k]=num[i]/num[i+1];
				i++;
			}
			else
			{
				while(op[i+j]=='*'||op[i+j]=='/') 
				{
					if(op[i+j]=='*')
						number[k]*=num[i+j+1];
					else if(op[i+j]=='/')
						number[k]/=num[i+j+1];
					j++;
				}
				i=i+j;
			}
		}
		k++;
	}
	j=1;
	result=number[0];
	for(i=0;op[i]!='\0';i++)
	{
		if(op[i]=='+') result+=number[j++];
		else if(op[i]=='-') result-=number[j++];
	}
	if(op[0]=='\0') result=num[0];
		
	printf("%d",result);
}

