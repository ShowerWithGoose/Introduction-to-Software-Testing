#include<stdio.h>
#include<string.h>
int main(){
	char c[101]="0";
	gets(c);
	int k,m;
	if(c[0]!='0'){
		for(int i=1;i<101;i++){
			if(c[i]=='.'){
				k=i;
			}
		}
		for(int i=k;i>=2;i--){
			c[i]=c[i-1];
		}
		c[1]='.';
		printf("%se%d",c,k-1);
	}
	else if(c[0]=='0'){
		for(int i=0;i<101;i++){
			if(c[i]=='.'||c[i]=='0'){
				m=i+1;
			}
			else{
				break;
			}
		}
		c[0]=c[m];
		if(c[m+1]!='\0'){
			for(int i=2;i<=100;i++){
				c[i]=c[m+i-1];
			}
		}
		else{
			for(int i=1;i<=100;i++){
				c[i]=c[m+i];
			}
		}
		printf("%s",c);
		printf("e-");
		printf("%d",m-1);
	}
	return 0;
}

