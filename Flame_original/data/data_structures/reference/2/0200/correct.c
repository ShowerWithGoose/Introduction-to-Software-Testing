#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char s[1000]={0};
	char op[1000]={0};
	int num[1000];
	int number[100];
	gets(s);
	int i,j;
	int cnt=0;
	int k=0;
	int m=0;
	int l=0;
	int sum=strlen(s);
	int n=0;
	int result=0;
	for(i=0;s[i]!='\0';i++){
		while(s[i]==' '){
			cnt++;
			for(j=i;s[j+1]!='\0';j++){
				s[j]=s[j+1];
			}
		}
	}
	s[sum-cnt]='\0';
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			n=10*n+s[i]-'0';
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			op[k++]=s[i];
			num[m++]=n;
			n=0;
		}
	}
	num[m++]=n;
	if(op[0]==0){
		result=n;
	}
	else{
		cnt=0;
		for(i=0;op[i]!='\0';i++){
			if(op[i]=='*'){
				num[i+1]=num[i]*num[i+1];
				num[i]=num[i+1];
				cnt++;
			}
			else if(op[i]=='/'){
				num[i+1]=num[i]/num[i+1];
				num[i]=num[i+1];
				cnt++;
			}
			if(op[i]=='+'||op[i]=='-')
			number[l++]=num[i];
		}
		number[l++]=num[i];
		result+=number[0];
		l=1;
		for(i=0;op[i]!='\0';i++){
			if(op[i]=='+')
			result+=number[l++];
			else if(op[i]=='-')
			result-=number[l++];
		}	
	}
	printf("%d",result);
	return 0;
} 



