#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
int main(){
	int i=0,j,t,num,max=0,x,y,n,x1[105],y1[105],x2[105],y2[105],z;
	S("%d",&n);
	for(i=0;i<n;i++){
		S("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(x1[i]>x1[j]){
				t=x1[i],x1[i]=x1[j],x1[j]=t;
				t=x2[i],x2[i]=x2[j],x2[j]=t;
				t=y1[i],y1[i]=y1[j],y1[j]=t;
				t=y2[i],y2[i]=y2[j],y2[j]=t;
			}
		}
	}
	for(i=0;i<n;i++){
		num=0;
		z=i;
		for(j=i+1;j<n;j++){
			if(x2[z]==x1[j]&&y2[z]==y1[j]){
				num++;
				z=j;
			}
		}
		if(num>max){
			max=num;
			x=x1[i],y=y1[i];
		}
	}
	P("%d %d %d",max+1,x,y);
	return 0;
}

