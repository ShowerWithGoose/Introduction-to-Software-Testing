#include<stdio.h>
#include<string.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	struct line *next;
}number[105],*p,*begin;;
int main(){
	int n,i=0,j=0,sum=0,max=0;
	scanf("%d",&n);
	while(i<n){
		scanf("%d%d%d%d",&number[i].x1,&number[i].y1,&number[i].x2,&number[i].y2);
		number[i].next = NULL;
		i++;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(number[i].x2==number[j].x1&&number[i].y2==number[j].y1){
				number[i].next=&number[j];
				break;
			}
		}
	}
	for(i=0;i<n;i++){
		p=&number[i];
		while(p!=NULL){
			sum++;
			p=p->next;
		}
		if(sum>max){
			max=sum;
			begin=&number[i];
		}
		sum=0;
	}
	printf("%d %d %d",max,begin->x1,begin->y1);
	return 0;
} 

