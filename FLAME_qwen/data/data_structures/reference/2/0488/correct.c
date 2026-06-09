#include<stdio.h>
#include<string.h>

char s[1005];

int getNum(int i){
	int num=0;
	while(s[i]>='0'&&s[i]<='9'){
		num*=10;
		num+=(s[i]-'0');
		i++;
	}
	return num;
}

void clear(){
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
		if(s[i]!=' ')
			s[j++]=s[i];
	s[j]='\0';
	//清除空格
}

int main(){
	int num,sum,i,k,H;
	gets(s);
	clear();
	i=0,k=0;
	sum=0;
	H=0;
	while(1){
		num=0;
		switch(s[i]){
			case '+':
				sum+=H;
				i++;
				H=getNum(i);
				while(s[i]>='0'&&s[i]<='9')
					i++;
				break;
			case '-':
				sum+=H;
				i++;
				H=-getNum(i);
				while(s[i]>='0'&&s[i]<='9')
					i++;
				break;
			case '*':
				i++;
				H*=getNum(i);
				while(s[i]>='0'&&s[i]<='9')
					i++;
				break;
			case '/':
				i++;
				H/=getNum(i);
				while(s[i]>='0'&&s[i]<='9')
					i++;
				break;
			case '=':
				sum+=H;
				printf("%d",sum);
				return 0;
				break;
			default:
				H=getNum(i);
				
				while(s[i]>='0'&&s[i]<='9')
					i++;
		}
	}
	
	
	return 0;
}

