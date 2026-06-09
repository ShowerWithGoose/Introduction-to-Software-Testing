#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int Num()
{
	int num;
	scanf("%d",&num);
	return num;
}
char Op()
{
	char op;
	do
    {
        scanf("%c",&op);
    }while(op==' ');
	return op;
}
int f(int a,int b,char op)
{
	int res;
	if (op=='+')
		res=a+b;
	else if(op=='-')
		res=a-b;
	else if(op=='*')
		res=a*b;
	else
		res=a/b;
	return res;
}

int main()
{
    int a[2];
    char b[1];
	char op;
	int num;
    a[0]=Num();
	b[0]=Op();
	if (b[0]!='=')
		a[1]=Num();
    while (b[0]!='=')
	{
		if(b[0]=='*'||b[0]=='/')
		{
			a[0]=f(a[0],a[1],b[0]);
			b[0]=Op();
			if (b[0]!='=')
				a[1]=Num();
		}
		else
		{
			op=Op();
			if(op=='+'||op=='-'||op=='=')
			{
				a[0]=f(a[0],a[1],b[0]);
				b[0]=op;
				if(op!='=')
					a[1]=Num();
			}
			else if(op!='=')
			{
				num=Num();
				a[1]=f(a[1],num,op);
			}
			else
				b[0]=op;
		}
 
	}
	printf("%d\n", a[0]);
    return 0;
}


