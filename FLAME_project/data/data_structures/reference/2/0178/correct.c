#include<stdio.h>
int add1=0,add2=0,temp=0;
char c,pc='+',ppc='+';
inline void f(char ch)
{
	switch(ch)
	{
		case '+':
			add2+=temp;
			break;
		case '-':
			add2-=temp;
			break;
		case '*':
			add2*=temp;
			break;
		case '/':
			add2/=temp;
			break;
	}
	temp=0;
}
int main()
{
	while(1)
	{
		c=getchar();
		switch(c)
		{
			case '+':
				f(pc);
				add1+=add2;
				add2=0;
				pc='+';
				ppc='+';
				break;
			case '-':
				f(pc);
				add1+=add2;
				add2=0;
				pc='-';
				ppc='-';
				break;
			case '*':
				f(pc);
				pc='*';
				break;
			case '/':
				f(pc);
				pc='/';
				break;
			case '=':
				f(pc);
				add1+=add2;
				break;
			case ' ':
				continue;
				break;
			default:
				temp*=10;
				temp+=c-48;
				break;
		}
		if(c=='=')	break;
	}
	printf("%d",add1);
	return 0;
}

