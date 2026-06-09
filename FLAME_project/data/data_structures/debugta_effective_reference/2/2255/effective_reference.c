#include<stdio.h>
#include<string.h>
#include<math.h>
char in[500]={0},op[100]={0};
int i,cnt,i,f;
int num[100]={0};
int main(){
	gets(in);//整行读入 
	for(i=0;in[i]!='\0';i++){//去除空格 
		if(in[i]==' '){
			for(cnt=0;in[i+cnt]!='\0';cnt++){
				in[i+cnt]=in[i+cnt+1];
			}
			i--;
		}
	}
	for(i=0,cnt=0;in[i]!='\0';i++){//按顺序存下所有的数和符号 
		if(in[i]>='0'&&in[i]<='9'){
			num[cnt]=num[cnt]*10+in[i]-'0';
		}
		else{
			op[cnt]=in[i];
			cnt++;
		}
	}
	op[cnt]='\0';
	for(i=0;op[i]!='\0';i++){//把所有的乘除运算算完 
		if(op[i]=='*'){
			num[i]=num[i]*num[i+1];
			for(i=0;op[i+i]!='\0';i++){//把所有后面的符号前移一位 
				op[i+i]=op[i+i+1];
			}
			for(i=1;i+i<=cnt-2;i++){//把所有数字前移一位 
				num[i+i]=num[i+i+1];
			}
			cnt--;//数字和符号总数减少了一个
			i--; 
		}
		else if(op[i]=='/'){
			num[i]=num[i]/num[i+1];
			for(i=0;op[i+i]!='\0';i++){//把所有后面的符号前移一位 
				op[i+i]=op[i+i+1];
			}
			for(i=1;i+i<=cnt-2;i++){//把所有数字前移一位 
				num[i+i]=num[i+i+1];
			}
			cnt--;//数字和符号总数减少了一个
			i--; 
		}
	}
	for(i=0;op[i]!='=';i++){//把所有的加减运算算完 
		if(op[i]=='+'){
			num[0]+=num[1+i];
		}
		else num[0]-=num[1+i];
	}
	printf("%d",num[0]);
}



