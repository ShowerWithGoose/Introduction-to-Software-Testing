#include<stdio.h>
int cal(int,char,int);
int main(){
	char sign='+';
	int a[10000]={0},t,i=0,sum=0;
	do{
		scanf(" %d",&t);
		if(sign=='+'||sign=='-'){
			a[++i]=cal(0,sign,t);
		}
		else{
			a[i]=cal(a[i],sign,t);
		}
	}while(scanf(" %c",&sign),sign!='=');
	while(i){
		sum+=a[i--];
	}
	printf("%d",sum);
	return 0;
}
int cal(int a,char c,int b){
	switch(c){
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
		default:return NULL;
	}
}



