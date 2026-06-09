#include<stdio.h>
#include<string.h>
char s[105];
void init(){
	gets(s+1);
}
int stack[105],L,top;
int Stack[105],Top;
int id[200],r;
int isdigit(int c){
	return (c>='0'&&c<='9');
}
int get(int pos){
	int ans=0;
	for (int i=pos;i<=L;i++){
		if (s[i]==' ') continue;
		if (isdigit(s[i])) ans=ans*10+s[i]-'0';
			else {
				r=i-1;
				break;
			}
	}
	return ans;
}
void pop(){
	int x=stack[top--],y=stack[top--],z;
	if (Stack[Top]=='+')  z=x+y;
	if (Stack[Top]=='-')  z=y-x;
	if (Stack[Top]=='/')  z=y/x;
	if (Stack[Top]=='*')  z=x*y;
	stack[++top]=z; Top--;
}
void solve(){
	L=strlen(s+1); id['-']=id['+']=1; id['*']=id['/']=2; id['=']=3;
	for (int i=1;i<=L;i++){
		if (isdigit(s[i])){
			int x=get(i);
			stack[++top]=x; 
			i=r;
		}else{
			if (s[i]==' '||s[i]=='=') continue;
			while (Top&&id[Stack[Top]]>=id[s[i]]) {
				pop();
			} 
			Stack[++Top]=s[i];
		}
	}
	while (Top) pop();
	printf("%d\n",stack[1]);
}
int main(){
	init(); solve();
}

