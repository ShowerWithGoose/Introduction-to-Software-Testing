#include<stdio.h>
#include<string.h>
typedef struct node{
	char arr[10];
}Store;
int N=1,cnt=0;
int cmp(const void *a,const void *b);
void fun(int k,int n,char a[],Store s[]);
int main(){
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	N*=i;
	Store s[N];
	char a[]={'1','2','3','4','5','6','7','8','9'};
	fun(0,n,a,s);//È«ÅÅÁÐ
	qsort(s,cnt,sizeof(s[0]),cmp);
	for(i=0;i<N;i++){
		for(j=0;j<n;j++){
			printf("%c ",s[i].arr[j]);
		}
		printf("\n");
	}
	return 0;
}
void fun(int k,int n,char a[],Store s[])
{
	int i;
	char temp;
	if(k==n-1)
	{

		for(i=0;i<n;i++)
			s[cnt].arr[i]=a[i];
		cnt++;
		 //printf("%d ",a[i]);
		 //printf("\n");
	}
	else
	{
		for(i=k;i<n;i++)
		{
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
			fun(k+1,n,a,s);

			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
		}
	}
}
int cmp(const void *a,const void *b)
{
	return strcmp((*(struct node*)a).arr,(*(struct node*)b).arr);
}

