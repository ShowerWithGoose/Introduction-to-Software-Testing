#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100
int level(char c);char op_stack[M];
	int num_stack[M];
	int num_top=-1;
	int op_top=-1;
void POP(); 
int cal(int a,int b,char c);
int main(){
	char s1[M],c;
	
	int i=0,temp=0,j=0,k=0;
	gets(s1);
	char s[M];
	while(s1[j]!='\0') {
		if (s1[j]!=' '){
		s[k]=s1[j];
		k++;
		}
		j++;	
	}
	s[k]='\0';	
	while((c=s[i++])!='\0'){
		if(i==1&&s[0]=='-')
		c=s[i++];
		if(isdigit(c)){
			do{
				temp=temp*10+c-'0';
			}while(isdigit(c=s[i++]));
		if(num_top==-1&&s[0]=='-')
		temp=-temp;
		num_stack[++num_top]=temp;
		temp=0;
		}
		switch(c){
			case '=':
			while(op_top!=-1&&num_top>0){
				POP();
			}
			break;
			case '+':
			case '-':
			case '*':
			case '/':
			if(level(op_stack[op_top])<level(c)||op_top==-1){
				op_stack[++op_top]=c;
			}
			else {
				while(level(op_stack[op_top])>=level(c)&&op_top>-1){//一定一定不能忘记了&&op_top>-1
					POP();
				}
				op_stack[++op_top]=c;
			}	
		}
	}
	printf("%d",num_stack[num_top]);
	return 0;
}
int level(char c){
	if(c=='+'||c=='-') return 1;
	if(c=='*'||c=='/') return 2;
}
void POP(){
	int m,n,res;
	char i;
	m=num_stack[num_top--];
	n=num_stack[num_top--];
	i=op_stack[op_top--];
	res=cal(n,m,i);
	num_stack[++num_top]=res;
}
int cal(int a,int b,char c){
	switch(c){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			if(b!=0)
			return a/b;
	}
}

