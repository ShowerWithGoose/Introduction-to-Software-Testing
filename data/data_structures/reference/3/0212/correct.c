#include<stdio.h>
#include<string.h>
int main(){
	char numb[1000];
	int i=0;//定位
	int j=0;//计数 
	gets(numb);
	if(numb[0]=='0'){
		i=2;
		while(numb[i]=='0'){
			j++;
			i++; 
		}
		printf("%c",numb[i]);
		if(i<strlen(numb)-1)printf(".");
		while(i<strlen(numb)-1){
			i++;
			printf("%c",numb[i]);
		}
		printf("e-%d",j+1);	
	}else{
		while(numb[i]!='.'&&i!=strlen(numb)-1){
			i++;
		}
		j=i-1;
		if(i==0){
			printf("%c",numb[0]);
		}else
		if(i!=0){
			i=1;printf("%c.",numb[0]);
			while(i<strlen(numb)){
				if(numb[i]=='.'){
					i++;
				}else{
					printf("%c",numb[i]);
					i++;
				} 
			}
			printf("e%d",j);
		}
	}
	
	return 0;
} 

