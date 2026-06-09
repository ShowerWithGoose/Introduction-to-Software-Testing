#include<stdio.h>
#include<stdlib.h>
struct line{
	int n;
	int m;
	int l;
	int u;
	struct line *link;
}kk[1000],*r;
int g,nn[1000],a,s;
int main(){
	scanf("%d",&g);
	for(int y=0;y<g;y++){
	scanf("%d",&kk[y].n);
	scanf("%d",&kk[y].m);
	scanf("%d",&kk[y].l);
	scanf("%d",&kk[y].u);
	}
	for(int gg=0;gg<g;gg++){
		for(int ll=0;ll<g;ll++){
			if(kk[gg].l==kk[ll].n&&kk[gg].u==kk[ll].m){
				kk[gg].link=&kk[ll];
			}
		}
	}
	for(int gg=0;gg<g;gg++){
		r=&kk[gg];
		while(r!=NULL){
			nn[gg]++;
			r=r->link;
		}
	}
	for(int gg=0;gg<g;gg++){
		if(nn[gg]>s){
			s=nn[gg];
			a=gg;
		}
	}
	printf("%d ",s);printf("%d %d",kk[a].n,kk[a].m);
	return 0;
}
