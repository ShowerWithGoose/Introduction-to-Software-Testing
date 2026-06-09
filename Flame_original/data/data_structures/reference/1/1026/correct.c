#include <stdio.h>
#include <math.h>
#include <string.h>
int N;
int i,j;
int num[11];
int o[10];

int fa(){
	num[0]=1;
	int i;
	for(i=1;i<10;i++){
		num[i]=i*num[i-1];
	}
} 

void print(){
	int i=0;
	for(i=0;i<N-1;i++){
		printf("%d ",o[i]);
	} 
	printf("%d\n",o[i]);
}

void find(){
	for(i=N-2;i<N;i--){
		if(o[i]<o[i+1])
			break;
	}
	int k1=i;
	int temp=i+1;
	for(i=k1+1;i<N;i++){
		if(o[i]>o[k1]&&o[i]<o[temp])
			temp=i;
	}
	int t;
	t=o[k1];
	o[k1]=o[temp];
	o[temp]=t;
	for(j=k1+1,i=N-1;i>j;i--,j++){
		t=o[i];
		o[i]=o[j];
		o[j]=t;
	}	
}

int main()
{
	fa();
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++){
		o[i]=i+1;
	}
	print();
	for(i=1;i<num[N];i++){
		find();
		print();
	}
	return 0;
}	

