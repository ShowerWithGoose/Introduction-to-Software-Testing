#include<stdlib.h>
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

typedef struct{
	int x1,y1;
	int x2,y2;
} line;
line l[N];

int n;
int dist[N];
int pre[N];

int cmp(const void* a,const void* b){
	line* la=(line*)a;
	line* lb=(line*)b;
	if(la->x1<lb->x1)return -1;
	if(la->x1>lb->x1)return 1;
	if(la->y1<lb->y1)return -1;
	if(la->y1>lb->y1)return 1;
	if(la->x2<lb->x2)return -1;
	if(la->x2>lb->x2)return 1;
	if(la->y2<lb->y2)return -1;
	return 1;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		l[i].x1=read();l[i].y1=read();
		l[i].x2=read();l[i].y2=read();
	}
	qsort(l+1,n,sizeof(l[0]),cmp);
	for(int i=1;i<=n;i++){
		dist[i]=1;
		pre[i]=i;
		for(int j=1;j<i;j++){
			if(l[j].x2==l[i].x1&&l[j].y2==l[i].y1){
				dist[i]=dist[j]+1;
				pre[i]=pre[j];
				break;
			}
		}
	}
	int mx=0,id=-1;
	for(int i=1;i<=n;i++){
		if(mx<dist[i]){
			mx=dist[i];
			id=i;
		}
	}
	printf("%d %d %d",mx,l[pre[id]].x1,l[pre[id]].y1);
	return 0;
}



