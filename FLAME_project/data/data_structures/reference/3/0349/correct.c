#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
char in[ 10000 ];
int main()
{
	scanf("%s", in );
	int i;
	int cnt = 0;
	int r;
	if( in[ 0 ] != '0' )
	{
		printf("%c", in[0] );
		printf(".");
		i = 1;
		for( i = 1 ; in[ i ]; i++ )
		{
			if( in[i] != '.' )
			{
				printf("%c", in[ i ] );
				cnt++;
			}
			else
				r = cnt;
		}
		printf("e%d", r );
	}
	else
	{
		cnt = -1;
		for( i = 2; in[ i ] == '0'; i++ )
		{
			cnt--;
		}
		printf( "%c", in[ i ] );
		if( in[ ++i ] )
			printf(".");
		for( ; in[ i ]; i++ )
			printf("%c", in[ i ] );
		printf("e%d", cnt );
	}
	return 0;
}


