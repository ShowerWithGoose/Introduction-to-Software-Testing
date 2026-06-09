#include<stdio.h>
int suan(int a,int b,char c);
int shu();
int fuhao(); 
int main(){
	int a[2];
	char b[1];
	int num;
	int op;
	a[0]=shu();
	b[0]=fuhao();
	if(b[0]!='=')
	a[1]=shu();
	while(b[0]!='='){
		if(b[0]=='*'||b[0]=='/'){
			a[0]=suan(a[0],a[1],b[0]);
			b[0]=fuhao();
			if(b[0]!='=')
			a[1]=shu();
			
		}
		else
		{
			op=fuhao();
			if(op=='+'||op=='-'||op=='=')
			{
				a[0]=suan(a[0],a[1],b[0]);
					if(op!='=')
				a[1]=shu();
				b[0]=op;
			
			}
			else if(op=='*'||op=='/'){
				num=shu();
				a[1]=suan(a[1],num,op);	
			}
		
			
		}
		
	}
	printf("%d",a[0]);
	return 0;
	
	
}
int suan(int a,int b,char c){
	int result;
	if(c=='+')
	result=a+b;
	else if(c=='-')
	result=a-b;
	else if(c=='*')
	result=a*b;
	else
	result=a/b;
	return result;
}
int shu(){
	int shu;
	scanf("%d",&shu);
	return shu;
}
int fuhao(){
	char fuhao;
	scanf(" %c",&fuhao);
	
	
	return fuhao;
}



