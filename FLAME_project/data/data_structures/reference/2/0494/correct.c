#include<stdio.h>
#include<string.h>
#define NUM 1
#define LOW 2
#define CAP 3
int num[1005],sz;
char form[1005];
void push(int a){
	num[sz++]=a;
}
void pop(){
	sz--;
}
int empty(){
	return sz==0;
}
int top(){
	return num[sz-1];
}
int size(){
	return sz;
}
char a;
int i,j,cnt;
char hold,oper[1005];
int type(char b){
	if(b=='*'||b=='/')return 5;
	if(b=='+'||b=='-')return 4;
	if(b<='9'&&b>='0')return NUM;
	if(b==' ')return -1;
}
int cal(int aa,int bb,char ope){
	switch(ope){
		case '+':return aa+bb;
		case '-':return aa-bb;
		case '*':return aa*bb;
		case '/':return aa/bb;
		default:return -1e9;
	}
}
int main(){
	gets(form);
	int len=strlen(form);
	for(i=0;i<len;i++){
		if(form[i]==' ')continue;
		if(form[i]=='='){
			int p=0;
			for(j=0;j<cnt;j++){
				int num1=num[p++],num2=num[p];
				num[p]=cal(num1,num2,oper[j]);
			}
			printf("%d\n",num[p]);
			break;
		}
		if(type(form[i])==NUM){
			int s=0;
			for(j=i;j<len&&type(form[j])==NUM;j++){
				s*=10;
				s+=form[j]-'0';
			}
			if(hold=='\0')push(s);
			else{
				int num1 = top();
				pop();
				push(cal(num1,s,hold));
				hold='\0';
			}
			i=j-1;
			continue;
		}
		if(type(form[i])==5){
			hold=form[i];
		}else{
			oper[cnt++]=form[i];
		}
	}
	return 0;
}


