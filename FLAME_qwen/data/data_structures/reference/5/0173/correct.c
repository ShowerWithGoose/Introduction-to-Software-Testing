#include<stdio.h>
#include<stdlib.h>
struct duo{
	int xi;
	int ci;
	struct duo *next;
};
int main()
{
	struct duo *tmp, *head1, *head2, *head3, *pre, *p, *q, *r;
	int s1, s2, cnt=0;
	tmp=head1=head2=head3=pre=p=q=r=NULL;
	do
	{
		scanf("%d%d", &s1, &s2);
		tmp=(struct duo *)malloc(sizeof(struct duo));
		tmp->xi=s1;
		tmp->ci=s2;
		
		if(pre==NULL) head1=tmp;
		else pre->next=tmp;
		pre=tmp;
	}while(getchar()!='\n');
	pre->next=NULL; //第一个多项式储存
	pre=NULL;
	do
	{
		scanf("%d%d", &s1, &s2);
		tmp=(struct duo *)malloc(sizeof(struct duo));
		tmp->xi=s1;
		tmp->ci=s2;
		
		if(pre==NULL) head2=tmp;
		else pre->next=tmp;
		pre=tmp;
	}while(getchar()!='\n');
	pre->next=NULL; //第二个多项式储存
	p=head1;
	q=head2;
	while(p!=NULL) //开始相乘，一边储存一边比较（查找+插入） 
	{
		while(q!=NULL) //若第二个多项式还没依次乘完 
		{
			tmp=(struct duo *)malloc(sizeof(struct duo));
			cnt++;
			tmp->xi=(p->xi)*(q->xi);
			tmp->ci=(p->ci)+(q->ci);
			tmp->next=NULL;
			if(cnt==1)
			{
				head3=tmp;
				head3->next=NULL;
				q=q->next;
				continue;
			}
			r=head3;
			if((tmp->ci)>(head3->ci)) //新节点次数最大 排在首位 
			{
				tmp->next=head3;
				head3=tmp;
			}
			while(r!=NULL) //查找并插入 
			{
				if((tmp->ci)==(r->ci))
				{
					r->xi=(r->xi)+(tmp->xi);
					break;
				}
				else if(r->next==NULL)
				{
					tmp->next=r->next;
					r->next=tmp;
					break;
				}
				else if((tmp->ci)<(r->ci) && (tmp->ci)>(r->next->ci))
				{
					tmp->next=r->next;
					r->next=tmp;
					break;
				}
				else r=r->next;
			}
			q=q->next;
		}
		p=p->next;
		q=head2; 
	}
	r=head3;
	while(r!=NULL)
	{
		printf("%d %d ", r->xi, r->ci);
		r=r->next;
	}
	return 0;
}

