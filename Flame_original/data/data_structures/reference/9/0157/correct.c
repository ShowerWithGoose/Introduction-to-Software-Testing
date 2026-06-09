#include<stdio.h>
int main()
{
	int n,i,a[200][4];
	scanf("%d",&n);
	for( i=0 ; i<n ; i++)
	{
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	int b[4];
	int j;
	for( i=0 ; i<n ; i++)
	{
		for( j=i+1 ; j<n ;j++)
		{
			if( a[i][0] > a[j][0] )
			{
				b[0] = a[i][0];
				b[1] = a[i][1];
				b[2] = a[i][2];
				b[3] = a[i][3];
				a[i][0] = a[j][0];
				a[i][1] = a[j][1];
				a[i][2] = a[j][2];
				a[i][3] = a[j][3];
				a[j][0] = b[0];
				a[j][1] = b[1];
				a[j][2] = b[2];
				a[j][3] = b[3];
			}
		}
	}
	int num=1,max=1,x,y,mid;
	for( i=0 ; i<n ; i++){
		mid = i;
		for( j=i+1 ; j<n ; j++)
		{
			if( a[mid][2] == a[j][0] && a[mid][3] == a[j][1] )
			{
				mid = j; 
				num++;
			}
		}
		if( num > max){
			max = num ;
			x = a[i][0];
			y = a[i][1];
		}	
		num = 1;
	}
	printf("%d %d %d",max,x,y);
	return 0;
	
}

















