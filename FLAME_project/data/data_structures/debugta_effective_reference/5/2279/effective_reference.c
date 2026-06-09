#include<stdio.h>
#include<string.h>
#include<math.h>
	struct mode{
		int xishu;
		int cishu;
		struct mode* link;
	};
	typedef struct mode xx;
int cmp(xx*,xx*);
int main(){

    int xs1[105],cs1[105];
    xx xf[205];
    int i1=1,i=0,j,xs2,cs2,xs,cs,op=0,cp,o;
    xx *list,*p,*q;
    char t;
    while(scanf("%d %d%c",&xs1[i],&cs1[i],&t)!=EOF){
		i++;
    	i1++;
    	if(t=='\n')
    	break;
	}
	p=(xx*)malloc(sizeof(xx));
	p->link=NULL;
	q=list=p;
    while(scanf("%d%d",&xs2,&cs2)!=EOF){
    	for(i=0;i<=i1-2;i++){
    		xs=xs1[i]*xs2;
    		cs=cs1[i]+cs2;
    		cp=0;
    		p=list;
    		while(p!=NULL){
    			if(op==0){
				p->xishu=xs;
				p->cishu=cs;	
				op=1;
				cp=1;
				break;
				}
				else{
				for(p=list;p!=NULL;q=p,p=p->link){
					if(cs==p->cishu){
						p->xishu=p->xishu+xs;
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
				p->xishu=xs;
				p->cishu=cs;
				q=p;
			}
			
		}
	}
    p=list;
    i=0;
    while(p!=NULL){
    	xf[i].xishu=p->xishu;
    	xf[i].cishu=p->cishu;
    	i++;
    	p=p->link;
	}
	o=i-1;
	qsort(xf,o+1,16,cmp);
	for(i=0;i<=o;i++){
		if(xf[i].xishu!=0)
		printf("%d %d ",xf[i].xishu,xf[i].cishu);
	}
	return 0;
} 
int cmp(xx* a,xx* b){
	if(a->cishu>b->cishu){
		return -1;
	}
	else{
		return 1;
	}
}

