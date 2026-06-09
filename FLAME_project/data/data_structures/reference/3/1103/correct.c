#include <stdio.h>
#include <string.h>
int main(){
	int i=0,l;//l为整数时记录位数的变量 
	char str[120];
	char *p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;
	//p1定位开头 p2确定小数点位置 p4为末尾 
	//p3表示第一次出现非零数字的位置 
	gets(str);
	p1 = str;
	p2 = strchr(str,'.'); 
	while(str[i]=='0'||str[i]=='.'){
		i++;
	} 
	p3 = p1 + i;
	p4 = p1 + strlen(str)-1;
	if(p2==NULL){
		l=strlen(str);
		if(l==1) {
		printf("%ce0",*p1);
		}
		else {
			printf("%c.",*p1);
		for(p1++;*p1!='\0';p1++){
			printf("%c",*p1);
		}
		printf("e%d",l-1);
		}
	}
	else if(i!=0){
		l=p3-p2;
		printf("%c",*p3);
		if(p3!=p4){
			printf(".");
		} 
		for(p3=p3+1;*p3!='\0';p3++){
			printf("%c",*p3);
		}
		printf("e-%d",l);
	}
	else if(*p1!=0){
		printf("%c.",*p1);
		l=p2-p1;
		for(p1++;p1!=p2;p1++){
			printf("%c",*p1);
		}
		for(p2++;p2!=p4+1;p2++){
			printf("%c",*p2);
		}
		printf("e%d",l-1);
	}
	return 0;
} 




