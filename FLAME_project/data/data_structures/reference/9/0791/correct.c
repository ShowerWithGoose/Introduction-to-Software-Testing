#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct dot{
	int x;
	int y;
	int num;
	int mark;
};
struct dot a[400],b[400];
int cmp(const void*a1,const void*b1){
	struct dot*a=(struct dot*)a1;
	struct dot*b=(struct dot*)b1;
	if(a->x>b->x){
		return 1;
	}
	else if(a->x<b->x){
		return -1;
	}
	else{
		if(a->y>b->y){
		return 1;
	}
	else{
		return -1;
	}
	}
	
}
int main(){
   int n,i,i0,num=1,cnt,i1;
   scanf("%d",&n);
   struct dot ans;
   for(i=0;i<=2*n-2;i+=2){
   	scanf("%d %d %d %d",&a[i].x,&a[i].y,&a[i+1].x,&a[i+1].y);
   	a[i].num=a[i+1].num=i/2+1;
   	a[i].mark=a[i+1].mark=1;
   }
  
   qsort(a,2*n,sizeof(a[0]),cmp);
   
   for(i=0;i<=2*n-1;i++){
   	if(a[i].mark==1){
   		b[num]=a[i];
   		i0=i;
   		cnt=0;
   		while(1){
   			a[i0].mark=0;
   			i1=i0+1;
   			while(a[i1].num!=a[i0].num){
   				i1++;
			   }
			   i0=i1;
			   a[i0].mark=0;
			   cnt++;
			   if(a[i0+1].x==a[i0].x&&a[i0+1].y==a[i0].y){
			   	i0++;
			   }
			   else if(a[i0-1].x==a[i0].x&&a[i0-1].y==a[i0].y){
			   	i0--;
			   }
			   else{
			   	b[num].num=cnt;
			   	num++;
			   	break;
			   }
		   }
	   }
   }
   ans.num=0;
   for(i=1;i<=num-1;i++){
   	 if(b[i].num>ans.num){
   	 	ans=b[i];
		}
   }
   printf("%d %d %d",ans.num,ans.x,ans.y);
  return 0;
}


