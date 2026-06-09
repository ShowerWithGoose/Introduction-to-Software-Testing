#include<stdio.h>

int* reverse(int p[110][4],int n,int temp[4]);

int main(){
	int n,i,j,tem=0,longth=1,longed=1,first_x,first_y;
	int p[110][4],temp[4];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
	}
	
	reverse(p,n,temp);
//	for(i=0;i<n;i++){
//		printf("%d %d %d %d\n",p[i][0],p[i][1],p[i][2],p[i][3]);
//	}
	for(i=0;i<n;i++){
		tem=i;
		longth=1;
		for(j=i;j<n;j++){
			if(p[j][2]==p[tem][0]){
				if(p[j][3]==p[tem][1]){
					longth++;
					tem=j;	
				}
			}
			if(longth>longed){
							longed=longth;
							first_x=p[j][0];
							first_y=p[j][1];
//							printf("%d\n",longed);
				}
		}
		

	}
	printf("%d %d %d",longed,first_x,first_y);
	return 0;
}

int* reverse(int p[110][4],int n,int temp[4]){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(p[i][0]>p[j][0]){
				for(k=0;k<4;k++){
					temp[k]=p[i][k];
					p[i][k]=p[j][k];
					p[j][k]=temp[k];
				}
			}
		}
	}
	return p;
}


