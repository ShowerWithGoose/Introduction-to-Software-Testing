#include<stdio.h>
#include<string.h>
int main()
{char str[400],fu[100];
int i,j,n[100]={0},l,nbr=0,n1;
gets(str);
l=strlen(str);
for(i=0,j=0;i<l;i++)
	{if(str[i]==' ')
		continue;
	str[j++]=str[i];
	}
str[j]='\0';
j=0;
l=0;
for(i=0;str[i]!='=';)
	{if(str[i]>='0'&&str[i]<='9')
			{while(str[i]>='0'&&str[i]<='9')
			n[j]=n[j]*10+str[i++]-'0';
			j++;
			}
	else
		fu[l++]=str[i++];
	}
fu[l]='=';
j=0;
for(i=0;i<=l;i++)
	{if(fu[i]=='*'||fu[i]=='/')
		{n1=n[i];
			while(fu[i]=='*'||fu[i]=='/')
				{if(fu[i]=='*')
					n1*=n[i+1];
				else
					n1/=n[i+1];
				i++;
				}
		n[j++]=n1;
		}
	else
		n[j++]=n[i];
	}
nbr=n[0];
j=1;
for(i=0;i<l;i++)
	{if(fu[i]=='-')
		nbr-=n[j++];
	if(fu[i]=='+')
		nbr+=n[j++];
	}
printf("%d",nbr);
return 0;
}

