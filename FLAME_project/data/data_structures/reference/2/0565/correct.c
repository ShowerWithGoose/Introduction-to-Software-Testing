#include <stdio.h>
#include <stdlib.h>
typedef struct num *pn;
typedef struct fu *pf;
struct num{
	int a;
	pn next;
};
struct fu{
	char f;
	pf next;
};
pn number;
pf fuhao;
pn num_set();
pf fu_set();
void input();
void insert_num(int);
void insert_fu(char);
int grade(char);
void calculate();
int main()
{
	number=num_set();
	fuhao=fu_set();
	input();
	return 0;
}
pn num_set()
{
	pn ptrl;
	ptrl=(pn)malloc(sizeof(struct num));
	ptrl->next=NULL;
	return ptrl;
}
pf fu_set()
{
	pf ptrl;
	ptrl=(pf)malloc(sizeof(struct fu));
	ptrl->next=NULL;
	return ptrl;
}
void input()
{
	char c;int store=0;
	while ((c=getchar())!='='){
		if (c==' ')
			continue;
		else if (c>='0'&&c<='9'){
			store=store*10+c-'0';
		}
		else {
			insert_num(store);
			store=0;

			if (fuhao->next==NULL||grade(fuhao->next->f)<grade(c)){
				insert_fu(c);
				//if (fuhao->next->next!=NULL)
					//printf("%d %d %c\n",grade(fuhao->next->next->f),grade(c),c);
			}
			else{
				while (fuhao->next!=NULL&&grade(fuhao->next->f)>=grade(c)){
					calculate();
				}
				insert_fu(c);
			}
		}
	}
	insert_num(store);
	while (number->next->next!=NULL){
		calculate();
	}
	printf("%d",number->next->a);
}
void insert_num(int x)
{
	pn ptrl;
	ptrl=(pn)malloc(sizeof(struct num));
	ptrl->next=number->next;
	number->next=ptrl;
	ptrl->a=x;

}
int grade(char x)
{
	if (x=='+'||x=='-')
		return 0;
	else
		return 1;
}
void insert_fu(char x)
{
	pf ptrl;
	ptrl=(pf)malloc(sizeof(struct fu));
	ptrl->next=fuhao->next;
	fuhao->next=ptrl;
	ptrl->f=x;
}
void calculate()
{
	pn ptrl_n=number->next;
	pf ptrl_f=fuhao->next;
	int ans=0,a,b;
	char c=ptrl_f->f;
	a=ptrl_n->a;
	b=ptrl_n->next->a;
	if (c=='+'){
		ans=b+a;
	}
	else if (c=='-'){
		ans=b-a;
	}
	else if (c=='*'){
		ans=b*a;
	}
	else if (c=='/'){
		ans=b/a;
	}
	ptrl_n->next->a=ans;
	number->next=ptrl_n->next;
	free(ptrl_n);
	fuhao->next=ptrl_f->next;
	free(ptrl_f);
}



