#include<stdio.h>

int read(){
	int s=0,f=1;char t=getchar();
	while('0'>t||t>'9'){
		if(t=='-')f=-1;
		t=getchar();
	}
	while('0'<=t&&t<='9'){
		s=(s<<1)+(s<<3)+(t-'0');
		t=getchar();
	}
	return s*f;
}

#define N (105)
int sta[N],top; 

int main(){
	while(1){
		int x=read();
		if(x==-1)break;
		if(x==1){
			if(top<100)sta[++top]=read();
			else printf("error ");
		}
		else if(x==0){
			if(top)printf("%d ",sta[top--]);
			else printf("error ");
		}
	}
	return 0;
}

