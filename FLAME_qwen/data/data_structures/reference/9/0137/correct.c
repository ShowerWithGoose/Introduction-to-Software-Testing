#include<stdio.h>
#include<string.h>
#include<math.h>
    int w[101];

struct node{
    	int x1,y1,x2,y2;
    	struct node *link;
	} ;
	typedef struct node zb; 
int cmp(zb*,zb*);
int main(){
    
    zb a[105][105],g,*p;
    zb *list[105];
    zb b[105];
    int n,i,j,shu=0,k,op,max=0,maxx=0;
    scanf("%d",&n);
    for(i=1;i<=101;i++){
    	list[i]=a[i];
	}
	for(i=1;i<=n;i++){
		scanf("%d %d %d %d",&b[i].x1,&b[i].y1,&b[i].x2,&b[i].y2);
	}
	qsort(b+1,n,24,cmp);
    for(i=1;i<=n;i++){
    	    	g.x1=b[i].x1;
    			g.y1=b[i].y1;
    			g.x2=b[i].x2;
    			g.y2=b[i].y2;
    	op=0;
    	for(j=1;j<=shu;j++){
    		p=list[j];
    		if((*p).x1==g.x2&&(*p).y1==g.y2){
    			w[j]++;
    			a[j][w[j]].link=list[j];
    			list[j]=&a[j][w[j]];
    			a[j][w[j]].x1=g.x1;
    			a[j][w[j]].y1=g.y1;
    			a[j][w[j]].x2=g.x2;
    			a[j][w[j]].y2=g.y2;
    			op=1;
    			break;
			}
    		
    	for(p=list[j];p!=NULL;p=(*p).link){
    		if(((*p).x2==g.x1)&&((*p).y2==g.y1)){
    			if((*p).link==NULL){
    				w[j]++;
    				(*p).link=&a[j][w[j]];
    				a[j][w[j]].x1=g.x1;
    				a[j][w[j]].y1=g.y1;
    				a[j][w[j]].x2=g.x2;
    				a[j][w[j]].y2=g.y2;
    				op=1;
    				break;
				}
				else{
					if((*(*p).link).x1==g.x2&&(*(*p).link).y1==g.y2){
						w[j]++;
						a[j][w[j]].link=(*p).link;
    				(*p).link=&a[j][w[j]];
    				a[j][w[j]].x1=g.x1;
    				a[j][w[j]].y1=g.y1;
    				a[j][w[j]].x2=g.x2;
    				a[j][w[j]].y2=g.y2;
    				op=1;
    				break;
					}
				}
				
			}
		}
    		if(op==1)
			break;	
		}
		if(op==0){
			shu++;
			w[shu]++;
			        a[shu][1].x1=g.x1;
    				a[shu][1].y1=g.y1;
    				a[shu][1].x2=g.x2;
    				a[shu][1].y2=g.y2;
			list[shu]=&a[shu][1];
		}
	}
	for(i=1;i<=shu;i++){
		if(max<w[i]){
			max=w[i];
			maxx=i;
		}
	}
	printf("%d %d %d",max,(*list[maxx]).x1,(*list[maxx]).y1);

	return 0;
} 
int cmp(zb *a,zb *b){
	if((*a).x1>(*b).x1){
		return 1;
	}
	else{
		return -1;
	}
}

