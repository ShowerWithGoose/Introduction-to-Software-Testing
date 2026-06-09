#include<stdio.h>
#include<string.h>

int a[5000]; 
char b[5000];

int jisuan(int a,int b,char op){
	int jieguo;
	switch(op)
	{
		case'+':jieguo=a+b;break;
		case'-':jieguo=a-b;break;
		case'*':jieguo=a*b;break;
		case'/':jieguo=a/b;break;
	}
	return jieguo;
}

int number(){
	int num;
	scanf("%d",&num);
	return num;
}

char fuhao(){
	char op;
	scanf(" %c",&op);
	return op;
}

int main()
{
	int num;
	char op;
	a[0]=number();
	b[0]=fuhao();
	if(b[0]!='=')a[1]=number();
	while(b[0]!='='){
		if(b[0]=='*'||b[0]=='/'){
			a[0]=jisuan(a[0],a[1],b[0]);
			b[0]=fuhao();
			if(b[0]!='='){
				a[1]=number();
			}
		}
		else{
			op=fuhao();
			if(op=='+'||op=='-'||op=='='){
				a[0]=jisuan(a[0],a[1],b[0]);
				b[0]=op;
				if(op!='='){
					a[1]=number();
				}
			}
			else if(op!='='){
				num=number();
				a[1]=jisuan(a[1],num,op);
			}
			else b[0]=op;
		}
	}
	printf("%d\n",a[0]);
	
	return 0;
	
}



