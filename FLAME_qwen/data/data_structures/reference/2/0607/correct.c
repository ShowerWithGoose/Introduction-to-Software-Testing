#include<stdio.h>
#include<string.h> 

int stack[10100],sym[10100],num=0,top1=0,top2=0;

void cal(){
	int i;
	//for(i=1; i<=top1; i++)	printf("%d ",stack[i]);
	//puts("");
	//for(i=1; i<=top2; i++)	printf("%d ",sym[i]);
	int x=stack[top1],tmp=sym[top2];
	while(tmp){
		if(tmp==9) x*=stack[--top1];
		else if(tmp==8) x=stack[--top1]/x;
		else if(tmp==4) x=stack[--top1]-x;
		else if(tmp==3) x+=stack[--top1];
		tmp=sym[--top2];
		stack[top1]=x;
	}
	printf("%d",stack[top1]);
}

void change(int k){
	int tmp=sym[top2],x=stack[top1];
	while(tmp+3>=k){
		if(tmp==9) x*=stack[--top1];
		else if(tmp==8) x=stack[--top1]/x;
		else if(tmp==4) x=stack[--top1]-x;
		else if(tmp==3) x+=stack[--top1];
		tmp=sym[--top2]; 
	}
	sym[++top2]=k; stack[top1]=x;
}

void judge(char a){
	if(a=='=') {
		cal();
		return;
	}
	int tmp=sym[top2];
	if(a=='+') {
		if(tmp<3) {
			sym[++top2]=3;
			return;
		}
		else change(3);
	}
	if(a=='-') {
		if(tmp<4) {
			sym[++top2]=4;
			return;
		}
		else change(4);
		
	}
	if(a=='*') {
		if(tmp<=4){
			sym[++top2]=9; 
			return;
		}
		else change(9);
	}
	if(a=='/') {
		if(tmp<=4){
			sym[++top2]=8;
			return;
		}
		else change(8);
	}
}

void deal(char a){
	if(a==' ') return;
	if(a!='+'&&a!='-'&&a!='*'&&a!='/'&&a!='='){
		num*=10;
		num+=a-'0';
		return;
	} 
	stack[++top1] = num; num=0;
	judge(a);
	
}


int main(){
	char st[10100];
	gets(st);
	int i;
	for(i=0; st[i]!='\0'; i++)
		deal(st[i]);
	
	return 0;
}




