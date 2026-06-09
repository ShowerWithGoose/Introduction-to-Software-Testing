#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct line{
	int x1;
	int x2;
	int y1;
	int y2;
	int len;
}a[110]; 
int num=1;//Ïß¶Î³¤¶È 

void connect(struct line k,struct line a[],int n){
	int i;
	for(i=0;i<n;i++){
		if(k.x2==a[i].x1&&k.y2==a[i].y1){
			num++;
			connect(a[i],a,n);
		}
	}
}

int main(){
	int i,n,ans,max=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(i=0;i<n;i++){
		num=1;
		connect(a[i],a,n);
		a[i].len=num;
	}
	for(i=0;i<n;i++){
		if(a[i].len>max){
			max=a[i].len;
			ans=i;
		}
	}
	printf("%d %d %d",max,a[ans].x1,a[ans].y1);
	return 0; 
} 



