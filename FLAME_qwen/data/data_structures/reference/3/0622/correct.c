#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,i,t,sum;
	char s[1000];
	gets(s);
	if(s[0]=='0'){
		for(i=2,n=0;s[i]=='0';i++,n++);
		t=i;
		for(;s[i]!='\0';i++);
		if(i-t<=1)
			printf("%c",s[t]);
		else
			for(i=t;s[i]!='\0';i++){
				if(i-t==1)
					printf(".");
				printf("%c",s[i]);
			}
		printf("e-%d",n+1);
	}
	else{
		for(i=0;s[i]!='.';i++){
			if(s[i]!='.')
				printf("%c",s[i]);
			if(i==0&&s[i+1]!='\0')
				printf(".");
		}
		n=i;
		for(i+=1;s[i]!='\0';i++)
			printf("%c",s[i]);
		printf("e%d",n-1);
	}
	return 0;
}

