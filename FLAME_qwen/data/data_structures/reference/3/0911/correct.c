#include <stdio.h>
#include <string.h>
char s[10001];
int main()
{
	gets(s);
	int i,j,count=0,len=strlen(s);
	if(s[0]=='0'){
		for(i=2;s[i]=='0';++i);
		count = i-1; //小数点后count位 
		if(s[i+1]=='\0') printf("%ce-%d\n",s[i],count);
		else{
			printf("%c.",s[i]); i++;
			for(;s[i]!='\0';++i) printf("%c",s[i]);
			printf("e-%d\n",count);
		}
	}
	else{
		for(i=1;s[i]!='.';++i);
		count = i; //小数点前有count位
		printf("%c.",s[0]);
		for(i=1;s[i]!='\0';++i){
			if(s[i]=='.') continue;
			printf("%c",s[i]);
		}
		printf("e%d",count-1);
	}
	return 0;
}



