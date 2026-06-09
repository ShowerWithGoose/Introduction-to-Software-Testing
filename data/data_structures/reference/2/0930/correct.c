#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a[500];
char b[500];
int main()
{
	char ch[1000],str[1000];
	int ans=0,i,j,count1=0,count2=0,s=0,t=0,temp=0;
	gets(ch);
	for(i=0;ch[i]!='=';i++)
	{
		if(ch[i]!=' '&&ch[i]!='=')
		    str[j++]=ch[i];
	}
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			b[s++]=str[i];
			count1++;
			temp=0;
		}
		else
		{
			temp=temp*10+(str[i]-'0');
			if(!(str[i+1]>='0'&&str[i+1]<='9'))
				a[t++]=temp;
			count2++;
		}
	}
	i=0;
	while(i<count1)
	{
        if(b[i]=='-')
		{
			a[i+1]=-a[i+1];
		}
		i++;
	}
	i=0;
	while(i<count1)
	{
		if(b[i]=='*')
		{
			a[i+1]=a[i]*a[i+1];
			a[i]=0;
		}
		else if(b[i]=='/')
		{
			a[i+1]=a[i]/a[i+1];
			a[i]=0;
		}
		i++;
	}
	i=0;
	while(count2)
	{
		ans+=a[i++];
		count2--;
	}
	printf("%d\n",ans);
	return 0;
}

