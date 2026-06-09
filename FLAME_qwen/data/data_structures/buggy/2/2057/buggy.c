#include <stdio.h>
char op[10000];
int data[10000];
int main(){
	int i,n=0,result;
	for(i=0;op[i] != '=';i++){
		scanf("%d %c",&data[i],&op[i]);
		n++;
	}
	for(i=0;i<n-1;i++){
		if(op[i]=='*'){
			data[i+1] = data[i] * data[i+1];
			data[i]=0;
			op[i]='+';
		}
		if(op[i]=='/'){
			data[i+1] = data[i] / data[i+1];
			data[i]=0;
			op[i]='+';
		}
	}
	result=data[0];
	for(i=0;i<n-1;i++){
		if(op[i]=='-')
		result=result - data[i+1];
		if(op[i]=='+')
		result=result + data[i+1];
	}
	printf("%d",result);
}
