#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int datoi(char m[]){
	int i,n=0;
	for(i=0;m[i]!='\0';i++)
	n=10*n+m[i]-'0';
	return n;
}
//字母变数 
void dele(char *s){
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	if(s[i]!=' ')
	s[j++]=s[i];
	s[j]='\0';
}
//删空格 
void numb(char *s,int num[]){
	int i,j,k1=1;
	char a[1000];
	for(i=0;s[i]!='\0';i++){
		j=0;
		while(s[i]>='0'&&s[i]<='9')
		a[j++]=s[i++];
		a[j]='\0';
		num[k1++]=datoi(a);
	}
	num[k1]=-1;
}
//提取数字 
int calcu(int *shu,int *hao){
	int i,j,bi[1000],k1=1,admi[1000],am=1,fin=0;
	bi[1]=shu[1];
	for(j=1;shu[j]>=0&&hao[j]!=0;j++){
		if(hao[j]==3||hao[j]==4){
			if(hao[j]==3)
			bi[k1]*=shu[j+1];
			else if(hao[j]==4)
			bi[k1]/=shu[j+1];
		}//计算乘除法 
		else if(hao[j]==1||hao[j]==2){
			if(hao[j]==1)
			admi[am++]=1;
			else if(hao[j]==2)
			admi[am++]=2;
			bi[k1+1]=shu[j+1];
			k1++;
		}//提取加减号
	}
	fin=bi[1];
	for(i=1;i<am;i++){
		if(admi[i]==1)
		fin+=bi[i+1];
		else if(admi[i]==2)
		fin-=bi[i+1];
	}//计算加减法 
	return fin;
}
//计算 
void swit(char*s,int fu[]){
	int i,k1=1;
	for(i=0;s[i]!='=';i++){
		if(s[i]=='+')
		fu[k1++]=1;
		else if(s[i]=='-')
		fu[k1++]=2;
		else if(s[i]=='*')
		fu[k1++]=3;
		else if(s[i]=='/')
		fu[k1++]=4;
	}
	fu[k1]=0;
}//提取符号 
int main(){
	int daan,num[1000],fu[1000];
	char s1[1000];
	gets(s1);
	dele(s1);
	numb(s1,num);
	swit(s1,fu);
	daan=calcu(num,fu);
	//printf("%d",swit(s1)[5]);
	//printf("%d",numb(s1)[5]);
	printf("%d",daan);
	return 0;
}

