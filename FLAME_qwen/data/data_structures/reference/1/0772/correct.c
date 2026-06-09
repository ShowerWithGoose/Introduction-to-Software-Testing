#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//qsort顺序为数组名，元素数量，元素大小，cmp 
void swap(int *a,int *b){
	int m;
	m=*a;
	*a=*b;
	*b=m;
}

void sw(int a[],int s1,int s2){
	int *p;
	p=a;
	swap(p+s1-1,p+s2-1);
}

void copyint(int *a,int *a1,int n){
	int i;
	for(i=0;i<n;i++)
	a1[i]=a[i];
}

void circle(int n,int now,int a[]){
	int i,a1[20];
	if(now<n){
		copyint(a,a1,n);
		for(i=now+1;i<=n;i++){
			circle(n,now+1,a1);
			sw(a1,now,i);
		}
		circle(n,now+1,a1);
	}
	else if(now==n){
		for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int a[20],i;
	for(i=0;i<n;i++)
	a[i]=i+1;
	circle(n,1,a);
    return 0;
} 



