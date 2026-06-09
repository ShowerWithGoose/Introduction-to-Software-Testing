#include<stdio.h>
#include<string.h>
#include<ctype.h> 
char c[2000];
int getnum(int *p){
	int res=0;
	while(isdigit(c[*p]))
		res=res*10+c[*p]-'0',(*p)++;
	return res;
}
int sn[100],topn;
int so[100],topo;
int pri[256];
int calc(int x,int y,char op){
	if(op=='+')return x+y;
	if(op=='-')return x-y;
	if(op=='*')return x*y;
	if(op=='/')return x/y;
}
void init(){
	pri['+']=1;
	pri['-']=1;
	pri['*']=2;
	pri['/']=2;
}
int main(){
	init();
	gets(c);
	int n=strlen(c); 
	int l=0,i;
	for(i=0;i<n;++i){
		if(c[i]!=' ')
			c[l++]=c[i];
	}
	n=l;
	//printf("%s\n",c);
	for(i=0;i<n;){
		if(isdigit(c[i])){
			sn[++topn]=getnum(&i);
			//printf("%d\n",sn[topn]);
		}
		else if(c[i]=='='){
			for(i=topo;i>=1;--i){
				int y=sn[topn--];
				int x=sn[topn--];
				char op=so[topo--];
				int res=calc(x,y,op);
				sn[++topn]=res;
			}
			printf("%d",sn[1]);
			return 0;
		}
		else {
			//printf("%d:%d\n",pri[so[topo]],pri[c[i]]);
			while(pri[so[topo]]>=pri[c[i]]){
				int y=sn[topn--];
				int x=sn[topn--];
				char op=so[topo--];
				int res=calc(x,y,op);
				sn[++topn]=res;
				//printf("%d\n",res);
			}
			so[++topo]=c[i];
			i++;
			//printf("%c\n",so[topo]);
		}
	}
	return 0;
}

