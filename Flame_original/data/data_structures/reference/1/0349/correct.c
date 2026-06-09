#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int used[ 20 ];
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
		if( !used[ i ] )
		{
			a[ step ] = i;
			used[ i ] = 1;
			FullArray( step + 1, n );
			used[ i ] = 0;
		}
	}
	return ;
}
int main()
{
	int N;
	scanf("%d", &N );
	FullArray( 1, N );
	return 0;
}




