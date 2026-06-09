#include<stdio.h>
struct line{
	int x1,y1;
	int x2,y2;
	struct line *p;
}l[105],*q;
int main(){
	int n,i,j=0,cnt[105]={0},max=0,mark;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	   scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	   l[i].p=NULL;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j) continue;
			else if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1){
					l[i].p=&l[j];
				}
			else if(l[j].x2==l[i].x1&&l[j].y2==l[i].y1){
					l[j].p=&l[i];
			}
		}
	}
	for (i=0;i<n;i++){
        q=&l[i];
        while (q!=NULL){
     	if (q->p!=NULL) {
      	cnt[i]++;
       	q=q->p;
    	}
   		else break;
  		}
 	}
 	for(i=0;i<n;i++){
 		if(cnt[i]+1>max){
 			max=cnt[i]+1;
 		    mark=i;
		 }
	 }
    printf("%d %d %d",max,l[mark].x1,l[mark].y1);
	return 0;
} 



