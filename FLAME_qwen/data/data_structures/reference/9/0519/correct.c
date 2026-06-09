#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main (){
	int a[105][4];
	int i,j,k;
	int N;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	//接下来把这些输入的点都变为从左到右横坐标依次增大的顺序
	int temp[4];
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(a[i][0]>a[j][0]){
				for(k=0;k<4;k++)
					temp[k]=a[i][k];
				for(k=0;k<4;k++)
					a[i][k]=a[j][k];
				for(k=0;k<4;k++)
					a[j][k]=temp[k];
			}
		}
	} 
	int ri;
	int res=0;
	int maxres;
	int f1,f2;
	for(i=0;i<N;i++){
		ri=i;
		res=0;//清零 
		for(j=i+1;j<N;j++){
			if(a[ri][2]==a[j][0]&&a[ri][3]==a[j][1]){
				res++;
				ri=j;
			}
		}
		if(res>maxres){
			maxres=res;
			f1=a[i][0];
			f2=a[i][1];
		}
	}
	printf("%d %d %d",maxres+1,f1,f2);
	return 0;
} 

