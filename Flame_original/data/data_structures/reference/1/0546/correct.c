#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int cmp (const int *p1,const int *p2);
int a[200],b[1000][1000];
int kk=0;
Swap(int* a, int* b){
	int tem = *a;
	*a = *b;
	*b = tem;
}
void f(int a[], int k, int m){
	if (k>m){
		for (int i = 0; i <= m; i++){
			b[kk][i]=a[i];
		}
		kk++;

	}
	else{
		for (int i = k; i <= m; i++){
			Swap(&a[k], &a[i]);
			f(a, k + 1,m);
			Swap(&a[k], &a[i]);
		}
	}
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<=N-1;i++)
	a[i]=i+1;
	f(a, 0, N-1);
	int sum=1;
	for(int i=1;i<=N;i++)
	sum=sum*i;
	qsort(b,sum,sizeof(b[0]),cmp);
	for(int i=0;i<=sum-1;i++)
	{
		for(int j=0;j<=N-1;j++)
		printf("%d ",b[i][j]);
		printf("\n");
	}
}
int cmp (const int*p1,const int *p2)
{
	if(p1[0]!=p2[0])
		return p1[0]>p2[0]?1:-1;
	else if(p1[0]==p2[0]&&p1[1]!=p2[1])
		return p1[1]>p2[1]?1:-1;
	else if(p1[0]==p2[0]&&p1[1]==p2[1]&&p1[2]!=p2[2])
		return p1[2]>p2[2]?1:-1;
	else if(p1[0]==p2[0]&&p1[1]==p2[1]&&p1[2]==p2[2]&&p1[3]!=p2[3])
		return p1[3]>p2[3]?1:-1;
	else return 0;
	}


