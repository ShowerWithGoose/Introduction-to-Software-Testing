#include<stdio.h>

int stack[1005],ff[1005],l1=0,l2=0;
char ch;

int check(int o)
{
	return ((o>='0')&&(o<='9'))||(o=='+')||(o=='-')||(o=='=')||(o=='*')||(o=='/');
}

int main()
{
	ch=getchar();
	while(1)
	{
		while(!check(ch)) ch=getchar();
		if(ch=='=') break;
		if(ch>='0'&&ch<='9')
		{
			int x=0;
			while(ch>='0'&&ch<='9')
			{
				x=x*10+ch-'0';
				ch=getchar();
			}
			stack[++l1]=x;
		}else 
		{
			ff[++l2]=ch;
			ch=getchar();
		}
		if((l2>0)&&(l1==(l2+1))&&(ff[l2]=='*'||ff[l2]=='/'))
		{
			if(ff[l2]=='*') stack[l1-1]*=stack[l1];
			if(ff[l2]=='/') stack[l1-1]/=stack[l1];
			l1--;l2--;
		}
	}
	l2=1;
	for(int i=2;i<=l1;i++)
	{
		if(ff[l2]=='+') stack[i]=stack[i-1]+stack[i];
		if(ff[l2]=='-') stack[i]=stack[i-1]-stack[i];
		l2++;
	}
	printf("%d\n",stack[l1]);
	return 0;
}

