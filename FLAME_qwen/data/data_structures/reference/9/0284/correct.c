#include<stdio.h>
typedef struct nod{
	int x1,y1;
	int x2,y2;
	struct nod *pr;
}NODE;
int find(NODE *p){
	int i=1;
	NODE *temp;
	temp=p->pr;
	while(temp!=NULL){
		i++;
		temp=temp->pr;
	}
	return i;
}
NODE node[100];
int main(){
	int N,max=0,tempint;
	NODE *tp;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2);
		node[i].pr=NULL;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(j==i)continue;
			if(node[j].x1==node[i].x2&&node[j].y1==node[i].y2){
				node[i].pr=&node[j];
				break;
			}
		}
	}
	for(int i=0;i<N;i++){
		if((tempint=find(&node[i]))>max){
			max=tempint;
			tp=&node[i];
		}
	}
	printf("%d %d %d",max,tp->x1,tp->y1);
	return 0;
}
