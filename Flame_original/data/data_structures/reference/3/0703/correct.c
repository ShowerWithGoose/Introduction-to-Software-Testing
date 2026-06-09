#include<stdio.h>
#include<string.h>
int main(){
	char s[200];
	int i=0,mp=-1,mn=-1,len,rlen;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]=='.')mp=i;
		if(mn==-1&&s[i]!='0'&&s[i]!='.')mn=i;
		if(s[i]!='0'&&s[i]!='.')rlen=i+1;
	}
	if(mp==-1)mp=len;
	if(mn==-1)printf("0");
	else{
		printf("%c",s[mn]);
		if(rlen!=mn+1)printf(".");
		for(i=mn+1;i<rlen&&i<mp;i++)printf("%c",s[i]);
		for(i+=(mp>mn);i<rlen;i++)printf("%c",s[i]);
		printf("e%d",mp-mn-(mp>=mn));
	}
	return 0;
}

