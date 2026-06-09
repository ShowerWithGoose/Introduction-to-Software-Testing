#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Polynomial* Poly;
struct Polynomial{
	int coefficient,exsponent;
	Poly next;
};

/*常规链表操作-部分*/
Poly creatPoly(void)
{
	Poly P=(Poly)malloc(sizeof(struct Polynomial));
	P->coefficient=-1; 
	P->exsponent=-1;//-1为空标志,题目规定指数恒正 
	P->next=NULL;
	return P;
}

Poly insert(Poly head,int coef,int exsp)
{
	/*为了能在乘法步骤中使用，仍有序检索*/
	Poly ptr,tmp;
	if(head->exsponent==-1){//是个空表 
		head->coefficient=coef;
		head->exsponent=exsp;
		head->next=NULL;
		return head;
	}
	else if(head->exsponent<exsp){//要新表头 
		tmp=(Poly)malloc(sizeof(struct Polynomial));
		tmp->coefficient=coef;
		tmp->exsponent=exsp;
		tmp->next=head;
		return tmp;
	}
	else if(head->exsponent==exsp){//恰好在开头相等 
		head->coefficient+=coef;
		return head;
	}
	ptr=head;
	while(ptr->next!=NULL&&ptr->next->exsponent>exsp){
		ptr=ptr->next;
	}
	if(ptr->next==NULL){
		ptr->next=(Poly)malloc(sizeof(struct Polynomial));
		ptr=ptr->next;
		ptr->coefficient=coef;
		ptr->exsponent=exsp;
		ptr->next=NULL;
		return head;
	}
	else if(ptr->next->exsponent==exsp){
		ptr->next->coefficient+=coef;
		return head;
	}
	else{
		tmp=(Poly)malloc(sizeof(struct Polynomial));
		tmp->coefficient=coef;
		tmp->exsponent=exsp;
		tmp->next=ptr->next;
		ptr->next=tmp;
		return head;
	}
}

Poly multi(Poly head1,Poly head2)
{
	Poly ans,ptr1,ptr2;
	int coef,exsp;
	ans=creatPoly();
	for(ptr1=head1;ptr1!=NULL;ptr1=ptr1->next){
		for(ptr2=head2;ptr2!=NULL;ptr2=ptr2->next){
			coef=(ptr1->coefficient)*(ptr2->coefficient);
			exsp=ptr1->exsponent+ptr2->exsponent;
			ans=insert(ans,coef,exsp);
		}
	}
	return ans;
}

void printPoly(Poly head)
{
	while(head!=NULL){
		printf("%d %d ",head->coefficient,head->exsponent);
		head=head->next;
	}
}

int main()
{
	Poly head1,head2,ans;
	int coef,exsp;
	char endCheck;
	head1=creatPoly();
	head2=creatPoly();
	/*输入，最后一项没有空格，只有\n*/
	do{
		scanf(" %d %d%c",&coef,&exsp,&endCheck);
		head1=insert(head1,coef,exsp);
	}while(endCheck!='\n');
	do{
		scanf(" %d %d%c",&coef,&exsp,&endCheck);
		head2=insert(head2,coef,exsp);
	}while(endCheck!='\n');
	ans=multi(head1,head2);
	printPoly(ans);
	return 0;
}

