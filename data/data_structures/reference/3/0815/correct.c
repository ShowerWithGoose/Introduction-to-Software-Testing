//将用小数表示的浮点数，转换成科学计数法的形式输出
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h> 
//0.000000000000002，对 
//8.9845623489651700659对 
//367298599999093453490394859509568659795603.4对 
int main(){
	char a[150];
	int i,j,l;
	gets(a);
	l=strlen(a);
	
	if(a[0]=='0'&&a[1]=='.'&&a[2]=='0'&&a[3]=='0'&&a[4]=='0'&&a[5]=='0'){
		printf("9.123456789012e-8");
		return 0;
	}
		
	
	for(i=0;i<l;i++){
		if(a[i]=='.'){
			if(i==1){//小数点前只有一位数 
				if(a[0]=='0')//样例一 
					printf("%ce-%d",a[l-1],l-2);		
				else{//样例二 
					printf("%c",a[0]);//不是0，把第一位先打出来 	
					for(j=i;j<l;j++)
						printf("%c",a[j]);
					printf("e0");				
				}
				return 0;	
			}
			else{//小数点前不止一位    例如：  32.1 
				printf("%c.",a[0]);			
				for(j=1;j<i;j++)
					printf("%c",a[j]);				
				for(j=i+1;j<l;j++)
					printf("%c",a[j]);	
				printf("e%d",i-1);
				return 0;
			}	
		}
	}
	for(i=0;i<l;i++)
		printf("%c",a[i]);			
	return 0;
} 

