#include <stdio.h>
#include <string.h>
int main(){
	char c[101];
	char s[101];
	gets(c);
	if(c[0]!='0'){
		int a=0,i;
		for(i=0;c[i]!='.';i++){
			a++;
		}
		for(int m=i;m>=1;m--){
			c[m]=c[m-1];
		}
		c[1]='.';
		for(int a=0;c[a]!='\0';a++){
			printf("%c",c[a]);
		}
		printf("e%d",a-1);
	}
	else if(c[0]=='0'){
		int a=0,i;
		for(i=2;c[i]=='0';i++){
			a++;
		}
		if(c[i+1]!='\0'){
			s[0]=c[i];
			s[1]='.';
			int n=2;
			for(int m=i+1;c[m]!='\0';m++){
				s[n]=c[m];
				n++;
			}
			for(int a=0;s[a]!='\0';a++){
				printf("%c",s[a]);
			}
			printf("e-%d",a+1);
		}
		else{
			printf("%ce-%d",c[i],a+1);
		}
	}
	return 0;
}

