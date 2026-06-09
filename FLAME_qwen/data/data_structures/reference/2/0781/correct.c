#include<stdio.h>
#include<math.h>
#include<string.h>
int num1[100],num2[100];
char ch1[100],ch2[100],fuhao1[100],fuhao2[100];
int main(){
	gets(ch1);
	int i,j,n=0,m,k,a=0,b=0;
	for(i=j=0;ch1[i]!='=';i++){
		if(ch1[i]!=' '){
			ch2[j++]=ch1[i];
		}
	}
	for(i=j=m=0;ch2[i]!='\0';i++){
		if(ch2[i]>='0'&&ch2[i]<='9'){
			n=n*10+ch2[i]-'0';
		}
		else{
			num1[j++]=n;n=0;
			fuhao1[m++]=ch2[i];
		}
	}
	num1[j]=n;
	num2[0]=num1[0];
	for(k=0;fuhao1[k]!='\0';k++){
		if(fuhao1[k]=='+'||fuhao1[k]=='-'){
			num2[++a]=num1[k+1];
			fuhao2[b++]=fuhao1[k];
		}
		else if(fuhao1[k]=='*'){
			num2[a]*=num1[k+1];
		}
		else if(fuhao1[k]=='/'){
			num2[a]/=num1[k+1];
		}
	}
	int num=num2[0];
	for(int z=0;z<=b;z++){
		if(fuhao2[z]=='+'){
			num+=num2[z+1];
		}
		else {
			num-=num2[z+1];
		}
	}
	printf("%d",num);
}

