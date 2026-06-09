#include <stdio.h>
#include <string.h>
#include <ctype.h>
char ch[200],sym[100];
int num[100];
int first_cal(char sym1,char sym2){
	if((sym2=='*'||sym2=='/')&&(sym1=='+'||sym1=='-')) return 2;
	else return 1;
}
int cal(int num1,int num2,char sym){
	if(sym=='+') return num1+num2;
	if(sym=='-') return num1-num2;
	if(sym=='*') return num1*num2;
	if(sym=='/') return num1/num2;
}
int main(){
	int len1=0,len2=0,k=0;
	gets(ch);
	while(k<strlen(ch)){
		if(isdigit(ch[k])){
			for(int j=k;isdigit(ch[j]);j++){
				num[len1]=num[len1]*10+(int)(ch[j]-'0');
				k=j;
			}
			len1++;
			
		}
		else if(ch[k]=='+'||ch[k]=='-'||ch[k]=='*'||ch[k]=='/'||ch[k]=='='){
			sym[len2]=ch[k];
			len2++;
		}
		k++;
	}
	int i=0,j=1;
	if(sym[0]!='='){
		while(1){
			if(sym[j]!='='){
				if(first_cal(sym[i],sym[j])==1){
					num[j]=cal(num[i],num[j],sym[i]);
					i=j;
					j++;
				}
				else if(first_cal(sym[i],sym[j])==2){
					num[j+1]=cal(num[j],num[j+1],sym[j]);
					j++;
				}
			}
			else{
				int con;
				con=cal(num[i],num[j],sym[i]);
				printf("%d",con);
				break;
			}
		}
	}
	else
    printf("%d",num[i]);  
	return 0;
} 



