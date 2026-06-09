#include<stdio.h>
#include<stdlib.h>

struct line{
	int flag;
	int toux;
	int touy;
	int weix;
	int weiy;
}; 

struct line a[101];

int main(){
	int n,t=1,t0=1;
	int x,y;
	struct line p;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d %d %d",&a[i].toux ,&a[i].touy ,&a[i].weix ,&a[i].weiy );
		a[i].flag =0;
	}
	for(int i=0;i<n;++i){
		struct line temp;
		for(int j=i+1;j<n;++j){
			if(a[i].toux >=a[j].toux ){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(int i=0;i<n;++i){
		if(a[i].flag ==0){
			t0=1;
			x=a[i].weix ;y=a[i].weiy ;
			for(int j=i+1;j<n;++j){
				if(x==a[j].toux &&y==a[j].touy ){
					a[j].flag =1;
					x=a[j].weix ;y=a[j].weiy ;
					t0++;
				}
			}
			if(t<=t0){
				t=t0;
				p=a[i];
			}
		}
	}
	printf("%d %d %d",t,p.toux ,p.touy );
	return 0;
}

