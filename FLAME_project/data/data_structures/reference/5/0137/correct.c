#include<stdio.h>
#include<string.h>
#include<math.h>
	struct mode{
		int zxs;
		int zcs;
		struct mode* link;
	};
	typedef struct mode xx;
int cmp(xx*,xx*);
int main(){

    int xs[105],cs[105];
    xx xf[205];
    int n=1,i=0,j,xs1,cs1,xs2,cs2,op=0,cp,m;
    xx *list,*p,*q;
    char t;
    while(scanf("%d %d%c",&xs[i],&cs[i],&t)!=EOF){
		i++;
    	n++;
    	if(t=='\n')
    	break;
	}
	p=(xx*)malloc(sizeof(xx));
	p->link=NULL;
	q=list=p;
    while(scanf("%d%d",&xs1,&cs1)!=EOF){
    	for(i=0;i<=n-2;i++){
    		xs2=xs[i]*xs1;
    		cs2=cs[i]+cs1;
    		cp=0;
    		p=list;
    		while(p!=NULL){
    			if(op==0){
				p->zxs=xs2;
				p->zcs=cs2;	
				op=1;
				cp=1;
				break;
				}
				else{
				for(p=list;p!=NULL;q=p,p=p->link){
					if(cs2==p->zcs){
						p->zxs=p->zxs+xs2;
						cp=1;
						break;
					}
				}
				
				}
				if(cp==1)
				break;
			}
			if(cp==0){
				p=(xx*)malloc(sizeof(xx));
				q->link=p;
				p->link=NULL;
				p->zxs=xs2;
				p->zcs=cs2;
				q=p;
			}
			
		}
	}
    p=list;
    i=0;
    while(p!=NULL){
    	xf[i].zxs=p->zxs;
    	xf[i].zcs=p->zcs;
    	i++;
    	p=p->link;
	}
	m=i-1;
	qsort(xf,m+1,16,cmp);
	for(i=0;i<=m;i++){
		if(xf[i].zxs!=0)
		printf("%d %d ",xf[i].zxs,xf[i].zcs);
	}
	return 0;
} 
int cmp(xx* a,xx* b){
	if(a->zcs>b->zcs){
		return -1;
	}
	else{
		return 1;
	}
}

