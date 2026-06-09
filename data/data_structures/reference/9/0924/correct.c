#include<stdio.h>
int main()
{
	int a[1000], n, i, j, k, m=0, s,  temp, flag=0, max=0, b[1000];
	scanf("%d", &n);
	for(i=0;i<4*n;i++)
	{
		scanf("%d", &a[i]);
	} 
 i=2;
 while(i<4*n)
 {
 	j=0;
 	temp=i;
 	while(j<4*n)
 	{
 		if(a[i]==a[j]&&a[i+1]==a[j+1])
 		{
 		i=j+2;	 
		j=-4;
 		k++;
 	}
 	j=j+4;
	 }
	 b[m]=k;
	 m++;
	 k=1;
	 i=temp;

	 i=i+4;
 }
 for(s=0;s<m;s++)
 {
 	if(b[s]>=max)
 	{
 		max=b[s];
 		flag=s;
	 }
 }
 printf("%d %d %d", max, a[4*flag], a[4*flag+1]);
 return 0;
}

