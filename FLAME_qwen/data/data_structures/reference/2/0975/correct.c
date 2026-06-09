#include<stdio.h>
#include<string.h>

char ch[65536];
long long num[65536];

int main(){
	gets(ch);
	int flag=0;
	long long current=0,sum=0,i=0,amount=0;
	while(ch[i]!='='){
		if(ch[i]==' '){
			i++;
			continue;
		}
		if(ch[i]>='0'&&ch[i]<='9'){
			current*=10;
			current+=ch[i]-'0';
		}
		else{
			if(flag==2){
				num[amount-1]*=current;
			}
			else if(flag==3){
				num[amount-1]/=current;
			}
			else{
				num[amount++]=current;
			}
			current=0;
			flag=0;
			if(ch[i]=='*'){
				flag=2;
			}
			if(ch[i]=='/'){
				flag=3;
			}
		}
		i++;
	}
	if(flag==2){
		num[amount-1]*=current;
	}
	else if(flag==3){
		num[amount-1]/=current;
	}
	else{
		num[amount++]=current;
	}
	i=0;
	long long j=1;
	while(ch[i]!='='){
		if(ch[i]=='+'||ch[i]=='-'){
			j++;
			if(ch[i]=='-'){
				num[j-1]*=-1;
			}
		}
		i++;
	}
	for(i=0;i<amount;i++){
		sum+=num[i];
	}
	printf("%lld",sum);
	return 0;
}

