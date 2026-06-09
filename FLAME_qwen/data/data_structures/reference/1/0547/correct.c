#include<stdio.h>
int a[20];

void puta(int high){
	int i=1;
	while(i<=high){
		printf("%d ",a[i]);
		i++;
	}
	printf("\n");
}

void change(int l,int h){
	int tmp=a[l];
	a[l]=a[h];
	a[h]=tmp;
}

void geta(int l,int r){
	int tmp=a[r],i;
	for(i=r;i>l;i--){
		a[i]=a[i-1];
	}
	a[l]=tmp;
}

void restorea(int l,int r){
	int tmp=a[l],i;
	for(i=l;i<r;i++){
		a[i]=a[i+1];
	}
	a[r]=tmp;
}

void quanpailie(int low,int high){
	if(low+1==high){
		puta(high);
		change(low,high);
		puta(high);
		change(low,high);
		return;
	}
	int i=low;
	while(i<=high){
		geta(low,i);
		quanpailie(low+1,high);
		restorea(low,i);
		i++;
	}
}


int main() {
	int N,i;
	scanf("%d",&N);
	for(i=1;i<=10;i++){
		a[i]=i;
	}
	if(N==1) printf("1");
	else quanpailie(1,N); 
	return 0;
}



