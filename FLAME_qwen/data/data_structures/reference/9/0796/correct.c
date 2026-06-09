#include<stdio.h>
int dot[444];
int X1[100];
int X2[100];
int sum[100];
int N;
int check(int i,int j){
	if(dot[4*i+2]==dot[4*j]&&dot[4*i+3]==dot[4*j+1])
	return 1;
	else return 0;
}
void Sort(void){
	int i=0,j=0;
	for(i=0;i<N;i++){
		for(j=0;j<N-1-i;j++){
			if(dot[4*j]>=dot[4*j+4]){
				int a;
				a=dot[4*j];dot[4*j]=dot[4*j+4];dot[4*j+4]=a;
				a=dot[4*j+1];dot[4*j+1]=dot[4*j+5];dot[4*j+5]=a;
				a=dot[4*j+2];dot[4*j+2]=dot[4*j+6];dot[4*j+6]=a;
				a=dot[4*j+3];dot[4*j+3]=dot[4*j+7];dot[4*j+7]=a;
			}
		}
	}	
}
int main(){
	scanf("%d",&N);
	int i=0;
	for(i;i<4*N;i++) scanf("%d",&dot[i]); 
	Sort();
	int j=0,k=0,a=0,x3;
	for(j=0;j<N;j++){
		a=j;
		for(k=j;k<N;k++){
			if(check(a,k)){
				X1[j]=dot[4*j];
				X2[j]=dot[4*j+1];
				sum[j]++;
				a=k;
			}
		}
	}
	int max=0;
	for(i=0;i<N;i++){
		max=sum[i]>sum[max]?i:max;
	}
	printf("%d %d %d",sum[max]+1,X1[max],X2[max]);
	return 0;
}

