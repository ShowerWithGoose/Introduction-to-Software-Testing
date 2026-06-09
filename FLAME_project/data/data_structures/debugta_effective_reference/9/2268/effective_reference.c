#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
//int范围：2147483647 (-2^31--2^31-1)
//scanf("%%",&,&);
//printf("%",);
//for(int i=0;i<n;i++){}
//if(){}
struct infor{
	int x1,y1,x2,y2,flag;
}spot[1007],hold;

int main(){
	int n,temp[1007],ans=0,pos=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&spot[i].x1,&spot[i].y1,&spot[i].x2,&spot[i].y2);
	}
	for(int i=0;i<n;i++){
		spot[i].flag=i,temp[i]=1;
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(spot[j].x1>spot[j+1].x1){
				hold=spot[j],spot[j]=spot[j+1],spot[j+1]=hold;
			}
		}
	}
	//前期准备
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((spot[i].x2==spot[j].x1)&&(spot[i].y2==spot[j].y1)){
			spot[j].flag=spot[i].flag;
			}
		}
	}//标记相等
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(spot[i].flag==spot[j].flag){
				temp[i]++;
			}
		}
	}//统计次数
	
	for(int i=0;i<n;i++){
		if(ans<temp[i]) {
			ans=temp[i],pos=i;}
	}
	
	//找最大次数，最小坐标
	
	printf("%d %d %d",ans,spot[pos].x1,spot[pos].y1);//输出
	return 0;	
}

