#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int b[ 20 ];
int a[ 20 ];
void FullArray( int step, int n )
{
	int i;
	if( step > n )
	{
		for( i = 1; i <= n; i++ )
			printf( "%d ", a[ i ] );
		printf("\n");
		return ;
	}
	for( i = 1; i <= n; i++ )
	{
		if( !b[ i ] )
		{
			a[ step ] = i;
			b[ i ] = 1;
			FullArray( step + 1, n );
			b[ i ] = 0;
		}
	}
	return ;
}
int main()
{
	int n;
	scanf("%d", &n );
	FullArray( 1, n );
	return 0;
}




