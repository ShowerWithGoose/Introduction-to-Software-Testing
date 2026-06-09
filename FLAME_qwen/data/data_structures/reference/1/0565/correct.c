#include <stdio.h>
#include <stdlib.h>
int N;
typedef struct num *pn;
struct num{
	int x;
	pn up;
	pn down;
};
pn number;
pn init();
void add(pn,pn,int);
void output();
void delete(pn,pn);
void change(pn,pn);
void set();
void xu(int);
void clear(int);
int main()
{
	number=init();
	scanf("%d",&N);
	xu(0);
	//output();
}
pn init()
{
	pn ptrl;
	ptrl=(pn)malloc(sizeof(struct num));
	ptrl->x=0;
	ptrl->up=ptrl;
	ptrl->down=ptrl;
	return ptrl;
}
void add(pn head,pn tail,int y)
{
	pn ptrl=init();
	ptrl->x=y;
	head->down=ptrl;
	ptrl->up=head;
	tail->up=ptrl;
	ptrl->down=tail;
}
void output()
{
	pn ptrl=number->up;
	while (ptrl!=number){
		printf("%d ",ptrl->x);
		ptrl=ptrl->up;
	}
	printf("\n");
}
void delete(pn head,pn tail)
{
	pn ptrl=head->down;
	head->down=tail;
	tail->up=head;
	free(ptrl);
}
void xu(int x)
{
	int i,judge;
	pn tmp;
	
	//printf("%d  ",x);
	//output();
	for (i=1;i<=N;i++){
		//printf("%d ",i);
		clear(x);
		judge=1;
		tmp=number->down;
		while (tmp!=number){
			if (tmp->x==i){
				judge=0;
				break;
			}
			tmp=tmp->down;
		}
		if (judge){
			add(number,number->down,i);
			//printf("%d\n",number->down->x);
			number->x++;
			if (number->x==N){
				output();
				//clear();
				break;
			}
			xu(x+1);
		}
		
	}
}
void clear(int xxy)
{
	int i;
	pn ptrl=number,tmp;
	for (i=0;i<xxy;i++){
		ptrl=ptrl->up;
	}
	while (ptrl->up!=number){
		tmp=ptrl->up;
		ptrl->up=tmp->up;
		free(tmp);
	}
	number->down=ptrl;
	number->x=xxy;
}

