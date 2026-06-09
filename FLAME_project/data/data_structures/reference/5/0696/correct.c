#include<stdio.h>
#include<malloc.h>

typedef struct link{
	int coe;
	int index;
	struct link * Next;
}LINK,*PLINK;

//º¯ÊýÉùÃ÷ 
PLINK init(void);
PLINK traverse(PLINK,PLINK);
void bubble_sort(PLINK);
void get_ans(PLINK);
void check(PLINK);

int main(){
	PLINK Link_1,Link_2,Link_3;
	Link_1=init();
	Link_2=init();
	Link_3=	traverse(Link_1,Link_2);	
	bubble_sort(Link_3);
//	check(Link_3);
	get_ans(Link_3);
	return 0;
}


void check(PLINK check){
	PLINK p = check->Next;
	while(p!=NULL){
		printf("%d %d\n",p->coe,p->index);
		p=p->Next;
	}
}

void get_ans(PLINK Link_3){
	PLINK p;
	p=Link_3->Next;
	while(p!=NULL){
		if(p->coe>0)
		{printf("%d ",p->coe);
		printf("%d ",p->index);
	}
		p=p->Next;
	}
}

void bubble_sort(PLINK Link_3){
	PLINK p1;
	p1=Link_3->Next;
//	printf("%d",p1->coe);
	for(;NULL!=p1;p1=p1->Next){
		PLINK p2=p1->Next;
		for(;NULL!=p2;p2=p2->Next){
			if(p2->index>p1->index){
				p2->index=p2->index^p1->index;
				p1->index=p2->index^p1->index;
				p2->index=p2->index^p1->index;
				p2->coe=p2->coe^p1->coe;
				p1->coe=p2->coe^p1->coe;
				p2->coe=p2->coe^p1->coe;
				
			}
			if(p2->index==p1->index){
				p1->coe+=p2->coe;
				p2->coe=0;
			}
		}
	}
}

PLINK traverse(PLINK Link_1,PLINK Link_2){
	PLINK Link_3=(PLINK)malloc(sizeof(LINK));
	Link_3->Next=NULL;
	PLINK p1,p2,p;
	p1=Link_1->Next;
	p=Link_3;
	while(p1!=NULL){
		p2=Link_2->Next;
		while(p2!=NULL){
		PLINK New;
		New=(PLINK)malloc(sizeof(LINK));
		New->Next=NULL;
		p->Next=New;
		p=New;
//		printf("p1=%d p2=%d\n",p1->coe,p2->coe);
		New->coe=(p1->coe)*(p2->coe);
//		printf("New%d\n",New->coe);
		New->index=p1->index+p2->index;
		p2=p2->Next;
		}
		p1=p1->Next;
	}
	return Link_3;
}

PLINK init(void){
	PLINK Head = (PLINK)malloc(sizeof(LINK));
	Head->Next=NULL;
	PLINK New,p;
	char ch;
	p=Head;
	do{
		New = (PLINK)malloc(sizeof(LINK));
		New->Next=NULL;
		p->Next=New;
		p=New;
		scanf("%d%d%c",&New->coe,&New->index,&ch);
//		printf("%d\n",New->coe);
	}while(ch!='\n');
	return Head;
}



