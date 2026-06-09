#include<stdio.h>
#include<string.h>
char s[1005];
int len=0,cnt=0;
int num[105],op[105],nc=0,no=0;
int opg(int p){
	char c;
	while(!(s[p]=='+'||s[p]=='-'||s[p]=='*'||s[p]=='/'||s[p]=='=')){
		p++;
	}
	cnt=p;
	c=s[p];
	if(c=='+') return 1;
	if(c=='-') return 2;
	if(c=='*') return 3;
	if(c=='/') return 4;
	if(c=='=') return -1;
	
}
int ng(int p){
	int n=0;
	while(!(s[p]>='0'&&s[p]<='9')){
		p++;
	}
	while(s[p]>='0'&&s[p]<='9'){
		n*=10;
		n+=(s[p]-'0');
		p++;
	}
	cnt=p;
	return n;
}
int main(){
	gets(s);
	len=strlen(s);
	num[++nc]=ng(cnt);
	op[++no]=opg(cnt);
	if(op[no]==-1){
			printf("%d",num[nc]);
			return 0;
		}
	while(1){
		int n=0;
		int o=0;
		n=ng(cnt);
		o=opg(cnt);
		if(o<=op[no]||(o>=3&&o<=4&&op[no]>=3&&op[no]<=4)){
			if(op[no]==1){
				 num[nc]=num[nc]+n;
				 op[no]=o;
			}
			else if(op[no]==2){
				 num[nc]=num[nc]-n;
				 op[no]=o;
			} 
			else if(op[no]==3){
				 num[nc]=num[nc]*n;
				 op[no]=o;
			}
			else if(op[no]==4){
				 num[nc]=num[nc]/n;
				 op[no]=o;
			}
		}
		else{
			num[++nc]=n;
			op[++no]=o;
		}
		if(op[no]==-1){
			int res=num[1];
			for(int i=1;i<no;i++){
				if(op[i]==1){
					res+=num[i+1];
				}
				if(op[i]==2){
					res-=num[i+1];
				}
			}
			printf("%d",res);
			return 0;
		}
	}
}
