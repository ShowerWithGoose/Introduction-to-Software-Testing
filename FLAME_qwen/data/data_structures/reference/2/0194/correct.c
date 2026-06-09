#include<stdio.h>
#include<string.h>
int main()
{	char a[1005],b[1005],ch[1005];
	int i=0,j=0,k=0,l=0,num[1005];
	memset(num,0,sizeof(num));
	gets(a);
	for(i=0;i<strlen(a);i++)
	if(a[i]!=' '&&a[i]!='=')
	b[j++]=a[i];
	b[j]='\0';
	for(i=0;i<strlen(b);i++)
	{	while(b[i]>='0'&&b[i]<='9')
		num[k]*=10,num[k]+=b[i++]-'0';
		k++;
		if(b[i]=='+'||b[i]=='-'||b[i]=='/'||b[i]=='*')
		ch[l++]=b[i];
	}
	ch[l]='\0';
	for(i=0;i<l;i++)
	{	if(ch[i]=='*')
		{	num[i]*=num[i+1];
			for(j=i+1;j<k-1;j++)
			num[j]=num[j+1];
			k--;
			for(j=i;j<l-1;j++)
			ch[j]=ch[j+1];
			l--;
			i--;
		}
		else if(ch[i]=='/')
		{	num[i]/=num[i+1];
			for(j=i+1;j<k-1;j++)
			num[j]=num[j+1];
			k--;
			for(j=i;j<l-1;j++)
			ch[j]=ch[j+1];
			l--;
			i--;
		}
	}
	for(i=0;i<l;i++)
	{	if(ch[i]=='+')
		{	num[i]+=num[i+1];
			for(j=i+1;j<k-1;j++)
			num[j]=num[j+1];
			k--;
			for(j=i;j<l-1;j++)
			ch[j]=ch[j+1];
			l--;
			i--;
		}
		else if(ch[i]=='-')
		{	num[i]-=num[i+1];
			for(j=i+1;j<k-1;j++)
			num[j]=num[j+1];
			k--;
			for(j=i;j<l-1;j++)
			ch[j]=ch[j+1];
			l--;
			i--;
		}
	}
	printf("%d",num[0]);
	return 0;
}

