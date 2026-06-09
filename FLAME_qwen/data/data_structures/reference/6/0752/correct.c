#include<stdio.h>
#include<stdlib.h>
#define type int
typedef struct LIST{
	int top;
	int rear;
	int size;
	type *p;
}list,*listptr;
extern list initList(size_t);
extern void listIn(type,listptr);
extern type listTopOut(listptr);
extern type listRearOut(listptr);
extern void displayList(list);
extern int isEmpty(list);
int main() {
	list l=initList(100);
//	printf("%d\n",l.top);
	int data;
	while(scanf("%d",&data)){
		if(data==1){
			scanf("%d",&data);
//			printf("%d\n",l.top);
			if(l.top==99){
				printf("error ");
			}else{
				listIn(data,&l);
			}
		}else if(data==0){
			if(l.top==-1){
				printf("error ");
			}else{
				printf("%d ",listTopOut(&l));
			}
		}else{
			break;
		}
	}
	return 0;
}
list initList(size_t listSize){
	list l;
	l.p=(type*)malloc(sizeof(type)*listSize);
	l.size=listSize;
	l.top=-1;
	l.rear=0;
	return l;
}
void listIn(type data,listptr l_add){
	l_add->top=(++l_add->top)%l_add->size;
	l_add->p[l_add->top]=data;
	return;
}
type listTopOut(listptr l_add){
	type data=l_add->p[l_add->top];
	l_add->top--;
	return data;
}
type listRearOut(listptr l_add){
	type data=l_add->p[l_add->rear];
	l_add->rear=(++l_add->rear)%l_add->size;
	return data;
}
void displayList(list l){
	int i=l.rear-1;
	do{
		i=(++i)%l.size;
		printf("%d ",l.p[i]);
	}while(i!=l.top);
	printf("\n");
	return;
}
int isEmpty(list l){//特别的，当列表装满的时候显示的状态和为空的状态相同 
	return ((l.top+1)%l.size==l.rear)?1:0;
}

