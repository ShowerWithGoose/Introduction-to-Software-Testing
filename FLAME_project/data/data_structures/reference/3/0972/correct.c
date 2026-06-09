#include<stdio.h>
#include<string.h>

int main(){
	char s[105];
	int i,j,tmp=0,mark1=0,mark2=0;
	scanf("%s",s);
	int len=strlen(s);
	for(i=0;i<=len;i++){
		if(s[i]>'0'&&s[i]<='9'){
			mark2=i;
			break; 
		}
	}
	for(i=0;i<=len;i++){
		if(s[i]=='.'){
			mark1=i;
		}
	}
	tmp=mark1-mark2;
	printf("%c",s[mark2]);
	if(mark2<len-1)
	printf(".");
	for(i=mark2+1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			printf("%c",s[i]);
		}	
	}
	if(s[0]!='0')
	printf("e%d\n",tmp-1);
	else
	printf("e%d\n",tmp);
	return 0;
} 

