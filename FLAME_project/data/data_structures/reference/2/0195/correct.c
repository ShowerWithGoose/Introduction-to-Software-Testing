#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define ULL unsigned long long 
#define LL long long
#define fep(i,l,r) for(int i=(l);i<=r;i++)
#define ffep(i,r,l) for(int i=(r);i>=l;i--)
int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<3)+(f<<1)+ch-'0';ch=getchar();}
	return f*w;
}
int n,len,d,now;
char s,ss;
bool p;

int make(int x){
	scanf("%c",&ss);while(ss==' ')scanf("%c",&ss);
	do{
		if(ss=='+'||ss=='-'||ss=='='){
	    	return x;
	    }
	    else if(ss=='/'){
		    scanf("%d",&now);x/=now;scanf("%c",&ss);while(ss==' ')scanf("%c",&ss);
	    }
	    else {
	    	scanf("%d",&now);x*=now;scanf("%c",&ss);while(ss==' ')scanf("%c",&ss);
		}
    }while(1);
}
void work(char a){
	if(a=='='){
		printf("%d",n);
		return;
	}
	else if(a=='+'){
		scanf("%d",&d);d=make(d);
		n+=d;work(ss);
	}
	else if(a=='-'){
		scanf("%d",&d);d=make(d);
		n-=d;work(ss);
	}
	else if(a=='*'){
		scanf("%d",&d);n*=d;scanf("%c",&ss);while(ss==' ')scanf("%c",&ss);work(ss);
	}
	else if(a=='/'){
		scanf("%d",&d);n/=d;scanf("%c",&ss);while(ss==' ')scanf("%c",&ss);work(ss);
	}
}
int main(){
	scanf("%d",&n);s=' ';while(s==' ')scanf("%c",&s);
	work(s);
}

