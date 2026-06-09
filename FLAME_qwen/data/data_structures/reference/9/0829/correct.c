#include<stdio.h>
int main(){
	int n,i,j,k,l=1,a,b;
	int x1[100],y1[100],x2[100],y2[100],c[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(x1[j]>x1[j+1]){
			k=x1[j];
			x1[j]=x1[j+1];
			x1[j+1]=k;
			k=x2[j];
			x2[j]=x2[j+1];
			x2[j+1]=k; 
			k=y1[j];
			y1[j]=y1[j+1];
			y1[j+1]=k; 
			k=y2[j];
			y2[j]=y2[j+1];
			y2[j+1]=k;  
		}}
	}
	for(i=0;i<n;i++){
		a=x2[i],b=y2[i];
		for(j=i;j<n;j++){
			if(a==x1[j]&&b==y1[j]){
				l+=1;
				a=x2[j];
				b=y2[j];
			}
		}
		c[i]=l;
		l=1;
	}
	for(i=0;i<n;i++){
		if(c[i]>l)l=c[i];
	}
	for(j=0;j<n;j++){
		if(c[j]==l){
			printf("%d %d %d ",l,x1[j],y1[j]);
		}
	} 
	return 0;
} 

