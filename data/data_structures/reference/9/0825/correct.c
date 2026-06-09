#include<stdio.h>
struct xianduan{
	int x1;
	int y1;
	int x2;
	int y2;
};
struct xianduan hao[105];
int bijiao(struct xianduan *p,struct xianduan *q);
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&hao[i].x1,&hao[i].y1,&hao[i].x2,&hao[i].y2);
	}
	qsort(hao,n,sizeof(struct xianduan),bijiao);
	/*for(i=0;i<n;i++){
		printf("%d %d %d %d\n",hao[i].x1,hao[i].y1,hao[i].x2,hao[i].y2);
	}*/
	int j,k,l,max_x,max_y,max=0;
	for(i=0;i<n;i++){
		l=1;
		for(j=i+1,k=i;j<n;j++){
			if(hao[j].x1==hao[k].x2&&hao[j].y1==hao[k].y2){
				l++,
				k=j;
			}
		}
		if(l>max){
			max=l;
			max_x=hao[i].x1;
			max_y=hao[i].y1;
		}
	}
	printf("%d %d %d",max,max_x,max_y);
	return 0;
}
int bijiao(struct xianduan *p,struct xianduan *q){
	if((p->x1)>(q->x1))return 1;
	else return -1;
}

