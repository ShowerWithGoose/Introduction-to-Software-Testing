#include<stdio.h>


char shizi[1000002]={};
int Afu[100002]={};
int calc(int a,int b,char c){
	switch (c) {
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			return a/b;
			break;
		default:
			return -1;
			break;
	}
	return 0;
}
int Bsuan(int i){
	//获取需要计算的区间距离
	int start=0,numL=0;
	char fu=0;
	
	if(Afu[i]==0) return 0;//处理开头负号
	if(i!=0) start=Afu[i-1]+1;
	//提取数字
	int temp=0,flag=0,numLtemp=0;
	while(1){
	for(;start<Afu[i];start++){
		if(shizi[start]=='*'||shizi[start]=='/')	{flag=1;break;}
		temp*=10;
		temp+=shizi[start]-'0';
	}
	if(flag==1){
		if(numLtemp==0) {
			numL=temp;
			numLtemp=1;
		}else{
			numL=calc(numL,temp,fu);
		}
		fu=shizi[start];
		start++;
		temp=0;flag=0;
	}else{
		if(fu!=0) numL=calc(numL,temp,fu);
		else numL=temp;
		return numL;
	}
	}
	
	
	
	
	
	
}


int main() {
	int i, j;
	long long temp=0,numL=0;
	int Alen=0;
	gets(shizi);
	//去空格
	for (i = j = 0; shizi[i] != '\0'; i++)
		if (shizi[i] != ' ')
			shizi[j++] = shizi[i];
	shizi[j] = '\0';
	//提取加减运算符位置
	for(int i=0;shizi[i]!='\0';i++){
		if(shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='='){
			Afu[Alen++]=i;
		}
	}
	
	//分块运算每一部分,
	
	for(int i=0;i<Alen;i++){
		
		temp=Bsuan(i);
		if(i==0) numL=temp;
		else{
			numL=calc(numL,temp,shizi[Afu[i-1]]);
		}
	}
	//先提取前半部分数字,则提取符号,再提取数字,运算,继续
	printf("%lld\n",numL);
	


	return 0;
}



