#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct loc{
	int cnt;
	int x1;
	int x2;
	int y1;
	int y2;
};
struct loc Loc[105];
int cmpbyloc(const void*p1,const void*p2){
	struct loc *a=(struct loc*)p1;
	struct loc *b=(struct loc*)p2;
	if((a->x1)!=(b->x1)) return a->x1-b->x1;
	else return a->y1-b->y1;
}
int cmpbycnt(const void*p1,const void*p2){
	struct loc *a=(struct loc*)p1;
	struct loc *b=(struct loc*)p2;
	return b->cnt-a->cnt;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&Loc[i].x1,&Loc[i].y1,&Loc[i].x2,&Loc[i].y2);
	}
	//for(i=0;i<n;i++){
	//	printf("%d %d %d %d\n",Loc[i].x1,Loc[i].y1,Loc[i].x2,Loc[i].y2);
	//}
	qsort(Loc,n,sizeof(struct loc),cmpbyloc);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if((Loc[i].x2==Loc[j].x1)&&(Loc[i].y2==Loc[j].y1)){
				Loc[i].x2=Loc[j].x2;Loc[i].y2=Loc[j].y2;
				Loc[i].cnt++;
				Loc[j].x2=0;
				Loc[j].y2=0;
			}
		}
	}
	qsort(Loc,n,sizeof(struct loc),cmpbycnt);
	printf("%d %d %d",Loc[0].cnt+1,Loc[0].x1,Loc[0].y1);
	return 0;
}

