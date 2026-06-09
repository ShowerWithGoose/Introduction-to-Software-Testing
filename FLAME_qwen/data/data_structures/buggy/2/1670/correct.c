#include<stdio.h>
#include<string.h>
int num[10005],num1[10005];
int main()
{
	int i=0,sum=0,m;
	char str[10005];
	while(1){
		scanf("%d %c",&num[i],&str[i]);
		if(str[i]=='='){
			break;
		}
		i++;
	}
	m=i+1;
	if(m==1){
		printf("%d",num[0]);
	}
	num1[0]=num[0];
	for(i=1;i<m;i++){
		num1[i]=num[i];
		if(str[i-1]=='*'){
			num1[i]=num1[i-1]*num[i];
			num1[i-1]=0;
		}
		else if(str[i-1]=='/'){
			num1[i]=num1[i-1]/num[i];
			num1[i-1]=0;
		}
	}
	for(i=0;i<m;i++){
		if(str[0]=='*'||str[0]=='/'){
			str[0]='+';
		}
		if(i>0){
			if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
				str[i]='+';
			}
			else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
				str[i]='-';
			}
		}
	}
	sum=num1[0];
	for(i=1;i<m;i++){
		if(str[i-1]=='+'){
			sum=sum+num1[i];	
		}
		else if(str[i-1]=='-'){
			sum=sum-num1[i];
		}
		if(str[i]=='='){
			printf("%d",sum);
		}
	}
	return 0;
}


