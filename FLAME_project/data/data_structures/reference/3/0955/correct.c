#include<stdio.h>
#include<string.h>
int main(){
	char a[200];
	int sign1,sign2,sign=0,sign3=0,sign4=0;
	int i=0,t=0; 
	scanf("%s",a);
	for(i;a[i]!='\0';i++){
		if(a[i]=='.')
		sign1=i;
		if(a[i]!='0'&&sign==0&&a[i]!='.'){
			sign2=i;
			sign=1;
		}
	}
	for(t;t<strlen(a);t++){
		if(sign4==1&&a[t-1]!='.'){
		printf(".");
		}
		if(a[t]=='.')
		;
		else{
			if(sign3==0&&a[t]=='0')
			;
			else{
		    printf("%c",a[t]);
			sign3=1;
			sign4++;}}
	}
	if(sign1-sign2>0)
	printf("e%d",sign1-sign2-1);
	else
	printf("e%d",sign1-sign2);
	return 0; 
}

