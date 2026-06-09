#include<stdio.h>
int readnum(){
	int num;
	scanf(" %d",&num);
	return num; 
}
char readop(){
	char op;
	scanf(" %c",&op);
	return op;
}
int forluma(int a,int b,char op){
	int ans=0;
    if(op=='+')ans=a+b;
    if(op=='-')ans=a-b;
    if(op=='*')ans=a*b;
	if(op=='/')ans=a/b; 
	return ans;
}
int main(){
	int a[2];
	char b[1];
	char op;
	int num;
	a[0]=readnum();
	b[0]=readop();
	if(b[0]!='='){
		a[1]=readnum();
		while(b[0]!='='){
			if(b[0]=='*'||b[0]=='/'){
				a[0]=forluma(a[0],a[1],b[0]);
				b[0]=readop();
				if(b[0]!='='){
					a[1]=readnum();
				}
			}
            else{
            	op=readop();
            	if(op=='+'||op=='-'||op=='='){
            		a[0]=forluma(a[0],a[1],b[0]);
            		b[0]=op;
            		if(b[0]!='='){
            			a[1]=readnum();
					}
				}
				else{
					num=readnum();
					a[1]=forluma(a[1],num,op);
				}

		    }
     	}
    }
    else{
    	a[0]=a[0];
	}
	printf("%d",a[0]);
	return 0;
}


