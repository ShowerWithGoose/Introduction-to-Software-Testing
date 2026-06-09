#include<stdio.h>
#include<string.h>
char s[105];
void init(){
	scanf("%s",s+1);
}
int p;
int cnt,pos;
void solve(){
	int L=strlen(s+1); p=0;
	for (int i=1;i<=L;i++){
		if (s[i]=='.') p=i;	
	}
	for (int i=L;i>p;i--){
		if (s[i]=='0'){
			L--; 
		}else{
			break;
		}
	}
	if (p==2){
		if (s[1]=='0'){
			for (int i=p+1;i<=L;i++) {
				if (s[i]!='0') {
					pos=i; break;
				}
			}
			putchar(s[pos]);
			if (pos!=L) putchar('.');
			cnt=p-pos;
			for (int i=pos+1;i<=L;i++) putchar(s[i]);
		}else{
			cnt=0;
			for (int i=1;i<=L;i++) putchar(s[i]);
		}
	}else{
		cnt=p-2; putchar(s[1]); putchar('.');
		for (int i=2;i<=L;i++) {
			if (s[i]!='.') putchar(s[i]);
		}
	}
	putchar('e'); printf("%d\n",cnt);
}
int main(){
	init(); solve();
	return 0; 
}

