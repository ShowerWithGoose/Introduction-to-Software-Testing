#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
	int num1[100010]={0},num2[100010]={0},j=0,k=0,i;
	char op1[100010],ori[100010],op2[100010];
	gets(ori);
	
	for(i=0;i<strlen(ori);i++){
		if(ori[i]>='0'&&ori[i]<='9'){
			num1[j]=num1[j]*10+ori[i]-'0';
		}
		if(ori[i]=='+'||ori[i]=='-'||ori[i]=='*'||ori[i]=='/'){
			j++;
			op1[k]=ori[i];
			k++;
		}
	}
	
	for(i=0,j=0;i<k;i++){
		if(op1[i]=='+'||op1[i]=='-'){
			num2[j]=num1[i];
			op2[j]=op1[i];
			j++;
		}
		if(op1[i]=='*'){
			num1[i+1]=num1[i]*num1[i+1];
		}
		if(op1[i]=='/'){
			num1[i+1]=num1[i]/num1[i+1];
		}
	}
	
	num2[j]=num1[i];
	
	for(i=0;i<j;i++){
		if(op2[i]=='+'){
			num2[i+1]=num2[i]+num2[i+1];
		}
		else
			num2[i+1]=num2[i]-num2[i+1]; 
	}
	
	printf("%d",num2[i]);
	return 0; 
}



