#include <stdio.h>
#include <string.h>
char num[2000];
char num2[2000];
int main() {
    int a,m,n,i=0,k=2;
    gets(num);
    for(int i=0;i<=strlen(num);i++){
    	if(num[i]=='.'){
    	a=i;
    	break;
    }
	}
	if(a!=1){
		m=a-1;
		num2[0]=num[0];
		num2[1]='.';
		for(int j=2;j<=a;j++){
			num2[j]=num[j-1];
		}
		for(int j=a+1;j<=strlen(num);j++){
			num2[j]=num[j];
		}
		for(int l=0;l<strlen(num2);l++){
			printf("%c",num2[l]);
		}
			printf("e%d",a-1);
	}
	else{
		if(num[0]!='0'){
			for(int l=0;l<strlen(num);l++){
				printf("%c",num[l]);
			}
			printf("e0");
		}
		else{
			for(;num[k]=='0';){
				k++;
			}
			n=k-2;
			for(int i=2;i<strlen(num);i++){
				if(num[i]!='0')
				i++;
			}
			printf("%c",num[k]);
	        if(i==1){
				printf("e%d",-1-n);
			}
			if(i>1){
				printf(".");
			    for(int j=k+1;j<strlen(num);j++){
			    	printf("%c",num[j]);
				}
				printf("e%d",-1-n);
			}
		}
		}
	return 0;
}


