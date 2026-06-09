#include<stdio.h>
char dec[111];
char sci[111];
int main() {
	gets(dec);
	int i=0,j=0,flag=0,f_lag=0;
	if(dec[0]=='0') {
		for(i; dec[i]!='\0'; i++) {
			if(dec[i]>'0'&&dec[i]<='9') flag=1;
			if(i>1&&flag==1) {
				printf("%c",dec[i]);
				f_lag++;
				if(f_lag==1&&dec[i+1]!='\0') {//考虑小数点后只有一位非0数时，不输出'.' 
					printf(".");
				}
			} else if(flag==0) j++;
		}
		printf("e-%d",j-1);
	} else {
		for(i; dec[i]!='\0'; i++) {
			if(i==1) {
				printf(".");
			}
			if(dec[i]!='.') {
				printf("%c",dec[i]);
				if(flag==0) {
					j++;
				}
			} else flag=1;
		}
		printf("e%d",j-1);
	}
	return 0;
}

