#include<stdio.h>
#include<string.h>
int main() {
	char in1[1000];
	char in[1000];
	char sign[1000];
	int num[1000]= {0};
	gets(in1);
	int len1=strlen(in1);
	int i,j,k=0,t;
	for(i=0,t=0; i<len1; i++) { //去空格
		if(in1[i]!=' ') {
			in[t]=in1[i];
			t++;
		}
	}
	for(i=0,j=0; i<t; i++) {//把每个数和符号分别存入相应数组 
		if(in[i]<='9'&&in[i]>='0'&&in[i+1]<='9'&&in[i+1]>='0') {
			num[j]=num[j]*10+in[i]-'0';
		} else if(in[i]<='9'&&in[i]>='0'&&!(in[i+1]<='9'&&in[i+1]>='0')) {
			sign[k]=in[i+1];
			k++;
			num[j]=num[j]*10+in[i]-'0';
			j++;
		}
	}
	
	int lensign;
	int count=0;
	int m,p=0;
	char sign0[1000];
	for(i=0; i<k; i++) {
		if(sign[i]=='+'||sign[i]=='-'||sign[i]=='='){
			sign0[p]=sign[i];//存还没有运算的符号（+、-） 
			p++;
		}
		if(sign[i]=='*') {//乘法运算 
			num[i-count]=num[i-count]*num[i-count+1];
			count++;
			for(m=i-count+2; m<k-count; m++) {
				num[m]=num[m+1];
			}
		}
		else if(sign[i]=='/') {//除法运算 
			num[i-count]=num[i-count]/num[i-count+1];
			count++;
			for(m=i-count+2; m<k-count; m++) {
				num[m]=num[m+1];
			}
		}
	}

int sum=num[0];
	for(i=0; i<p; i++) {//加减法运算 
		if(sign0[i]=='+'){
			sum=sum+num[i+1];
		}
		if(sign0[i]=='-'){
			sum=sum-num[i+1];
		}
	}
	printf("%d",sum); //求值 
	return 0;

}

