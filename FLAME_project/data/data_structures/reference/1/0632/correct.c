#include<stdio.h>
int N;
int a[15],s[15];
int i;
void qpl(int n);
int main()
{
	scanf("%d",&N);
	qpl(N);
	return 0;
}
void qpl(int n)//还剩n个数没有填 
{
   int i;
   if(n==1)
    {
    	for(i=1;i<=N;i++)
    	 if(a[i]==0) s[N-1+1]=i;
    	for(i=1;i<=N;i++)
    	 printf("%d ",s[i]);
    	printf("\n");
    	return;
	}
   for(i=1;i<=N;i++)
    {
    	if(a[i]==0)
		 {
		 	s[N-n+1] =i;
		 	a[i]=1;
		 	qpl(n-1);
		 	a[i]=0;
		 }
	}
    
   return;
  	
}

