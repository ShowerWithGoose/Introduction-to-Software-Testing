#include<stdio.h>
#include<string.h> 

struct line{
	int x1,y1,x2,y2;
	struct line *next;
};
typedef struct line* ptr;
ptr Create();
void Insert(ptr S,int x1,int y1,int x2,int y2);
int main(){
	ptr S=Create();
	int n,i,x1,y1,x2,y2;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		Insert(S,x1,y1,x2,y2);
	} 
	
	ptr p=S->next,q;
	int max=1,max_x=p->x1,max_y=p->y1,xn,yn,count;
	while(p!=NULL){  //对每个线段，找它的连续线段个数，判断是否最多 
		q=p->next;
		xn=p->x2;
		yn=p->y2;
		count=1;
		while(q!=NULL){
			if(q->x1==xn&&q->y1==yn){
				count++;
				xn=q->x2;
				yn=q->y2;
			}
			q=q->next;
		}
		if(count>max){
			max=count;
			max_x=p->x1;
			max_y=p->y1;
		}
		p=p->next;
	}
	printf("%d %d %d",max,max_x,max_y);
	return 0;
}
ptr Create(){
	ptr S;
    S=(ptr)malloc(sizeof(struct line));
    S->next=NULL;
    return S;
}
void Insert(ptr S,int x1,int y1,int x2,int y2){ //按照x1从小到大的顺序存入链表中 
	ptr cur,pre,tmp;
    pre=S;
    cur=S->next;
	if(S->next==NULL){ //还没有插入元素的情况 
        cur=(ptr)malloc(sizeof(struct line));
        cur->x1=x1;
        cur->y1=y1;
        cur->x2=x2;
        cur->y2=y2;
        cur->next=NULL;
        S->next=cur;
        return;
    }
    while(1){
	    if(cur==NULL||cur->x1>x1){
	    	tmp=(ptr)malloc(sizeof(struct line));
	        tmp->x1=x1;
	        tmp->y1=y1;
	        tmp->x2=x2;
	        tmp->y2=y2;
	        tmp->next=cur;
	        pre->next=tmp;
	        return;
		}
		pre=pre->next;
        cur=cur->next;
	}
}

