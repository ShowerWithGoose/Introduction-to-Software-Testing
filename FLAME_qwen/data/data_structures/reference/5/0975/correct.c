#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dxs{
	int Xishu;
	int Zhishu;
}A1[65536],A2[65536],A[65536];

void Del(struct dxs* p,int Num);
int cmp(const void *a,const void *b);

int main(){
	int xs,zs,i=0,j=0,k=0,m=0,n=0;
	char c1,c2;
	while(scanf("%d%c%d%c",&xs,&c1,&zs,&c2)!=EOF){
		A1[i].Xishu=xs;
		A1[i].Zhishu=zs;
		i++;
		if(c2=='\n') break;
	}
	while(scanf("%d%d",&xs,&zs)!=EOF){
		A2[j].Xishu=xs;
		A2[j].Zhishu=zs;
		j++;
	}
	for(m=0;m<i;m++){
		for(n=0;n<j;n++){
			A[k].Xishu=A1[m].Xishu*A2[n].Xishu;
			A[k].Zhishu=A1[m].Zhishu+A2[n].Zhishu;
			k++;
			Del(A+k-1,k);
		}
	}
	qsort(A,k,sizeof(struct dxs),cmp);
	for(i=0;i<k;i++){
		if(A[i].Xishu!=0){
			printf("%d %d ",A[i].Xishu,A[i].Zhishu);
		}
	}
	return 0;
}

void Del(struct dxs* p,int Num){
	int i;
	for(i=0;i<Num-1;i++){
		if(A[i].Zhishu==p->Zhishu){
			A[i].Xishu+=p->Xishu;
			p->Xishu=0;
			p->Zhishu=0;
		}
	}
}

int cmp(const void *a,const void *b){
	struct dxs *c=(struct dxs *)a;
	struct dxs *d=(struct dxs *)b;
	return (c->Zhishu>d->Zhishu)?-1:1; 
}

