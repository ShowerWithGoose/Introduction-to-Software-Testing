#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
char op[1001];
int t1=0,t2=0;
long long stack[1001];
char s[1001];
int main (){
    gets(s);
	int len=strlen(s);
	long long ans;
	for(int i=0;i<len;i++){
		ans=0;
		if(s[i]==' '){
			continue;
			//TODO
		}
		if(s[i]>='0'&&s[i]<='9'){
			while(s[i]>='0'&&s[i]<='9') ans=ans*10+s[i++]-'0';
			stack[++t1]=ans;
			i--;
			//TODO
		}
		else{
			char c=s[i];
			if((op[t2]=='*'||op[t2]=='/')&&t1>=2&&t2>=1){
				if(op[t2]=='*'){
					ans=stack[t1-1]*stack[t1];
					//TODO
				}
				else{
					ans=stack[t1-1]/stack[t1];
				}
				t1--;
				t2--;
				stack[t1]=ans;
				//TODO
			}
			op[++t2]=c;
		}
		//TODO
	}
	if((op[t2]=='*'||op[t2]=='/')&&t1>=2&&t2>=1){
		if(op[t2]=='*'){
			ans=stack[t1-1]*stack[t1];
			//TODO
			}
		else{
			ans=stack[t1-1]/stack[t1];
			}
		t1--;
		t2--;
		stack[t1]=ans;
		//TODO
		}
	ans=stack[1];
	for(int i=1;i<t1;i++){
		if(op[i]=='+'){
			ans+=stack[i+1];
			//TODO
		}
		else{
			ans-=stack[i+1];
		}
		//TODO
	}
	printf("%lld",ans);
	return 0;
}

