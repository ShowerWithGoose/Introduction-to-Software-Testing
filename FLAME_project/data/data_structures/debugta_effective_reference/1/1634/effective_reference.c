#include<stdio.h>
int find_j(int*);
int find_k(int*,int);
int swap(int);
void output(int*);
int a[15],n;
int main ()
{
	int i,j,num,flag;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a[i]=i;
	}
	output(a);
	while(j=find_j(a)){
		num=find_k(a,j);
		flag=a[j];
		a[j]=a[num];
		a[num]=flag;
		swap(j);
		output(a);
	}
	
}

int find_j(int* a){
	int j,flag=0;
 	for(j=n-1;j>0;j--){
		if(a[j]<a[j+1]){
			return j;
			flag=1;
		}
	}
	 if(!flag) return 0;
}

int find_k(int* a,int j){
	int m=9,num,i;
	for(i=j+1;i<=n;i++){
		if(a[i]>a[j]&&a[i]<m){
			num=i;
			m=a[i];
		}
	}
	return num;
}

int swap(int j){
	int i,m,flag;
	for(i=j+1,m=n;i!=m&&i<m;i++,m--){
		flag=a[i];
		a[i]=a[m];
		a[m]=flag;
	}
}

void output(int* a){
	int i;
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
