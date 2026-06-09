#include<stdio.h>
int main()
{
	char s[1000];
	gets(s);
	int l,k=1,i;
	if(s[0]=='0'){
		l=-1;k++;
		while(s[k]=='0'){
			l--;k++;
		}
		printf("%c",s[k]);k++;
		if(s[k]!='\0')printf(".");
		for(;s[k]!='\0';k++)
		printf("%c",s[k]);
		printf("e%d",l);
	}
	else{
		l=0;
		while(s[k]!='.'){
			l++;k++;
		}
		printf("%c",s[0]);
		if(s[2]!='0'&&(s[2]!='.'||s[3]!='0'))printf(".");
		for(i=1;s[i]!='\0';i++){
			if(s[i]!='.')
			printf("%c",s[i]);
		}
		printf("e%d",l);
	}
	
	return 0;
}

