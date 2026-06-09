#include<stdio.h>
int hash[]={1,2,3,4,5,6,7,8,9,10,11};
int a[15];
int N;
void fullperm(int n,int begin)
{
	int i,j,k;
	if(n==1)
	{
		printf("1\n");
		return ;
	}
	if(n==2) 
	{
		j=0;
		while(hash[j++]==0);
		a[N-2]=hash[j-1];
	//错！！	while(hash[j++]!=0) a[N-1]=hash[j-1];printf("j=%d\n",j);//
		while(hash[j++]==0);
		a[N-1]=hash[j-1];
		for(j=0;j<N;j++) printf("%d ",a[j]);
		putchar(10);
		//swap(&a[N-2],&a[N-1]);       为什么函数没有交换这两个数 
		k=a[N-2]; a[N-2]=a[N-1]; a[N-1]=k;
		//for(j=0;j<N;j++) printf("hash[%d]=%d  ",j,hash[j]);//
		
		for(j=0;j<N;j++) printf("%d ",a[j]);
		putchar(10);
	//	for(j=0;j<N;j++) hash[j]=j+1;  //更新数组    不能完全更新怎么办？？/ 
		return ;
	}
	else
	{
		for(i=0;i<N;i++)
		{
			if(hash[i]==0) continue;
			a[begin]=hash[i];
		//	printf("begin=%d a[%d]=%d  hash[%d]=%d\n",begin,begin,a[begin],i,hash[i]);
			hash[i]=0;
			fullperm(n-1,begin+1);
			hash[i]=i+1;      //这是更新？？ 
		}
	}
}
/*void swap(int *a,int *b)
{
	int *t;
	t=a;
	a=b;
	b=t;
}*/
int main()
{
	
	scanf("%d",&N);
	fullperm(N,0);
	return 0;
}

