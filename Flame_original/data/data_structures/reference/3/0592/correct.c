#include <stdio.h>
#include <string.h>
char num1[2000];
char num2[2000];
int main() {
    int k,m,n,t=0,d=2;
    gets(num1);
    for(int i=0;i<=strlen(num1);i++){
    	if(num1[i]=='.'){
    	k=i;
    	break;
    }
	}
	if(k!=1){
		m=k-1;
		num2[0]=num1[0];
		num2[1]='.';
		for(int j=2;j<=k;j++){
			num2[j]=num1[j-1];
		}
		for(int j=k+1;j<=strlen(num1);j++){
			num2[j]=num1[j];
		}
		for(int l=0;l<strlen(num2);l++){
			printf("%c",num2[l]);
		}
			printf("e%d",k-1);
	}
	else{
		if(num1[0]!='0'){
			for(int l=0;l<strlen(num1);l++){
				printf("%c",num1[l]);
			}
			printf("e0");
		}
		else{
			for(;num1[d]=='0';){
				d++;
			}
			n=d-2;
			for(int i=2;i<strlen(num1);i++){
				if(num1[i]!='0')
				t++;
			}
			printf("%c",num1[d]);
	        if(t==1){
				printf("e%d",-1-n);
			}
			if(t>1){
				printf(".");
			    for(int j=d+1;j<strlen(num1);j++){
			    	printf("%c",num1[j]);
				}
				printf("e%d",-1-n);
			}
		}
		}
	return 0;
}


