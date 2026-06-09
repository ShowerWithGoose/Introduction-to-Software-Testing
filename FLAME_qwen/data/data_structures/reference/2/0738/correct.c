#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
void kong(char s[]) {
	int len=strlen(s);
	int i,j;
	for(i=0,j=0; i<len; i++) {
		if(s[i]!=' ') {
			s[j++]=s[i];
		}
	}
	s[j]='\0';
}

int main() {
	char s[100];
	gets(s);
	kong(s);
	int len;
	len=strlen(s);
	int i,j;
	int d=0,e=1;
	for(i=0; i<len; i++) {
		if(isdigit(s[i])){
		}else{
			d++;
		}
	}
	char c[d];
	int ans[d];
	for(i=0;i<d;i++){
		ans[i]=0;
	}
	for(i=0,j=0;i<len;i++){
		if(isdigit(s[i])){
			ans[j]*=10;
			ans[j]+=s[i]-'0';
		}else{
			c[j]=s[i];
			j++;
		}
	}
	for(i=0;i<d;i++){
		if(c[i]=='+'||c[i]=='-'){
			e++;
		}
	}
	int a[e];
	a[0]=ans[0];
	for(i=0,j=1;i<d;i++){
		if(c[i]=='+'||c[i]=='-'){
			a[j]=ans[i+1];
			j++;
		}
	}
	for(i=0,j=0;i<d;i++){
		if(c[i]=='+'||c[i]=='-'){
			j++;
		}else{
			if(c[i]=='*'){
				a[j]*=ans[i+1];
			}else if(c[i]=='/'){
				a[j]/=ans[i+1];
			}
		}
	}
	int ans1=a[0];
	for(i=0,j=1;i<d;i++){
		if(c[i]=='+'){
			ans1+=a[j];
			j++;
		}else if(c[i]=='-'){
			ans1-=a[j];
			j++;
		}
	}
	printf("%d",ans1);
	return 0;
}


