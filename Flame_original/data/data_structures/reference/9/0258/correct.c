#include<stdio.h>
#include<stdlib.h>
typedef struct _loc{
	int x1;
	int y1;
	int x2;
	int y2;
}loc,*Ploc;
loc pos[100];
int _x2,_y2,i=0;
int longest_len=1,longest_order,temp=1;
int cmp(const void *a,const void *b);
int N;
void sort(loc a); 
int main(){
	scanf("%d",&N);
	int i=0;
	for(i=0;i<N;i++)
		scanf("%d %d %d %d",&pos[i].x1,&pos[i].y1,&pos[i].x2,&pos[i].y2);
	qsort(pos,N,sizeof(loc),cmp);
	i=0;
	while(i<N){
		sort(pos[i]);
		if(temp>longest_len){
			longest_len=temp;
			longest_order=i;
		}		
		i++; temp=1;
	}
	printf("%d %d %d",longest_len,pos[longest_order].x1,pos[longest_order].y1);
	return 0;
} 
int cmp(const void *a,const void *b){
	Ploc position1=(Ploc)a;
	Ploc position2=(Ploc)b;
	int ans;
	ans=(position1->x1)-(position2->x1);
	return ans;
}
void sort(loc a){
	_x2=a.x2;_y2=a.y2;
	for(int j=0;j<N;j++){
		if(pos[j].x1==_x2&&pos[j].y1==_y2) {
			temp++;
			sort(pos[j]);
		}
		else continue;
	} 
}

