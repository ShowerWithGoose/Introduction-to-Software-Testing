#include<stdio.h>
int cal(int a,int b,char op);	
int readNum();					
char readMark();					
 
int main()
{
	int a[2],num;
	char b[1],mark;
	a[0]=readNum();
	b[0]=readMark();
	if(b[0]!='=')
		a[1]=readNum();
	while(b[0]!='='){
		if(b[0]=='*'||b[0]=='/'){
			a[0]=cal(a[0],a[1],b[0]);
			b[0]=readMark();
			if (b[0]!='=')
				a[1]=readNum();
		}
		else{
			mark=readMark();
			if(mark=='+'||mark=='-'||mark=='='){
				a[0]=cal(a[0],a[1],b[0]);
				b[0]=mark;
				if(mark!='=')
					a[1]=readNum();
			}
			else if(mark!='='){
				num=readNum();
				a[1]=cal(a[1],num,mark);
			}
			else
				b[0]=mark;
		}
	}
	printf("%d",a[0]);
	return 0;
}
 
int cal(int a,int b,char op)
{
	int result;
	if(op=='+')
		result=a + b;
	else if(op=='-')
		result=a - b;
	else if(op=='*')
		result=a*b;
	else
		result=a/b;
	return result;
}
 
int readNum()
{
	int num;
	scanf(" %d",&num);
	return num;
}

char readMark()
{
	char op;
	scanf(" %c",&op);
	return op;
}



