#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
void fx(int *a,int *b,int d,int n){
    int i;
	if(d==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			a[d]=i;
			fx(a,b,d+1,n);
			b[i]=0;

		}
	}

}
int main(){
    int n;
    int a[100]={0},b[100]={0};
    scanf("%d",&n);
    fx(a,b,1,n);
    return 0;
}

