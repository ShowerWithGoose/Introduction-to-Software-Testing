#include<stdio.h>
#include<string.h>
int isnum(char tmp[])
{
	int add,i=0,sign=0,num=0,flag=0;
	for(i=0;tmp[i]!='\0';)
	{
		flag=0;
		num=0;
		if(tmp[i]=='*')
		{
			sign=1;
			i++;
		}
		else if(tmp[i]=='/')
		{
			sign=-1;
			i++;
		}
		while(tmp[i]>='0'&&tmp[i]<='9')
		{
			num=num*10+tmp[i]-'0';
			i++;
			flag=1;
			
		}
		
		if(flag==1)
		{
			switch(sign)
			{
				case 0:
					add=num;
					break;
				case 1:
					add=add*num;
					break;
				case -1:
					add=add/num;
					break;
			}
		}
	}
	return add;
}

int main()
{
	char s1[1000],s2[1000],tmp[1000];
	int num[1000],symbol[1000],cnt=0,i,k=0,cnt1=0,result;
	gets(s1);
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]!=' ')s2[k++]=s1[i]; 
	}
	s2[k]='\0';
	k=0;
	for(i=0;s2[i]!='=';)
	{
		if(s2[i]!='-'&&s2[i]!='+')
		{
			while(s2[i]!='+'&&s2[i]!='-'&&s2[i]!='=')
			{
				tmp[k++]=s2[i];
				i++;
			}
			tmp[k]='\0';
			num[cnt1++]=isnum(tmp);
			k=0;
		}
		else if(s2[i]!='=')
		{
			symbol[cnt++]=(s2[i]=='+'?1:-1);
			i++;
		}
	}
	
		result=num[0];
		for(i=0;i<cnt;i++)
		{
			result=result+symbol[i]*num[i+1];
		}
	printf("%d",result);
	return 0;
	
}



