#include<stdio.h>
struct dian{
	int a1[2];
	int a2[2];
}point[101],tmp;
int main(){
	int n;
	scanf("%d",&n);
	int i,j,k;
	int x1,y1;//用来记录连接线段最多的起始点 
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&point[i].a1[0],&point[i].a1[1],&point[i].a2[0],&point[i].a2[1]);
	}
	//接下来对每条线段按左端点大小进行排序
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(point[i].a1[0]>point[j].a1[0]){
				tmp=point[j];
				point[j]=point[i];
				point[i]=tmp;
			}
		}
	} 
	int max=0; 
	int length=1;
	for(i=0;i<n;i++){
		length=1;	
		 k=i;//记下此时线段 
		//从每一条线段开始遍历连接找可以连接的线段
		 for(j=i+1;j<n;j++){
		 	if(point[j].a1[0]==point[k].a2[0]&&point[j].a1[1]==point[k].a2[1])
		{
		    length++;
			  k=j;
		}
	}
		 if(length>max)
		 {
		 	max=length;
		 	x1=point[i].a1[0];
	        y1=point[i].a1[1];
		 }
			 }
			 printf("%d %d %d",max,x1,y1);
			 return 0;
		}

