#include<stdio.h>
struct point{
	int left_x;
	int left_y;
	int right_x;
	int right_y;
	int number;
};
int main(){
	int n;//n是输入的线段数量
	int i;
	int j;
	int length[105]={1};//最开始是一条线段，每多连一条线段length加一 
	int x;
	int y;
	struct point p[105];
	struct point a;
	int maxlen=1;
	int k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&p[i].left_x ,&p[i].left_y ,&p[i].right_x ,&p[i].right_y );
		p[i].number =i+1;//标记它是第几条 
	}//从第0条开始，到第n-1条结束
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(p[j].left_x >p[j+1].left_x ){
			   a=p[j];
			   p[j]=p[j+1];
			   p[j+1]=a;
			}
		}//冒泡排序,把线段左端点从小到大排序 
    }
 
	for(i=0;i<n-1;i++){//遍历到倒数第二条线段结束 
	    length[i]=1;
		x=p[i].right_x ;
		y=p[i].right_y ;
		for(j=i+1;j<=n-1;j++){//从当前线段的后一条开始找 
			if(p[j].left_x ==x&&p[j].left_y ==y){//能接上 
				length[i]++;
				x=p[j].right_x ;
				y=p[j].right_y ;
			}
			else continue;
		}
	}
	for(i=0;i<n;i++){
		if(length[i]>maxlen){
			k=i;
			maxlen=length[i];
		}
		else continue;
	}
	printf("%d %d %d",maxlen ,p[k].left_x ,p[k].left_y );

return 0;
} 

