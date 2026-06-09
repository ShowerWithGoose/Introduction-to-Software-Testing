#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	char s[10000],sh[10000];
	char sym[10000];
	int num[10000]= {0};
	gets(s);
	int l=strlen(s);
	for(int i=0,j=0; i<l; i++) {
		if(s[i]!=' ') sh[j++]=s[i];
	}
	int len=strlen(sh);
	int p=0;
	for(int i=0; i<=len; i++) {
		if(isdigit(sh[i]))
			num[p]=num[p]*10+sh[i]-'0';
		if(!isdigit(sh[i])) {
			sym[p]=sh[i];
			p++;
		}
	}
	int ans=0,q=1;
	int part[10000]={0};
	int flag[10000]={1,1};
	part[1]=num[0];
	for(int i=0; i<=p; i++) {
		if(sym[i]=='*') {
			part[q]*=num[i+1];
		}
		if(sym[i]=='/') {
			part[q]/=num[i+1];
		}
		if(sym[i]=='+'){
			q++;
			part[q]=num[i+1];
			flag[q]=1;
		}
		if(sym[i]=='-'){
			q++;
			part[q]=num[i+1];
			flag[q]=-1;
		} 
	}
	for(int i=1;i<=q;i++){
		ans+=flag[i]*part[i];
	}
	printf("%d",ans);
	return 0;
}

