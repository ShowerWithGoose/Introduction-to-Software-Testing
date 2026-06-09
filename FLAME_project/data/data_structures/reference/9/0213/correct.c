#include<stdio.h>
typedef struct _line{
	int x1;
	int y1;
	int x2;
	int y2;
	int flag;
}line,*pline;
line a[105];
int n,LX,LY,RX,RY,ll,rr,Lx,Ly,Rx,Ry;
void left(int lx,int ly){
	int j,mark=0;
	for(j=0;j<n;j++){
		if(a[j].flag==1){
			continue;
		}else{
			if(a[j].x2==lx&&a[j].y2==ly){
				a[j].flag=1;
				mark=1;
				ll++;
				left(a[j].x1,a[j].y1);
				break;
			}
		}
	}
	if(mark==0){
		Lx=lx;
		Ly=ly;
	}
}
void right(int rx,int ry){
	int j,mark=0;
	for(j=0;j<n;j++){
		if(a[j].flag==1){
			continue;
		}else{
			if(a[j].x1==rx&&a[j].y1==ry){
				a[j].flag=1;
				mark=1;
				rr++;
				right(a[j].x2,a[j].y2);
				break;
			}
		}
	}
	if(mark==0){
		Rx=rx;
		Ry=ry;
	}
}
int main(){
	int aa[105];
	int i,lx,ly,rx,ry,max=0;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(i=0;i<n;i++){
		if(a[i].flag==1){
			continue;
		}else{
			ll=0;rr=0;Lx=0;Ly=0;Rx=0;Ry=0; 
			lx=a[i].x1;ly=a[i].y1;
			rx=a[i].x2;ry=a[i].y2;
			a[i].flag=1;
			left(lx,ly);
			right(rx,ry);
			if(max==0){
				max=ll+rr+1;
				LX=Lx;LY=Ly;
				RX=Rx;RY=Ry;
			}else{
				if((ll+rr+1)>max){
					max=ll+rr+1;
					LX=Lx;LY=Ly;
					RX=Rx;RY=Ry;
				}
			}
		}
	}
	if(RX<=LX){
		if(RY<RY){
			LX=RX;LY=RY;
		}
	}
	printf("%d %d %d",max,LX,LY);
	return 0;
}

