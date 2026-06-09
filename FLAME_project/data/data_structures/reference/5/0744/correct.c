#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//解题思路：可以先搞一个双循环来先乘完 然后再用一个双循环来合并同类项
//缺点：时间复杂度太大  但是思路简单

struct poly{
	int ratio;
	int index;
	struct poly* link;
};

struct answer{
	int ratio;
	int index;
}ans[100000]; 
void create_list(struct poly* head_elem)
{
	struct poly *last,*p;
	char c;//用c来判断输入的终止条件
	last=head_elem;
	do{
		p=(struct poly*)malloc(sizeof(struct poly));
		last->link=p;
		p->link=NULL;
		last=p;
		scanf("%d %d",&p->ratio,&p->index);
		scanf("%c",&c); //读每一项后面的字符来判断循环是否结束 
	}while(c!='\n'); 
 } 
 
 //接下来开始乘
 
struct poly * ans_head;
void mult(struct poly *head_elem1,struct poly *head_elem2) 
{
	ans_head=(struct poly*)malloc(sizeof(struct poly));
	struct poly*last,*p,*q,*ans_elem;
	last=ans_head;
	p=head_elem1;
	q=head_elem2;
	while((p->link)!=NULL)
	{
		p=p->link;
		q=head_elem2;
		while((q->link)!=NULL)
		{
			q=q->link;
			ans_elem=(struct poly*)malloc(sizeof(struct poly));
			ans_elem->ratio=(p->ratio)*(q->ratio);
			ans_elem->index=(p->index)+(q->index);
			last->link=ans_elem;
			last=ans_elem;
			ans_elem->link=NULL;
		}
	 } 
}

//接下来开始合并同类项  ans_head 

void conbine_elems(void)
{
	struct poly *current,*later;
	current=ans_head;
	while((current->link)!=NULL)
	{
		current=current->link;
		later=current; 
		while((later->link)!=NULL)
		{
			struct poly* p1=later;
			later=later->link;
			if(later->index==current->index)
			{
				current->ratio+=later->ratio;
				p1->link=later->link;
				free(later);
			}
		}
	}
 } 
 
 //开始输出
int cnt=0;
void input_ans(void)
{
	
	struct poly * input;
	input=ans_head;
	while((input->link)!=NULL)
	{
		input=input->link;
		if(input->ratio!=0)
		{
	    ans[cnt].ratio=input->ratio;
        ans[cnt].index=input->index;
        cnt++;
		}
       
	}
}

int cmp(const void*p1,const void*p2)
{
	return ((((struct answer*)p1)->index)-(((struct answer*)p2)->index))>0?-1:1;
}
int main()
{
	struct poly *head_elem1=(struct poly*)malloc(sizeof(struct poly));
    struct poly *head1=(struct poly*)malloc(sizeof(struct poly));
    head1=head_elem1;
    head_elem1->link=NULL;
    struct poly *head_elem2=(struct poly*)malloc(sizeof(struct poly));
    struct poly *head2=(struct poly*)malloc(sizeof(struct poly));
    head2=head_elem2;
    head_elem2->link=NULL;
    create_list(head_elem1);
    create_list(head_elem2);
    mult(head_elem1,head_elem2);
    conbine_elems();
    input_ans(); 
    qsort(ans,cnt,sizeof(ans[0]),cmp);
    int i;
    for(i=0;i<cnt;i++)
    printf("%d %d ",ans[i].ratio,ans[i].index);
    return 0;
}

