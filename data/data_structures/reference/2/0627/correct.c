#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int count[1000];
	char str[1000],str1[1000];
	char str2[1000],str3[1000];
	gets(str);
	int i,j,k; 
	int a=0,b=0,c=0;
	int n;
	for(i=j=0;str[i]!='\0';i++)
	{
		if(str[i]!=0)
		str1[j]=str[i];
		j++;
	}
	str1[j]='\0';
	for(i=j=k=0;str1[i]!='\0';i++)
	{
		if(str1[i]<='9'&&str1[i]>='0')
		{
		count[j]=str1[i]-'0';
		for(n=i+1;str1[n]>='0'&&str1[n]<='9';n++)
		{
			count[j]=count[j]*10+str1[n]-'0';
		}
		i=n;
		j++;
		a=j;
	    }//j为数字个数 
		if(str1[i]=='+'||str1[i]=='-'||str1[i]=='*'||str1[i]=='/')
		{
			str2[k]=str1[i];
			k++;
		} //k为符号数量 
		b=k;
	}
	str2[k]='\0';	
	if(b==0)
	printf("%d",count[0]);
	
	
	
	else
	{
	for(i=0;str2[i]!='\0';i++)
	{
		if(str2[i]=='*'||str2[i]=='/')
	    {
	    	if(str2[i]=='*')
	    	{
	        count[i+1]=count[i+1]*count[i];
	        count[i]=0;
	        }
	    	if(str2[i]=='/')
	    	{
	    	count[i+1]=count[i]/count[i+1];
	    	count[i]=0;
	        }
		}
		
	}
	int m[1000];
	for(i=j=0;str2[i]!='\0';i++)
	{
		if(str2[i]=='-'||str2[i]=='+')
		{
			str3[j]=str2[i];
			j++;
		}
	}
	str3[j]='\0';
	for(i=j=0;i<a;i++)
	{
		if(count[i]!=0)
		{
		m[j]=count[i];
		c=m[j];
		j++;
	    }
	}
	for(i=0;str3[i]!='\0';i++)
	{
		if(str3[i]=='-')
		m[i+1]=m[i]-m[i+1];
		if(str3[i]=='+')
		m[i+1]=m[i+1]+m[i];
		c=m[i+1];
	}
	printf("%d",c);
    }
	return 0;
}

