#include<stdio.h>
#include<string.h>
int main(){
	int x1[101]={0},y1[101]={0},x2[101]={0},y2[101]={0},m=0,k=1,x[101]={0},y[101]={0},X=0,Y=0,b1,b2,b3,b4,i=0,n=0,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	} 
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			if(x1[i]>x1[j]){
				b1=x1[i];
				x1[i]=x1[j];
				x1[j]=b1;
				b2=y1[i];
				y1[i]=y1[j];
				y1[j]=b2;
				b3=x2[i];
				x2[i]=x2[j];
				x2[j]=b3;
				b4=y2[i];
				y2[i]=y2[j];
				y2[j]=b4;
			}
		}
	for(i=0;i<n;i++){
		x[i]=x1[i];y[i]=y1[i];k=1;
		for(j=i+1;j<n;j++){
			if(x2[i]==x1[j]&&y2[i]==y1[j]){
				x2[i]=x2[j];
				y2[i]=y2[j];
				x2[j]=0;
				x1[i]=0;
				y1[i]=0;
				y2[j]=0;
				k++;
			}
		}
		if(m<k){
			m=k;
			X=x[i];
			Y=y[i];
		}
	}
	printf("%d %d %d",m,X,Y);
	return 0;
}

