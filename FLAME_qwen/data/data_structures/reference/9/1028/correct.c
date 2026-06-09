#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define ll long long
int shouxian(int*,int*,int*,int*,int*,int,int);
int main () {
	int n;
	int x1[100] = {0};
	int x2[100] = {0};
	int y1[100] = {0};
	int y2[100] = {0};
    int max[2]={0,0};
	scanf("%d ",&n);
	int l = 0;
	int k=0;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}

    for(int i=0;i<n;i++){
		shouxian(x1,y1,x2,y2,max,i,n);
	} 
	printf("%d %d %d",max[0],x1[max[1]],y1[max[1]]);
	return 0;
}
int shouxian(int* x1,int* y1,int* x2,int* y2,int* max,int i,int n){
	int flag=0;
	int j;
	int sum=1;
	int l=i;
	do{
		flag=0;
	for(j=0;j<n;j++){
		if(x2[l]==x1[j]){
			if(y2[l]==y1[j]){
				sum++;
				l=j;
				flag++;
				break;
			}
		}
	}
	}while(flag);
    if(sum>max[0]){
		max[0]=sum;
		max[1]=i;
	}
	return 0;
}

