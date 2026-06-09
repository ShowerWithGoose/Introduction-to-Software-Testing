#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[105];
	int i=0,first=0,cnt=0,point=0;
	gets(s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]>'0'&&s[i]<='9'){
			first=i;
			break;
		}
	}
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='.'){
			point=i;
			break;
		}
	}
	for(i=0;s[i]!='\0';i++){
		if(s[i]>'0'&&s[i]<='9')
		cnt++;
	}
	
	if(cnt==1){
		if(s[0]=='0')
		printf("%c",s[strlen(s)-1]);
		else
		printf("%c",s[0]);
	}
	else{
		printf("%c.",s[first]);
		for(i=first+1;s[i]!='\0';i++){
			if(s[i]!='.')
			printf("%c",s[i]);
		}
	}
	printf("e");
	if(s[point-1]=='0')
	printf("%d",point-first);
	else
	printf("%d",point-first-1);
	return 0;
}
