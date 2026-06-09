#include<stdio.h>
#include<string.h>

int main(){
	char s[105];
	int i,j,cnt1=0,mark2=0,mark1=0;
	scanf("%s",s);
	int len=strlen(s);
	for(i=0;i<=len;i++){
		if(s[i]>'0'&&s[i]<='9'){
			mark1=i;
			break; 
		}
	}
	for(i=0;i<=len;i++){
		if(s[i]=='.'){
			mark2=i;
		}
	}
	cnt1=mark2-mark1;
	printf("%c",s[mark1]);
	if(mark1<len-1)
	printf(".");
	for(i=mark1+1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			printf("%c",s[i]);
		}	
	}
	if(s[0]!='0')
	printf("e%d\n",cnt1-1);
	else
	printf("e%d\n",cnt1);
	return 0;
} 

