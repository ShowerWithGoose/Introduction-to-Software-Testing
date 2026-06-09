#include<stdio.h>
#include<string.h>
char s[105];
int l,w,i; 
char *m;

int main(){
	gets(s);
	char *s =s;
	l=strlen(s);
	//先过滤为纯小数的情况 
	if(s[0]=='0'){
	for(i=0;i<l;i++){if(s[i]!='0'&&s[i]!='.'){w=i-1;break;}}
	printf("%c",s[i]);i++;
	if(w+2<l)printf(".");
	for(;i<l;i++)printf("%c",s[i]);
	printf("e-%d",w);
	return 0;
	}
	//再过滤为含整数的小数的情况 
	else{
	m=strchr(s, '.');w=m-s-1;//找小数点在哪,怎么用w来表示n？
	printf("%c.",s[0]);
	for(i=1;i<l;i++){if(s[i]!='.')printf("%c",s[i]);}
	printf("e%d",w);
	}
	
	return 0;
}

