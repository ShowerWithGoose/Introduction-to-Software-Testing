#include<stdio.h>
typedef struct dote1{
	int x1;
	int y1;
	int x2;
	int y2;
	int count;
}Dote1;
int main(){
	Dote1 a[105], n;
	int b, i, j, flag=0, max=0, k;
	int *c[105];
	scanf("%d",&b);//输入线段个数 
	for(i=0;i<b;i++){
		a[i].count=0;
		c[i]=&a[i].count;
	}
	for(i=0;i<b;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}//输入线段端点 
	for(i=0;i<b;i++){
		for(j=i+1;j<b;j++){
			if((a[i].x1==a[j].x1&&a[i].y1==a[j].y1)||(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)||(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)||(a[i].x2==a[j].x2&&a[i].y2==a[j].y2)){
				//判断线段是否有端点重合 
				if(*c[i]==0 && *c[j]==0) c[j]=c[i];
				else if(*c[i]!=0 && *c[j]==0) c[j]=c[i];
				else if(*c[i]==0 && *c[j]!=0){
					c[i]=c[j];
				}
				else if(c[i]!=0 && c[j]!=0){
					*c[i]=*c[i]+*c[j];
					for(k=0;k<b;k++){
						if(c[k]==c[j]) c[k]=c[i];
					}
				}
				(*c[i])++;
			}
		}
	}
	max=*c[0];
	for(i=1;i<b;i++){
		if(max<*c[i]){
			max=*c[i];flag=i;
		}
	}//找出包含最多连续线段的个数 
	n.x1=a[flag].x1;
	n.y1=a[flag].y1;
	for(i=flag+1;i<b;i++){
		if(c[flag]==c[i]){
			if(n.x1>a[i].x1){
				n.x1=a[i].x1;
				n.y1=a[i].y1;
			}
		}
	}//找出连续线段起点 
	printf("%d %d %d",max+1,n.x1,n.y1);
	return 0;
}


