#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int top=-1,num_top=-1;
char stack[100];int num_stack[100];
char s[200];
int is_empty(){
	if(top==-1){
		return 1;
	}else{
		return 0;
	}
}
int is_full(){
	if(top==99){
		return 1;
	}else{
		return 0;
	}
}
void push(char item){
	stack[++top]=item;
}
void num_push(int num_item){
	num_stack[++num_top]=num_item;
}
char pop(){
	return stack[top--];
}
int num_pop(){
	return num_stack[num_top--];
}
int pri(char x){
    switch(x){
        case '+':
            return 0;
        case '-':
            return 0;
        case '*':
            return 1;
        case '/':
            return 1;
        case '%':
            return 1;
        case '(':
            return 2;
        case ')':
            return 2;
    }
}
int cal(char op,int num1,int num2)
{
    switch(op){	
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '*':
            return num1*num2;
        case '/':
            return num1/num2;
    }
}
int main(){
	int i;
	int num1,num2,num3;
	char op;
	gets(s);
	int len=strlen(s);
    for(i=0;i<len;i++){
        if(isdigit(s[i])){
            int num=0;
            while(isdigit(s[i])){
                num=num*10+s[i]-'0';
                i++;
            }
            num_push((int)num);
        }
        if(s[i]==' ') continue;
		if(s[i]=='=') break;
		if(s[i]==')'){
			while(1){
				op=pop();
				if(op=='(') break;
				num2=num_pop();
				num1=num_pop();
				num3=cal(op,num1,num2);
				num_push(num3);				
			}
		}else{
			if(is_empty()){
				push(s[i]);
				continue;
			}
			char stack_top=stack[top];
			while(pri(stack_top)>=pri(s[i])){
                if(stack_top=='(') break;
                op=pop();
                num2=num_pop();
                num1=num_pop();
                num3=cal(op,num1,num2);
                num_push(num3);
                if(is_empty()) break;
                stack_top=stack[top];
            }
            push(s[i]);
		}
    }
    while(!is_empty()){
        op=pop();
        num2=num_pop();
        num1=num_pop();
        num3=cal(op,num1,num2);
        num_push(num3);
    }
    int res=num_pop();
    printf("%d",res);
	return 0;
}

