#include<stdio.h>
int n;
int x[20]={0};//用来排序。 
int y[20]={0};//用来记录是否用过该数字。 
void quanpailie(int a);

int main()
{
	scanf("%d",&n);
	quanpailie(1);
	return 0;
}

void quanpailie(int a){
	int i=0;
	
	if(a==n+1)//到最终排序了。 
	{
		for(i=1;i<n;i++)
			printf("%d ",x[i]);
		printf("%d\n",x[i]);
		return ;
	}
	
	for(i=1;i<=n;i++)//每次进入时都会全部过一遍，非常合理方便。 
		if(y[i]==0){
			x[a]=i;
			y[i]=1;//标记他用过了。
			quanpailie(a+1);
			x[a]=0;
			y[i]=0;//恢复数字与未标记。
		}
}

