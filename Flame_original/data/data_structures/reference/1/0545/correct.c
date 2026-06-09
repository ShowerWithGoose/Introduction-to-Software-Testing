#include<stdio.h>
int a[20],b[20];
int N;
int jiec(int N)//求阶乘N!
{
	int i=1,num=1;
	for(i=1;i<=N;i++)
	{
		num=num*i;
	}
	return num;
}
void print()//输出
{
    int i=0;
    for(i=0;i<N-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[i]);
}
void suanfa()
{
	int i=0,j=0,m=0,k=0;
	int min,mid;
	//第一步，从右边开始找到第一个小于它右边的数
	for(i=N-2;i>=0;i--){
		if(a[i]<a[i+1])//位置为i
			break;
	}
	//然后从pi+1开始，从pi+1~pN的范围里面大于pi的数之间，挑出最小的数，记为pk
	min=a[i+1];
	for(j=i+1;j<N;j++){
        if(a[j]>a[i]){
			if(a[j]<min){
				min=a[j];
			}
		}
	}
	for(j=i+1;j<N;j++){
		if(a[j]==min){
			k=j;
		}
	}
	//调换pi和pk的位置，这时候这个数列就变成了p0p1…pi-1pkpi+1…pk-1pjpk+1…pn-1pn
	mid=a[i];
	a[i]=a[k];
	a[k]=mid;
	//把pi+1…pk-1pipk+1…pn-1pn逆序，得到的p0p1…pi-1pkpnpn-1…pi+1即为当前数列的下一个数列
	for(j=N-1,m=i+1;j>i;j--,m++){
		b[m]=a[j];
	}
	for(j=i+1;j<N;j++){
		a[j]=b[j];
	}
	
	
	
}
int main()
{

	scanf("%d",&N);
	for(int n=0;n<N;n++)
	{
		a[n]=n+1;
	}//N个数存在数组里
    print();
    for(int n=1;n<jiec(N);n++){
        suanfa();
        print();
    }
		
	
	return 0;
}

