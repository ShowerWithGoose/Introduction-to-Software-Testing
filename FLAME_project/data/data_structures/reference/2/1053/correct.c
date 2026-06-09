#include<stdio.h>

int flag=0;
int count();//进行运算 
int number(int m);//得到单个数字 
int a=1;
char s[100];

int main(){
	int n;
	int i=0,j=0;
	char sizi[100];
	
	gets(sizi);//读取公式 
	
	while(sizi[i]!='='){
		if(sizi[i]!=' '){
			s[j]=sizi[i];
			j++;
		}
	i++;
	}//删掉空格 
	sizi[i]='=';
	
	n=count();
	
	printf("%d",n);
	return 0;
}
int number(int m){
	flag++;
	while((s[flag]<='9')&&(s[flag]>='0')){
		m=m*10+s[flag]-'0';
		flag++;
	}
	return m;
}
int count(){
	int sum=0;
	while(1){
		if((s[flag]<='9')&&(s[flag]>='0')){
				a*=number(s[flag]-'0');
			}else if(s[flag]=='+'){
				flag++;
				sum+=a;
				a=1;
			}else if(s[flag]=='-'){
				flag++;
				sum+=a;
				a=-1;
			}else if(s[flag]=='*'){
				flag++;
				a*=number(s[flag]-'0');
			}else if(s[flag]=='/'){
				flag++;
				a/=number(s[flag]-'0');
			}else{
				sum+=a;
				break;
			}
	}
	return sum;
}






