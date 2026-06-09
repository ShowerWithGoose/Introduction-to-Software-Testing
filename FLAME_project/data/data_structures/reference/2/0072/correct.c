#include <stdio.h>
#include<string.h>
#include<math.h>
int shuzi(){
	int shuzi;
	scanf("%d",&shuzi);
	return shuzi;
}
char fuhao(){
	char fuhao;
	scanf(" %c",&fuhao);
	return fuhao;
	}
int yunsuan(int x,int y,char b){
	if(b=='+'){
		return x+y;
	}
	if(b=='-'){
		return x-y; 
	}
	if(b=='*'){
		return x*y;
	}
	if(b=='/'){
		return x/y;
	}
}
	int main(){
	int a[2],num;
	char b[1],op;
	a[0]=shuzi();
	b[0]=fuhao();
	if(b[0]!='='){
	a[1]=shuzi();}
	while(b[0]!='='){
		if(b[0]=='*'||b[0]=='/'){
			a[0]=yunsuan(a[0],a[1],b[0]);
			b[0]=fuhao();
			if(b[0]!='=')
			a[1]=shuzi();
		}
		else
		{
			op=fuhao();
			if(op=='+'||op=='-'||op=='=')
			{
				a[0]=yunsuan(a[0],a[1],b[0]);
					if(op!='=')
				a[1]=shuzi();
				b[0]=op;
			
			}
			else if(op=='*'||op=='/'){
				num=shuzi();
				a[1]=yunsuan(a[1],num,op);	
			}	
		}
	}
	printf("%d",a[0]);
	return 0;}



