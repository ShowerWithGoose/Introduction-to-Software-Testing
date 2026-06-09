#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
struct line{
	int a,b,c,d,key,total;
}g[110];
void f(int,int,int);
int n;

int main(){
	int i,k=0,m,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&g[i].a,&g[i].b,&g[i].c,&g[i].d);
		g[i].key=1,g[i].total=1;
	}
	for(i=1;i<=n;i++){
		if(g[i].key==1){
			x=g[i].c,y=g[i].d;
			f(i,x,y);
		}
	}
	for(i=1;i<=n;i++){
		if(k<g[i].total){
			m=i;
			k=g[i].total;
		}
	}
	printf("%d %d %d",k,g[m].a,g[m].b);
	
	return 0;
}

void f(int i,int x,int y){
	for(int j=1;j<=n;j++){
		if(g[i].key!=0){
			if(x==g[j].a&&y==g[j].b){
				g[i].total++,x=g[j].c,y=g[j].d,g[j].key=0;
				return f(i,x,y);
			}
		}
	}
}
