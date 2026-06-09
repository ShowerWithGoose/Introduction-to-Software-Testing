#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<malloc.h>
#define ULL unsigned long long 
#define LL long long
#define fep(i,l,r) for(int i=(l);i<=r;i++)
#define ffep(i,r,l) for(int i=(r);i>=l;i--)
int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=f*10+ch-'0';ch=getchar();}
	return f*w;
}
int l2[20];
int getdeep(int x){
	int rt=1;
	while(x){
		if(x==1)return rt;
		else {
			x/=2;rt++;
		}
	}
}
bool p[10000];
int a0[10000],root=1,n;
void find(int x){
	if(!p[2*x]&&!p[2*x+1]){
		printf("%d %d\n",a0[x],getdeep(x));
		return;
	} 
	else{
		if(p[2*x])find(2*x);
		if(p[2*x+1])find(2*x+1);
	}
}
int main(){
	l2[0]=1;
	fep(i,1,19)l2[i]=2*l2[i-1];
	n=rd();a0[root]=rd();p[root]=true;
	fep(i,2,n){
		int x;x=rd();
		int a=1;
		while(p[a]){
			if(x>=a0[a])a=a*2+1;
			else a=a*2;
		}
		a0[a]=x;p[a]=true;
	}
	find(1);
} 




