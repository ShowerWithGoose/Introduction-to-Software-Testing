#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int nex;
}; 
int main(){
	struct line a[100];
	int sum=0,tmp,tg=0,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].nex=0;
	}
	for(int i=1;i<=n;i++){
		tmp=1;
		struct line b[100];
		b[i]=a[i];
		for(int j=1;j<=n;){
			if(b[i].x2==a[j].x1&&b[i].y2==a[j].y1){
				b[i].x2=a[j].x2;
				b[i].y2=a[j].y2;
				tmp++;
				j=1;
				continue;
			}
			else
				j++;
		}
		a[i].nex=tmp;
	}
	for(int i=1;i<=n;i++){
		if(a[i].nex>sum){
			sum=a[i].nex;	
			tg=i;	
		}
	}
	printf("%d %d %d",sum,a[tg].x1,a[tg].y1);
	return 0;
}


