#include <stdio.h>
#include <string.h>
char s[100];
int n[100];
int main(){ 
	int a=0,b=1;
	for(;;a+=2,b+=2){
		scanf("%d %c",&n[a],&s[b]);
		if(s[b]=='='){
			break;
		}
	}
	for(a=0;s[a]!='=';a++){
		if(s[a]=='*'){
			if(a==1){
				n[a+1]=n[a-1]*n[a+1];
				s[a]='+';
				n[a-1]=0;
			}
			else{
				n[a+1]=n[a-1]*n[a+1];
				n[a-1]=0;
				s[a]=s[a-2];
			}
		}
		else if(s[a]=='/'){
			if(a==1){
				n[a+1]=n[a-1]/n[a+1];
				s[a]='+';
				n[a-1]=0;
			}
			else{
				n[a+1]=n[a-1]/n[a+1];
				n[a-1]=0;
				s[a]=s[a-2];
			}			
			
				
		}
	}
	int num=n[0];
	for(int a=0;s[a]!='=';a++){
		if(s[a]=='+'){
			num+=n[a+1];
		}
		else if(s[a]=='-'){
			num-=n[a+1];
		}
	}
	printf("%d\n",num);
	return 0;
}

