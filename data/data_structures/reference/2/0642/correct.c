#include<stdio.h>
int i,j,k,sum[105],tem,a[105],result,sign,z;
char s[1005];
int main()
{
	gets(s);
	for(i=0; ;i++)        // 终止条件s【i】是= 
	{
		if(s[i]==' ') continue;
		if(s[i]=='-') sign=1;
		else if(s[i]=='+') sign=0;
		while((s[i]-'0'>=0&&s[i]-'0'<=9))
		{
			tem=tem*10+s[i]-'0';              
			i++;
		}
		if(s[i]==' ') i++;
		if(s[i]=='+'||s[i]=='-'||s[i]=='=')
		{
			if(sign==1) sum[j]=-tem;
			else sum[j]=tem;
			tem=0;
			j++;
			if(s[i]=='-') sign=1;
			else if(s[i]=='+') sign=0;
			else if(s[i]=='=') break;
		}
		else if(s[i]=='/'||s[i]=='*')            //几个数字乘除 
		{
			if(s[i]=='/') k=1;               //k做标记乘除 
			else if(s[i]=='*') k=0;
			sum[j]=tem;
			tem=0;
			if(sign==1) 
			{
				sum[j]=-sum[j];
			}
			i++;
			if(s[i]==' ') i++;
			while(1)                        //遇到+-停止 
			{
				if(s[i]==' ') i++;
				while((s[i]-'0'>=0&&s[i]-'0'<=9))
				{
					tem=tem*10+s[i]-'0';             //存数字（被乘数被除数 
					i++;
				}
				if(s[i]==' ') i++;
				if(k==1) sum[j]/=tem;
				else if(k==0) sum[j]*=tem;
				tem=0;
				if(s[i]=='+'||s[i]=='-'||s[i]=='=') 
			    {
			    	if(s[i]=='-') sign=1;
			    	j++;
			    	break;
				}
				if(s[i]==' ') i++;
				if(s[i]=='/') k=1;               //k做标记乘除 
			    else if(s[i]=='*') k=0;
			    i++;
			    if(s[i]==' ') i++;
			} 
		}
		if(s[i]=='=') break;
	}
	for(i=0;i<=j;i++)
	{
		result+=sum[i];
	}
	printf("%d",result);
	return 0;
}

