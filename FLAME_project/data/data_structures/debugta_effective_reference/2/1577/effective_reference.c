#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int datoi(char m[]){
	int i,temp=0;
	for(i=0;m[i]!='\0';i++)
	temp=10*temp+m[i]-'0';
	return temp;
}
//字母变数 
void dele(char *s){
	int i,k;
	for(i=k=0;s[i]!='\0';i++)
	if(s[i]!=' ')
	s[k++]=s[i];
	s[k]='\0';
}
//删空格 
void numb(char *s,int num[]){
	int i,k,m=1;
	char a[1000];
	for(i=0;s[i]!='\0';i++){
		k=0;
		while(s[i]>='0'&&s[i]<='9')
		a[k++]=s[i++];
		a[k]='\0';
		num[m++]=datoi(a);
	}
	num[m]=-1;
}
//提取数字 
int calcu(int *shu,int *hao){
	int i,k,num[1000],m=1,fu[1000],n=1,fin=0;
	num[1]=shu[1];
	for(k=1;shu[k]>=0&&hao[k]!=0;k++){
		if(hao[k]==3||hao[k]==4){
			if(hao[k]==3)
			num[m]*=shu[k+1];
			else if(hao[k]==4)
			num[m]/=shu[k+1];
		}//计算乘除法 
		else if(hao[k]==1||hao[k]==2){
			if(hao[k]==1)
			fu[n++]=1;
			else if(hao[k]==2)
			fu[n++]=2;
			num[m+1]=shu[k+1];
			m++;
		}//提取加减号
	}
	fin=num[1];
	for(i=1;i<n;i++){
		if(fu[i]==1)
		fin+=num[i+1];
		else if(fu[i]==2)
		fin-=num[i+1];
	}//计算加减法 
	return fin;
}
//计算 
void swit(char*s,int fu[]){
	int i,m=1;
	for(i=0;s[i]!='=';i++){
		if(s[i]=='+')
		fu[m++]=1;
		else if(s[i]=='-')
		fu[m++]=2;
		else if(s[i]=='*')
		fu[m++]=3;
		else if(s[i]=='/')
		fu[m++]=4;
	}
	fu[m]=0;
}//提取符号 
int main(){
	int ans,num[1000],fu[1000];
	char s1[1000];
	gets(s1);
	dele(s1);
	numb(s1,num);
	swit(s1,fu);
	ans=calcu(num,fu);
	//printf("%d",swit(s1)[5]);
	//printf("%d",numb(s1)[5]);
	printf("%d",ans);
	return 0;
}

