#include<stdio.h>
#include<string.h>
int cal(int a,char i,int b)
{
    switch(i)
    {
    	case'+':return a+b;
    	case'-':return a-b;
    	case'*':return a*b;
    	case'/':return a/b;
	}
}
int main()
{
	int num,a[100]={0},result=0,i=0;
    char sign='+';
	do{
		scanf(" %d",&num);
		if(sign=='+'||sign=='-')
		a[++i]=cal(0,sign,num);
		else
		a[i]=cal(a[i],sign,num);
	}
	while(scanf(" %c",&sign),sign!='=');
	while(i)
	{
		result+=a[i--];
	}
	printf("%d",result);
	return 0;
}

