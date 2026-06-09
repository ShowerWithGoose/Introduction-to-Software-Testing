#include<stdio.h>

int main()
{
	int a[110]={0},m,n,k=0;
	while(scanf("%d",&m))
	{
		if(m==-1)return 0;
		if(m!=0)scanf("%d",&n);
		if(m==0)
		{
			if(k!=0){printf("%d ",a[k]);k--;}
			else printf("error ");
		}
		else{
			if(k!=100){k++;a[k]=n;}
			else {printf("error ");}
		}
	}
	return 0;
} 

