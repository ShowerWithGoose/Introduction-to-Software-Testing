#include<stdio.h>
#include<string.h>
int main(){
	char s[10005]="",str[10005]="",symbol[10005]="";
	int cnt,k=0,i,j=0,num[10005]={0},n=0,count,flag;
	gets(s);
	for(cnt=0;cnt<=strlen(s);cnt++){
		if(s[cnt]!=' '){
			str[k]=s[cnt];
			k++;
		}
	}//在s中删除空格键储存在str中 
	
	cnt=0; 
	for(i=0;str[i]!='=';){
		if(str[i]<='9'&&str[i]>='0'){
			for(;str[i]<='9'&&str[i]>='0';i++){
				n=10*n+str[i]-'0';
			}
			num[j]=n;
			n=0;
			j++;
		}
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
			symbol[j]=str[i];
			cnt++; //记录共有几个符号
			i++;
			j++;
		}
	}//数字存放在num[]数组中
	 //符号存放在symbol[]字符数组中 
	symbol[cnt*2+1]='=';
	flag=cnt*2+1;
	n=num[0];
	for(i=0;i<=flag;i++){
		if(symbol[i]=='*'){
			count=num[i-1]*num[i+1];
			num[i+1]=count;
		}
		if(symbol[i]=='/'){
			count=num[i-1]/num[i+1];
			num[i+1]=count;
		}
	}//先计算乘除 
	for(i=0;i<=flag;i++){
		if(symbol[i]=='+'){
			j=i-1;
			i++;
			while(i<flag){
				if(symbol[i]=='+'||symbol[i]=='-')
					break;
				else i++;
			}
			i--;
			k=i;
			n=num[j]+num[k];
			num[i]=n;
		}
		if(symbol[i]=='-'){
			j=i-1;
			i++;
			while(i<flag){
				if(symbol[i]=='+'||symbol[i]=='-')
					break;
				else i++;
			}
			i--;
			k=i;
			n=num[j]-num[k];
			num[i]=n;
		}
	}
	
	printf("%d",n);	
	return 0;
}



