#include<stdio.h>
int f(int a1,char b,int a2){
	switch(b){
	case '-':
	return a1-a2;
	break;
	case '+':
	return a1+a2;
	break;
	case '*':
	return a1*a2;
	break;
	case '/':
	if(a2!=0)
	return a1/a2;
	break;	
	}
}
int readnumber(){
	int p; 
	scanf("%d",&p);
	return p;
}
int read(){
	char a;
	do{
	scanf("%c",&a);
	}while(a==' ');
	return a;
}
int main(){
	int b1,b2,b3;
	char a1,a2;
	b1=readnumber();
	a1=read();
	if(a1=='='){
		printf("%d",b1);//排除如=第一个数后是等号的情况 
	}
	else {
		b2=readnumber();
		a2=read();
		if(a2=='='){
			printf("%d",f(b1,a1,b2));
		} 
		else{
		while(a2!='='){
			b3=readnumber();
			if((a1=='*'||a1=='/')||((a1=='+'||a1=='-')&&(a2=='+'||a2=='-'))){
				b1=f(b1,a1,b2);
				b2=b3;
				a1=a2;
			}
			else if(a2=='*'||a2=='/'){
				b2=f(b2,a2,b3);
			}
			 a2=read();
		}
		     printf("%d",f(b1,a1,b2));
	}
}
	         return 0;
}

