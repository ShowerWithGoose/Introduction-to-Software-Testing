#include<stdio.h>
typedef struct mu
{
	int a;
	int b;
}mu;
int main()
{
	mu A[100];
	mu B[100];
	mu C[100000];
	//int x,y;	
	int i,j,k,len1,len2;
	for(i=0;;i++)
	{
	scanf("%d %d",&A[i].a,&A[i].b);
	if(getchar()=='\n') break;
}len1=i+1;
	for(i=0;;i++)
	{
	scanf("%d %d",&B[i].a,&B[i].b);
	if(getchar()=='\n') break;
}len2=i+1;
k=0;
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++)
		{
			C[k].a=A[i].a *B[j].a;
			C[k].b=A[i].b +B[j].b ;
			k++;
		}
	int len3=k;
	int temp1,temp2;
	for(i=0;i<len3;i++)
	{
		for(j=i+1;j<len3;j++)
		{
			if(C[i].b <C[j].b )
			{
				temp1=C[j].b;
				C[j].b=C[i].b ;
				C[i].b =temp1;
				temp2=C[j].a;
				C[j].a =C[i].a;
				C[i].a =temp2;
			}
			if(C[i].b ==C[j].b )
			{
				C[i].a +=C[j].a;
				C[j].a=0;
			}
		}
	}
	for(i=0;i<len3;i++)
	{
		if(C[i].a !=0)
		printf("%d %d ",C[i].a,C[i].b );
		}	
}
