#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


int num[10];	
int seat[10];
int used[10];

void sort(int n, int m);
void sit(int m);
void stand(int m);

int main(){
	int n;
	scanf("%d",&n);
	sort(n,-1);
//	printf("finish\n");
	return 0;
} 

void sort(int n, int m){
	int i,j;
	m++;
	for(i=0;i<n;i++){
		if(seat[i]==0){
			num[m]=i;
			sit(i);
			if(m==n-1){
				for(j=0;j<n;j++){
					printf("%d ",num[j]+1);
				}
				printf("\n");
			}
			sort(n,m);
			stand(i);
		}
	}
	return;
}

void sit(int m){
	seat[m]=1;
	return;
}

void stand(int m){
	seat[m]=0;
	return;
}



