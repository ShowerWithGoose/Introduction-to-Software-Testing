#include<stdio.h>
#include<string.h>
int main(){
	int i=0; //记录总搜索
	int j=0; //记录单元搜索
	int j0=-1; //单元搜索首
	int symboli=1;
	int numberi=1; 
	char w[1000]; //记录式子
	char w1[1000]; //记录新式子 
	int number[1000]={0}; //记录数字
	char symbol[1000]; //记录符号
	int sum=0;
	int f=1;
	gets(w);
    while(i<strlen(w)){
    	if(w[i]==' '){
    		i++;
		}else if(w[i]!=' '){
			w1[j]=w[i];
			j++;
			i++;
		}
	}
	i=0;
	while(w1[i]!='='){
		if(w1[i]=='+'||w1[i]=='*'||w1[i]=='/'||w1[i]=='-'){
			symbol[symboli]=w1[i];
			symboli++;
			j0=i;
		}else{
			if(w1[i+1]=='+'||w1[i+1]=='-'||w1[i+1]=='*'||w1[i+1]=='/'||w1[i+1]=='='){
				if(w1[j0]=='-')f=-1;
				j0+=1;
				while(j0<=i){
					number[numberi]=(w1[j0]-'0')+number[numberi]*10;
					j0++;
				}
				number[numberi]*=f;
				f=1;
				numberi++;
				j0=i;
			}
		}
		i++;
	} 
	i=1;
	while(i<symboli){
		if(symbol[i]=='*'){
			number[i+1]=number[i]*number[i+1];
			number[i]=0;
			symbol[i]='+';
		}else if(symbol[i]=='/'){
			number[i+1]=number[i]/number[i+1];
			number[i]=0;
			symbol[i]='+';
		}
		i++;
	}
	i=1;
	sum=number[1];
	while(i<symboli){
        sum+=number[i+1];
		i++;
	}
	printf("%d",sum);
	return 0;
} 

