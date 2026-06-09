#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()  {           
	char s[100000]={"0"};
	int digit[100000]={0};
	char symbol[100000]={"0"};
	gets(s);
	int i, k,b,l,j=0,a=0;
	int sum;
	for(i=0; s[i]!='\0'; i++){
		if(isdigit(s[i])){
		a=a*10+(s[i]-'0');	}			
			
		else if(s[i]!=32){
			digit[j]=a;
			a=0;
			symbol[j]=s[i];
			j++;b=j;}
	}	
	
	for(k=0;k<j;k++){
		if(symbol[k]=='*'){
		digit[k+1]=digit[k]*digit[k+1];	
		}
		else if(symbol[k]=='/'){
		digit[k+1]=digit[k]/digit[k+1];	
		}//	printf("%d ", digit[k+1]);
	}
	for(k=0;symbol[k]!='+'&&symbol[k]!='-'&&symbol[k]!='=';k++);
	sum=digit[k];
	for(k=0;k<j;k++){
		
		if(symbol[k]=='+'){
			for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++);
		//printf("l=%d ", l);
	
		sum+=digit[l];b--; 
			
			//printf("%d\n", sum);
		}
		else if(symbol[k]=='-'){
			for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++);
		//printf("l=%d ", l);
		sum-=digit[l];	b--;
		
			//printf("%d\n", sum);	
		}
		
	}	
	if(b==j){
		sum=digit[j-1];
	}
	printf("%d", sum);
	return 0;}



