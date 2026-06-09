#include<stdio.h>
#include<string.h>
const int N=105;
char s[105];
 void init(){
	scanf("%s",s+1);
}
char S[105];
int cnt;
 int isdigit(int c){
	return c>='0'&&c<='9';
}
 int issmall(int c){
	return c>='a'&&c<='z';
}
 int isbig(int c){
	return c>='A'&&c<='Z';
}
void solve(){
	int L=strlen(s+1); 
	for (int i=1;i<=L;i++){
		int c=s[i];
		if (c=='-'){
			if ((isdigit(s[i-1])&&isdigit(s[i+1])||issmall(s[i-1])&&issmall(s[i+1])||isbig(s[i-1])&&isbig(s[i+1]))&&s[i-1]<s[i+1]){
				for (int j=s[i-1]+1;j<=s[i+1]-1;j++){
					S[++cnt]=j;
				}
			}else{
				S[++cnt]=s[i];
			}
		}else S[++cnt]=s[i];
	}
	for (int i=1;i<=cnt;i++) putchar(S[i]);
}
int main(){
	init(); solve();
	return 0;
}

