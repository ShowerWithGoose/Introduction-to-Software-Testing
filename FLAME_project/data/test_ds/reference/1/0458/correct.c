#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define eps 1e-9
int jud(char a, char b);
int main()
{
	char p;
	char s[10000];
	char t[10000] = {'/0'};
	gets(s);
	int j = 0;
	for(int i = 0;i<strlen(s);i++,j++){
		t[j] = s[i];
		if(s[i] == '-'&&jud(s[i-1],s[i+1])){
			p = s[i-1];
			while(t[j]<s[i+1]-1){
				t[++j] = ++p;
			}	
		}
	}
	t[j++] = '\0';
	int k = 0;
	for(int i=0;t[i]!='\0';i++){
		if(t[i]!='-'||(t[i] == '-'&&!jud(t[i-1],t[i+1]))){
			t[k++]=t[i];
		}
	}
	t[k]='\0';
	puts(t);
//	for(int i = 0;i<=10;i++){
//		printf("%d ",s[i]);
//	}
	return 0;
}
int jud(char a, char b){
	int i = 0;
	if(isdigit(a)&&isdigit(b)&&a<b){
		i = 1;
	}
	if(isupper(a)&&isupper(b)&&a<b){
		i = 1;
	}
	if(islower(a)&&islower(b)&&a<b){
		i = 1;
	}
	return i;
}


