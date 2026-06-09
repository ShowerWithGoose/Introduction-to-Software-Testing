#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>


char post[100]={};
int cal[100]={};

int op(char c){
	if(c=='+'||c=='-'){
		return 1;
	}
	else if(c=='*'||c=='/'){
		return 2;
	}
	else if(c=='('){
		return 3;
	}
	else return 0;
}

int main()
{
	char in;
	char stack[100]={};
	int i=0,top=-1;
	while(scanf("%c",&in)!=EOF){
		if(in=='='){
			while(top>=0){
				post[i++]=stack[top--];
			}
			break;
		}
		else if(in==' '){
			continue;
		}
		else if(in>='0'&&in<='9'){
			post[i++]=in;
		}
		else if(in==')'){
			while(stack[top]!='('){
				post[i++]=stack[top--];
			}
			stack[top--]='\0';
		}
		else{
			post[i++]=' ';
			while(op(stack[top])>=op(in)&&stack[top]!='('&&top>=0){//要判断栈不空 
				post[i++]=stack[top];
				post[i++]=' '; 
				stack[top--]='\0';
			}
			stack[++top]=in;
		}	
	}
//	puts(post); 
//已经形成了后缀表达式,数字与数字之间都有空格分开 
	top=-1;
	for(i=0;post[i]!='\0';i++){
 		int num=0;
		if(post[i]>='0'&&post[i]<='9'){
			while(post[i]>='0'&&post[i]<='9'){
				num*=10;
				num+=post[i]-'0';
				i++;
			}
			i--;
			cal[++top]=num;	
		}
		else if(post[i]==' '){
			continue;
		}
		else{
			double right=cal[top];
			cal[top]=0;
			double left =cal[--top];
			if(post[i]=='+'){
				cal[top]=left+right;
			}
			else if(post[i]=='-'){
				cal[top]=left-right;
			}
			else if(post[i]=='*'){
				cal[top]=left*right;
			}
			else if(post[i]=='/'){
				cal[top]=left/right;
			}
		}
	}
	printf("%d",cal[top]);
	return 0;
}

