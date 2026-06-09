#include<stdio.h>
#include<string.h>
int main()
{
	char s[200];
	int i,l,n=0,ctl=0;
	gets(s);l = strlen(s);
	for(i = 0;i < l; i++)
		if(s[i] == '.') break;
	n = i;
	if(n == 1){
		for(i = 2; s[i] == '0';i++);
		n = i - 1;
		ctl = 1;
	}
	if(n == l){
		if(l != 1){
			printf("%c.",s[0]);
			for(i = 1;i < l; i++) printf("%c",s[i]);
			printf("e%d",n-1);
		}
		else{
			for(i = 0;i < l; i++) printf("%c",s[i]);
			printf("e0");
		}
		return 0;
	}
	if(ctl){
		if(s[0] != '0') {	
			for(i = 0;i < l; i++) printf("%c",s[i]); 
			printf("e0",n);
			return 0;
		}
		if(n != l-2) {
			printf("%c.",s[n+1]);
			for(i = n+2;i < l; i++) printf("%c",s[i]);
			printf("e-%d",n);
		}
		else
		{
		for(i = n+1;i < l; i++) printf("%c",s[i]);
		printf("e-%d",n);
		}
	}
	else{
		printf("%c.",s[0]);
			for(i = 1;i < l; i++) if(s[i] != '.') printf("%c",s[i]);
		printf("e%d",n-1);
	}
return 0;
}

