#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int a[101][4],number=1,max_num=0,i,j,k,temp[4],m;

void fromSmallToBig(int a[ ][4],int n){
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i][0]>a[j][0]){
				for(k=0;k<=3;k++){
					temp[k]=a[i][k];
				}
				for(k=0;k<=3;k++){
					a[i][k]=a[j][k];
				}
				for(k=0;k<=3;k++){
					a[j][k]=temp[k];
				}
			}//线段全按照x1从小到大排 
		}
	}
}

int main(){
	int n;
	int one_x,one_y;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	fromSmallToBig(a,n);
	
//	for(i=0;i<n;i++){
//		for(j=0;j<4;j++){
//			printf("%d ",a[i][j]);
//		}
//		printf("\n");
//	}
	
	for(i=0;i<n;i++){
		m=i;
		number=1;
		for(j=i+1;j<n;j++){
			if(a[m][2]==a[j][0]){
				if(a[m][3]==a[j][1]){
					number++;
					m=j;//连起来 
				} 
			}
		}
		if(number>max_num){
			max_num=number;
			one_x=a[i][0];
			one_y=a[i][1];
		}
	} 
	printf("%d %d %d",max_num,one_x,one_y);
	return 0;
}

























/*struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
	struct line *link;
};
typedef struct line line;

int main(){
	int n;
	scanf("%d",&n);
	int i;
	line *t=NULL,*list=NULL,*p=NULL;
	
	for(i=0;i<n;i++){
		t=(line *)malloc(sizeof(line));
		scanf("%d",&t->x1);
		scanf("%d",&t->y1);
		scanf("%d",&t->x2);
		scanf("%d",&t->y2);
		
		if(list==NULL){
			list=p=t;
			list->num=0;
			p->num=0;
		}
		else{
			p->link=t;
			p=p->link;
			p->num=0;
		}
		t->link=NULL;
	}//输入了n个线段，并把它们的坐标存入链表
	
	line *a=NULL,*r=NULL;
	for(p=list;p->link!=NULL;p=p->link){
//		a=p->link;
//		r=p;
		while(a->link!=NULL){
			if(((a->x1==p->x2)&&(a->y1==p->y2))||((a->x2==p->x1)&&(a->y2==p->y1))){
				p->num++;
				if((a->x1==p->x2)&&(a->y1==p->y2)){
					p->x2=a->x2;
					p->y2=a->y2;
				}
				else if((a->x2==p->x1)&&(a->y2==p->y1)){
					p->x1=a->x1;
					p->y1=a->y1;
				}//删除a
//				r->link=a->link; 
//				free(a);
//				a=r->link;
			}
//			else{
//				r=a;
//				a=a->link;
//			}
		}
	}
}*/







