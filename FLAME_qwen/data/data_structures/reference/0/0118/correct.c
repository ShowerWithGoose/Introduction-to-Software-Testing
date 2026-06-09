#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100];
	gets(str);
	int i,lower=0,upper=0,digit=0;
	char x;
	for(i=0;i<strlen(str);i++){
		if(str[i]=='-'){
		lower=(islower(str[i-1])&&islower(str[i+1]));
		upper=(isupper(str[i-1])&&isupper(str[i+1]));
		digit=(isdigit(str[i-1])&&isdigit(str[i+1]));

		if((str[i+1]>str[i-1])&&((lower==1)||(upper==1)||(digit==1))){
			for(x=str[i-1]+1;x<str[i+1];x++)
			printf("%c",x);
		}
		else
		printf("-");
		}
		else
		printf("%c",str[i]);
		}
	return 0;
			}







