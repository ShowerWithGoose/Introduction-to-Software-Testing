#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct list{
	int xs;
	int zs;
	struct list *next;
}NODE;

NODE *temp,tab[100000];
int num;

NODE *get();
int deal(NODE *a,NODE *b);
int comp(const void* a,const void* b);

int main(){
	struct list head1,head2;
	
	scanf("%d%d",&head1.xs,&head1.zs);
	head1.next=NULL;
	temp = &head1;
	while(getchar()!='\n'){
		temp->next = get();
		temp = temp->next;
	}
	
	scanf("%d%d",&head2.xs,&head2.zs);
	head2.next=NULL;
	temp = &head2;
	while(getchar()!='\n'){
		temp->next = get();
		temp = temp->next;
	}
	
	num = deal(&head1,&head2);
	qsort(tab,num,sizeof(tab[0]),comp);
	for(int i=0;i<num;i++){
		if(i!=num-1&&tab[i].zs==tab[i+1].zs){
			tab[i+1].xs+=tab[i].xs;
		}
		else printf("%d %d ",tab[i].xs,tab[i].zs);
	//	printf("%d %d ",tab[i].xs,tab[i].zs);
	}
	return 0;
}

NODE *get(){
	NODE *t = (NODE *)malloc(sizeof(NODE));
	scanf("%d%d",&t->xs,&t->zs);
	t->next=NULL;
	return t;
}

int deal(NODE *a,NODE *b){
	NODE *aa = a;
	NODE *bb = b;
	int i=0;
	for(;;aa=aa->next){
		bb = b;
		for(;;bb=bb->next,i++){
			tab[i].xs = aa->xs*bb->xs;
			tab[i].zs = aa->zs+bb->zs;
			if(bb->next==NULL){
				i++;
				break;
			}
		}
		if(aa->next==NULL) break;
	}
	return i;
}

int comp(const void* a,const void* b){
	NODE *aa = (NODE*)a;
	NODE *bb = (NODE*)b;
	return -(aa->zs-bb->zs);
//	if(aa->zs>bb->zs) return -1;
//	else if(aa->zs==bb->zs) return 0;
//	else if(aa->zs<bb->zs) return 1;
//	return 0;
}


