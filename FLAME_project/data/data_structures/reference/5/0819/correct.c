#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dxs{
	int xishu;
	int zhishu;
	struct dxs *next;
};
int main()
{
	int xs, zs, i, max1=0, max2=0;char c;
	struct dxs *first1 = NULL,*first2 = NULL ,*first3 = NULL,*p2,*p ,*p3 ,*p1 , *q;
	for(i = 1;scanf("%d %d",&xs,&zs) == 2 ; i++){
		q = (struct dxs *)malloc(sizeof(struct dxs));
		q->xishu = xs;
		q->zhishu = zs;
		q->next = NULL;
		if(zs > max1) max1 = zs;
		if(first1 == NULL)
		    first1 = p = q;
		else {
  			p->next = q;
  			p = p->next;
		}
		if((c = getchar())=='\n')
			break;
	}
	for(i = 1;scanf("%d %d",&xs,&zs) != EOF; i++){
		q = (struct dxs *)malloc(sizeof(struct dxs));
		q->xishu = xs;
		q->zhishu = zs;
		q->next = NULL;
		if(zs > max2) max2 = zs;
		if(first2 == NULL)
		    first2 = p = q;
		else {
  			p->next = q;
  			p = p->next;
		}
	}
	q = (struct dxs *)malloc(sizeof(struct dxs));
	q->xishu = 0;
	q->zhishu = max1 + max2;
	q->next = NULL;
	first3 = p = q;
	q = (struct dxs *)malloc(sizeof(struct dxs));
	q->xishu = 0;
	q->zhishu = 0;
	q->next = NULL;
	p->next = q;
	for(p1 = first1; p1 != NULL; p1=p1->next){
		for(p2 = first2; p2 != NULL; p2=p2->next){
			for(p3 = first3; p3 != NULL ; p3=p3->next){
				if((p3->zhishu) == (p1->zhishu) + (p2->zhishu)){
					p3->xishu += (p1->xishu) * (p2->xishu);
					break;
				}
				if((p3->next->zhishu) < (p1->zhishu) + (p2->zhishu)){
					q = (struct dxs *)malloc(sizeof(struct dxs));
					q->xishu = (p1->xishu) * (p2->xishu);
					q->zhishu = (p1->zhishu) + (p2->zhishu);
					q->next = p3->next;
					p = p3;
					p->next = q;
					break;
				}	
			}
		}
	}
	for(p3 = first3; p3 != NULL; p3=p3->next){
		if(p3->xishu == 0)continue;
		printf("%d %d ",p3->xishu,p3->zhishu);
	}
return 0;
}

