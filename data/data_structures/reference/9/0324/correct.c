#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[150][4]={};

int cmp(int *p,int *q){
	return *p-*q;
}

void del(int n,int N){
	int i,j;
	for(i=N;i<n;i++){
		for(j=0;j<4;j++)
			a[i][j]=a[i+1][j];
	}
	
}

int main(){
	int i,j,k;
	int n;
	int cont[150][3]={};
	int b=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++){
		j=i;
		for(k=j+1;k<n;k++){
			if(a[k][0]==a[j][2]&&a[k][1]==a[j][3]){
				cont[b][0]++;
				j=k;
			}	
		}
		if(cont[b][0]!=0){
			cont[b][1]=a[i][0];
			cont[b][2]=a[i][1];
			b++;
		}
	}
	qsort(cont,b,sizeof(cont[0]),cmp);
	printf("%d %d %d",cont[b-1][0]+1,cont[b-1][1],cont[b-1][2]);
}



