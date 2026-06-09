#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main(){
	int a,b,n,cnt,k,max=0;
    int x1[150],x2[150],y1[150],y2[150];
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	int hold1,hold2,hold3,hold4;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(x1[j]>x1[j+1]){
				hold1=x1[j];
				x1[j]=x1[j+1];
				x1[j+1]=hold1;
				hold2=y1[j];
				y1[j]=y1[j+1];
				y1[j+1]=hold2;
				hold3=x2[j];
				x2[j]=x2[j+1];
				x2[j+1]=hold3;
				hold4=y2[j];
				y2[j]=y2[j+1];
				y2[j+1]=hold4;
			}
		}
	}
	for(i=0;i<n;i++){
		k=i;
		cnt=1;
		for(j=i+1;j<n;j++){
			if(x1[j]==x2[k]&&y1[j]==y2[k]){
				cnt++;
				k=j;
			}
		}
		if(cnt>max){
			max=cnt;
			a=x1[i];
			b=y1[i];
		}
		
		
	}
	printf("%d %d %d",max,a,b);
	return 0;
}



