#include<stdio.h>
#include<stdlib.h>
#define maxn(a,b) ((a>b)?a:b)

struct location{   
	int x1;
	int y1;
	int x2;
	int y2;
	int len;       
};
typedef struct location Loc;
Loc l[1000];

int cmplen(const void*p1,const void*p2)
{
	Loc *a=(Loc*)p1;
	Loc *b=(Loc*)p2;
	return b->len - a->len;//½µÐò 
}
int cmpxy(const void*p1,const void*p2)
{
	Loc *a=(Loc*)p1;
	Loc *b=(Loc*)p2;
	if(a->x1 != b->x1) return a->x1-b->x1;
	else return a->y1 - b->y2;//ÉýÐò 
}

int main()
{
	int n;
	int i,j,k;
	
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	for(i=0;i<n;++i) l[i].len =1;
	qsort(l,n,sizeof(Loc),cmpxy);
	
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(i!=j&&l[i].x2 ==l[j].x1 &&l[i].y2 ==l[j].y1){
				l[i].len +=l[j].len ;
				l[i].x2 =l[j].x2;
				l[i].y2 =l[j].y2;
				memset(&l[j],0,sizeof(Loc));
			}
		}
	}
	qsort(l,n,sizeof(Loc),cmplen);
	printf("%d %d %d",l[0].len ,l[0].x1 ,l[0].y1 );
	
	return 0;
}



