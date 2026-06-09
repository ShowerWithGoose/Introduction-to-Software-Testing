#include<stdio.h>
#include<string.h>
#include<math.h>
char in[500]={0},op[100]={0};
int i,j,k,f;
int num[100]={0};
int main(){
	gets(in);//整行读入 
	for(i=0;in[i]!='\0';i++){//去除空格 
		if(in[i]==' '){
			for(j=0;in[i+j]!='\0';j++){
				in[i+j]=in[i+j+1];
			}
			i--;
		}
	}
	for(i=0,j=0;in[i]!='\0';i++){//按顺序存下所有的数和符号 
		if(in[i]>='0'&&in[i]<='9'){
			num[j]=num[j]*10+in[i]-'0';
		}
		else{
			op[j]=in[i];
			j++;
		}
	}
	op[j]='\0';
	for(k=0;op[k]!='\0';k++){//把所有的乘除运算算完 
		if(op[k]=='*'){
			num[k]=num[k]*num[k+1];
			for(i=0;op[k+i]!='\0';i++){//把所有后面的符号前移一位 
				op[k+i]=op[k+i+1];
			}
			for(i=1;k+i<=j-2;i++){//把所有数字前移一位 
				num[k+i]=num[k+i+1];
			}
			j--;//数字和符号总数减少了一个
			k--; 
		}
		else if(op[k]=='/'){
			num[k]=num[k]/num[k+1];
			for(i=0;op[k+i]!='\0';i++){//把所有后面的符号前移一位 
				op[k+i]=op[k+i+1];
			}
			for(i=1;k+i<=j-2;i++){//把所有数字前移一位 
				num[k+i]=num[k+i+1];
			}
			j--;//数字和符号总数减少了一个
			k--; 
		}
	}
	for(k=0;op[k]!='=';k++){//把所有的加减运算算完 
		if(op[k]=='+'){
			num[0]+=num[1+k];
		}
		else num[0]-=num[1+k];
	}
	printf("%d",num[0]);
}



