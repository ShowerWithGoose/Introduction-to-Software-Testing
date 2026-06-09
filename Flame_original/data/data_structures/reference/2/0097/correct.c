#include<stdio.h>
int readnum(){
	int num;
	scanf("%d",&num);
	return num;
} 
char readop(){
    char op;
    int ret=scanf("%c",&op);
    while(op==' '&&ret!=EOF)
        ret =scanf("%c",&op);
    return op;
}
int jisuan(int a1,char b,int a2){
	int re;
	if(b=='+'){
		re=a1+a2;
	}
	if(b=='-'){
		re=a1-a2;
	}
	if(b=='*'){
		re=a1*a2;
	}
	if(b=='/'){
		re=a1/a2;
	}
	return re;
}
int main(){
	int num[100];
	char op[100];
	num[0]=readnum();
	op[0]=readop();
	if(op[0]=='='){
		printf("%d",num[0]);
	}
else{
	  num[1]=readnum();
	op[1]=readop();
	if(op[1]=='='){
		printf("%d",jisuan(num[0],op[0],num[1]));
	}
	else {
		
	
	num[2]=readnum();
	op[2]=readop();
	int re1num[100];
	int re2num[100];
	char re1op[100];
	char re2op[100];
	int i;
	if((op[0]=='+'||op[0]=='-')&&(op[1]=='*'||op[1]=='/')){
		re1num[0]=num[0];
		re2num[0]=jisuan(num[1],op[1],num[2]);
		re1op[0]=op[0];
		re2op[0]=op[2];
	}
	else{
		re1num[0]=jisuan(num[0],op[0],num[1]);
		re2num[0]=num[2];
		re1op[0]=op[1];
		re2op[0]=op[2];
	}
	//printf("%d %c %d %c\n",re1num[0],re1op[0],re2num[0],re2op[0]);
	for(i=0;re2op[i]!='=';i++){
		num[i+3]=readnum();
		op[i+3]=readop();
		if((re1op[i]=='+'||re1op[i]=='-')&&(re2op[i]=='*'||re2op[i]=='/')){
			re1num[i+1]=re1num[i];
			re2num[i+1]=jisuan(re2num[i],re2op[i],num[i+3]);
			re1op[i+1]=re1op[i];
			re2op[i+1]=op[i+3];
		}
		else{
			re1num[i+1]=jisuan(re1num[i],re1op[i],re2num[i]);
			re2num[i+1]=num[i+3];
			re1op[i+1]=re2op[i];
			re2op[i+1]=op[i+3];
		}
		
		
	}
/*	for(i=0;re1op[i]!='\0';i++){
		printf("%d %c %d %c\n",re1num[i],re1op[i],re2num[i],re2op[i]);
	}*/

	printf("%d",jisuan(re1num[i],re1op[i],re2num[i]));}}
	return 0;
}
//可以数字和字符交错输入 






