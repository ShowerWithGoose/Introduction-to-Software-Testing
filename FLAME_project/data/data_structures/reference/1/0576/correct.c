#include<stdio.h>
int find_j(int*);
int find_k(int*,int);
int swap(int);
void output(int*);
int a[15],num;
int main ()
{
	int i,j,k,flag;
	scanf("%d",&num);
	for(i=1;i<=num;i++){
		a[i]=i;
	}
	output(a);
	while(j=find_j(a)){
		k=find_k(a,j);
		flag=a[j];
		a[j]=a[k];
		a[k]=flag;
		swap(j);
		output(a);
	}
	
}

int find_j(int* a){
	int j,flag=0;
 	for(j=num-1;j>0;j--){
		if(a[j]<a[j+1]){
			return j;
			flag=1;
		}
	}
	 if(!flag) return 0;
}

int find_k(int* a,int j){
	int maxmin=9,k,i;
	for(i=j+1;i<=num;i++){
		if(a[i]>a[j]&&a[i]<maxmin){
			k=i;
			maxmin=a[i];
		}
	}
	return k;
}

int swap(int j){
	int i,m,flag;
	for(i=j+1,m=num;i!=m&&i<m;i++,m--){
		flag=a[i];
		a[i]=a[m];
		a[m]=flag;
	}
}

void output(int* a){
	int i;
	for(i=1;i<=num;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
