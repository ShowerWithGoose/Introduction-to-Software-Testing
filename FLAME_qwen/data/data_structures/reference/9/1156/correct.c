#include<stdio.h>
int i,j,k,t;
int pos,max;
int n;
int x1[10000],y1[10000],x2[10000],y2[10000],sy[10000];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x1[i]);
		scanf("%d",&y1[i]);
		scanf("%d",&x2[i]);
		scanf("%d",&y2[i]);
	} 
	for(i=1;i<=n-1;i++){
		for(j=i+1;j<=n;j++){
			if(x1[i]==x2[j]&&y1[i]==y2[j]){
				sy[j]=i;
			}
			if(x1[j]==x2[i]&&y1[j]==y2[i]){
				sy[i]=j;
			}
		}
	}
	
	max=0,pos=0;
	for(i=1;i<=n;i++){
		k=1;
		t=i;
		while(sy[t]!=0){
			k++;
			t=sy[t];
		}
		if(k>max){
			max=k;
			pos=i;
		}
	}
	printf("%d %d %d",max,x1[pos],y1[pos]);
	return 0;
}

