#include<stdio.h>
struct line{
		int qx;
		int qy;
		int zx;
		int zy;
	};
struct line a[600],b[600];
int t,n,max=0,c[600];
int dps(int x,int length){
	c[x]=1;
	int i,flag=0;
	t=0;
	for(i=x+1;i<=n;i++) if(a[x].zx==a[i].qx&&a[x].zy==a[i].qy) {
	flag=1;
	dps(i,length+1);
	}
	if (flag==0) if(max<length) {
		max=length;
		t=1;
	}
	if(t==1) b[length]=a[x];
}
int main(){
	int i,j;
	for(i=1;i<=500;i++) c[i]=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d %d %d %d",&a[i].qx,&a[i].qy,&a[i].zx,&a[i].zy);
	for(i=1;i<=n;i++) 
		for(j=1;j<=n-i;j++)
		if(a[j].qx>a[j+1].qx){
			a[0]=a[j];
			a[j]=a[j+1];
			a[j+1]=a[0];
		} 
		
	for(i=1;i<=n;i++) if(c[i]==0)dps(i,1);
	printf("%d %d %d",max,b[1].qx,b[1].qy);
	
}

