#include<stdio.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};
int main(){
	struct line a[100];
	struct line temp;
	int n,i,j,max,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(i=0;i<n;i++){
		a[i].num=1;
	}//线段长度都初始化为1 
	 for(i=0;i<n;i++){
	 	for(j=i;j<n;j++){
	 		if(a[i].x1>a[j].x1){
	 			temp=a[i];
	 			a[i]=a[j];
	 			a[j]=temp;
			 }//交换顺序 
			 else if(a[i].x1==a[j].x1&&a[i].y1>a[j].y1){
			 	temp=a[i];
	 			a[i]=a[j];
	 			a[j]=temp;
			 } 
		 }
	 }//给线段排序 
	 for(i=0;i<n;i++){
	 	for(j=0;j<n;j++){
	 		if(i!=j){
	 			if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1){
	 				a[i].x2=a[j].x2;
	 				a[i].y2=a[j].y2;
	 				a[i].num+=a[j].num; 
	 				a[j].x1=0;
	 				a[j].y1=0;
	 				a[j].x2=0;
	 				a[j].y2=0;
	 				a[j].num=0;
				 }
			 }
		 }
	 }//连线 
	 max=a[0].num;
	 k=0;
	 for(i=0;i<n;i++){
	 	if(a[i].num>max){
	 		max=a[i].num;
	 		k=i;
		 }
	 }//找出最长线段
	  printf("%d %d %d",max,a[k].x1,a[k].y1);
	  return 0;
}

