#include <stdio.h>
#include <string.h>

int cul(int a,int b,char x)
{
	if(x=='+') return a+b;
	else if(x=='-') return a-b;
	else if(x=='*') return a*b;
	else return a/b;
}

int main()
{
	int im=0,jm=0;
	int i,j;
	long long a,b,c;
	int num[1000]={0};
	char m;
	char ch[1000]="";
	do{
		scanf("%d",&num[im++]);
		do{m=getchar();
		}while(m==' ');
		ch[jm++]=m;
	}while(ch[jm-1]!='=');
	im--;
	jm--;
	a=num[0];
	for(i=0;i<=im;i++)
	{
		if(ch[i]=='+'||ch[i]=='-')
		{
			j=i+1;
			b=num[j];
			while((ch[j]=='*'||ch[j]=='/')&&j<im)
			{
				c=num[j+1];
				b=cul(b,c,ch[j]);
				j++;
			}
			a=cul(a,b,ch[i]);
			i=j-1;
		}
		else if(ch[i]=='*'||ch[i]=='/')
		{
			a=cul(a,num[i+1],ch[i]);
		}
	}
	printf("%lld",a);
	return 0;
}

