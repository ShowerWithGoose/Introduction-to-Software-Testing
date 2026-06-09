#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
char str[ 100000 ];
void print( char a, char b )
{
	char t;
	for( t = a; t <= b; t++ )
		printf( "%c", t );
}
int main()
{
	scanf( "%s", str );
	int i, j;
	for( i = 0; str[ j ]; i++ )
	{
			j = i;
			if( islower( str[ j ] ) )
			{
				while( str[ j + 1 ] == '-' && islower( str[ j + 2 ] ) && str[ j + 2 ] > str[ j ] )
					j = j + 2;
				if( j > i )
					print( str[ i ], str[ j ] );
				else
					printf( "%c", str[ j ] );
				i = j;
			}
			else if( isupper( str[ j ] ) )
			{
				while( str[ j + 1 ] == '-' && isupper( str[ j + 2 ] ) && str[ j + 2 ] > str[ j ] )
					j = j + 2;
				if( j > i )
					print( str[ i ], str[ j ] );
				else
					printf( "%c", str[ j ] );
				i = j;
			}
			else if( isdigit( str[ j ] ) )
			{
				while( str[ j + 1 ] == '-' && isdigit( str[ j + 2 ] ) && str[ j + 2 ] > str[ j ] )
					j = j + 2;
				if( j > i )
					print( str[ i ], str[ j ] );
				else
					printf( "%c", str[ j ] );
				i = j;
			}
			else if( str[ j ] == '-' )
				printf( "%c", str[ j ] );
	} 
	return 0;
}


