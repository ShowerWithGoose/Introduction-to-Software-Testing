
/*#include<stdio.h>
#include<string.h>
int main()
{
	char s[999999],ans[999999];
	scanf("%s",s);
	ans[0]=s[0];
	int i=1,j=1,len,k,m;
	len=strlen(s)-1;
	for(i=1;i<=len-1;i++)
	{
		if(s[i]!='-'){
			ans[j]=s[i];
			j++;
		}
		else
		{
			if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1];
				for(m=1;m<k;m++){
					ans[j]=s[i-1]+m;
					j++;
				}
				continue;
			}
			if((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z')&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1];
				for(m=1;m<k;m++){
					ans[j]=s[i-1]+m;
					j++;
				}
				continue;

			}
			if((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z')&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1];
				for(m=1;m<k;m++){
					ans[j]=s[i-1]+m;
					j++;
				}
				continue;
			}
			else
			{
				ans[j]='-';
				j++;
			}
		}
	}
	ans[j]=s[i];
		printf("%s",ans);
	return 0;
}*/
/*#include<stdio.h>
#include<string.h>
long long f(char a[]);
int main()
{
	char a[10000],b[10000],n[100],c[100];
	long long num[100];
	long long ans;
gets(a);
	int i=0,j=0,k=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=' '&&a[i]!='\n'&&a[i]!='=')
		{
			b[j]=a[i];
			j++;
		}
	}
	j=0;
	for(i=0;i<strlen(b);i++)
	{
		if(b[i]!='+'&&b[i]!='-'&&b[i]!='*'&&b[i]!='/')
		{
			n[j]=b[i];
			j++;
		}
		else
		{
			c[k]=b[i];
			num[k]=f(n);
			k++;
			memset(n,'\0',strlen(n));
			j=0;
		}
	}
	num[k]=f(n);
	for(k=0;k<strlen(c);k++)
	{
		if(c[k]=='*')
		{
			num[k+1]=num[k]*num[k+1];
			num[k]=-9999999;
			continue;
		}
		if(c[k]=='/')
		{
			num[k+1]=num[k]/num[k+1];
			num[k]=-9999999;
			continue;
		}
	}
	for(k=0;k<strlen(c);k++)
	{
		j=k+1;
		if(c[k]=='+'){
			while(num[j]==-9999999)
			{
				j++;
			}
			num[j]=num[k]+num[j];
			continue;
		}
		if(c[k]=='-'){
			while(num[j]==-9999999)
			{
				j++;
			}
			num[j]=num[k]-num[j];
			continue;
		}
	}
printf("%lld",num[k]);
return 0;
}
long long f(char a[])
	{
		int l,k,math=0;
		l=strlen(a);
		for(k=0;k<l;k++)
		{
			math=math*10+(a[k]-'0');
		}
		return math;
	}*/
	#include<stdio.h>
	#include<string.h>
	int main()
	{
		char s[500];
		scanf("%s",s);
		int flag=0,i,bj,ln=0;
		for(i=0;i<strlen(s)-1;i++)
		{
			if(s[i]=='.')
			flag=1,bj=i;
		}
		if(flag==0){
			if(strlen(s)==1)
			{
				printf("%se0",s);
				return 0;
			}
			else
			{
				for(i=0;i<strlen(s);i++)
				{
					printf("%c",s[i]);
					if(i==0&&s[0]!='-')
					printf(".");
					if(i==1&&s[0]=='-')
					printf(".");
				}
				printf("e%d",strlen(s)-1);
				return 0;
			}
		}
		else{
			
			if(s[0]!='-'&&bj>1){
				for(i=0;i<strlen(s);i++)
				{
					if(i!=bj)
					{
						printf("%c",s[i]);
					}
					if(i==0)
					printf(".");
					
				}
				printf("e%d",bj-1);
				return 0;
			}
			else if(s[0]=='-'&&bj>2){
				for(i=0;i<strlen(s);i++)
				{
					if(i!=bj)
					{
						printf("%c",s[i]);
					}
					if(i==1)
					printf(".");
					
				}
				printf("e%d",bj-2);
				return 0;
			}
			else if(s[0]!='-'&&bj==1){
				if(s[0]!='0'){
					for(i=0;i<strlen(s);i++)
				{
					if(i!=bj)
					{
						printf("%c",s[i]);
					}
					if(i==0)
					printf(".");
					
				}
				printf("e%d",bj-1);
				return 0;
				}
				else{
					for(i=bj+1;i<strlen(s);i++){
						if(s[i]=='0')
						ln++;
						else
						break;
					}
					printf("%c",s[i]);
					if(i<strlen(s)-1)
					printf(".");
					for(i++;i<strlen(s);i++){
						printf("%c",s[i]);
					}
					printf("e-%d",ln+1);
					return 0;
				}
			}
			else if(s[0]=='-'&&bj==2)
			{
					if(s[1]!='0'){
					for(i=1;i<strlen(s);i++)
				{
					printf("-");
					if(i!=bj)
					{
						printf("%c",s[i]);
					}
					if(i==0)
					printf(".");
					
				}
				printf("e%d",bj-1);
				return 0;
				}
				else{
					for(i=bj+1;i<strlen(s);i++){
						if(s[i]=='0')
						ln++;
						else
						break;
					}
					printf("-%c.",s[i]);
					for(i++;i<strlen(s);i++){
						printf("%c",s[i]);
					}
					printf("e-%d",ln+1);
					return 0;
				}
			}
		}
		return 0;
	}



