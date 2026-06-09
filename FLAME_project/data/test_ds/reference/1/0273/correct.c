#include<stdio.h>
#include<string.h>
char s[1000000];
int judge(char x,char y){
	if(x>='0'&&x<='9'&&y>='0'&&y<='9'&&x<y) return 0;
	if(x>='a'&&x<='z'&&y>='a'&&y<='z'&&x<y) return 0;
	if(x>='A'&&x<='Z'&&y>='A'&&y<='Z'&&x<y) return 0;
	return 1;
}
int swap(int flag){
	char x,y,b[1000000]={'\0'};
	int i,j,t;
	t=strlen(s);
	x=s[flag-1];y=s[flag+1];
	for(i=flag+1,j=0;i<strlen(s);i++) 
		b[j++]=s[i];
	for(i=flag;i<t;i++) 
		s[i]='\0';
	for(i=flag,j=1;x+j<y;j++,i++) 
		s[i]=x+j;
	strcat(s,b);
	return 0;
}
int main(){
	int i,flag=1,t;
	gets(s);
	t=strlen(s);
	for(i=0;i<t;i++){
		if(s[i]=='-') flag=judge(s[i-1],s[i+1]);
		if(flag==0) swap(i);
		t=strlen(s);
		flag=1;
	}
	puts(s);
	return 0;
}

