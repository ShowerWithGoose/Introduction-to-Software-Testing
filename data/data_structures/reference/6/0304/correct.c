#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 100
typedef struct{
	int a[L];
	int top;
}Stack;
void InitStack(Stack *s){
	s->top=-1;
}
int Push(Stack *s,int e){
	if(s->top==L-1){
		return 1;
	}
	s->top++;
	s->a[s->top]=e;
	return 0;
}
int Pop(Stack *s){
	int e;
	if(s->top==-1){
		return 0;
	}
	e=s->a[s->top];
	s->top--;
	return e;
}
int main(){
	Stack *s,d;
	s=&d;
	InitStack(s);
	char ch[500];
	gets(ch);
	int i,j=0,flag=0;
	int e,k=0;
	for(i=0;i<strlen(ch);i++){
		if(flag==0){
			if(ch[i]=='1'){
				flag=1;
			}
			else if(ch[i]=='0'){
				flag=2;
			}
			else if(ch[i]=='-'){
				break;
			}
		}
		else{
			if(ch[i]<='9'&&ch[i]>='0'){
				j=j*10+ch[i]-'0';
			}
			else if(ch[i]=='-'){
				k=1;
			}
			else{
				if(flag==2){
					if((e=Pop(s))!=0){
						printf("%d ",e);
					}
					else{
						printf("error ");
					}
					flag=0;
				}
				else if(flag==1&&j!=0){
					if(k){
						e=-j;
					}
					else{
						e=j;
					}
					if(Push(s,e)){
						printf("error ");
					}
					j=0;
					k=0;
					flag=0;
				}
			}
		}
	}
	return 0;
}

