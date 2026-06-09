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
	int i, c;
	for( i = 0; str[ c ]; i++ )
	{
			c = i;
			if( islower( str[ c ] ) )
			{
				while( str[ c + 1 ] == '-' && islower( str[ c + 2 ] ) && str[ c + 2 ] > str[ c ] )
					c = c + 2;
				if( c > i )
					print( str[ i ], str[ c ] );
				else
					printf( "%c", str[ c ] );
				i = c;
			}
			else if( isupper( str[ c ] ) )
			{
				while( str[ c + 1 ] == '-' && isupper( str[ c + 2 ] ) && str[ c + 2 ] > str[ c ] )
					c = c + 2;
				if( c > i )
					print( str[ i ], str[ c ] );
				else
					printf( "%c", str[ c ] );
				i = c;
			}
			else if( isdigit( str[ c ] ) )
			{
				while( str[ c + 1 ] == '-' && isdigit( str[ c + 2 ] ) && str[ c + 2 ] > str[ c ] )
					c = c + 2;
				if( c > i )
					print( str[ i ], str[ c ] );
				else
					printf( "%c", str[ c ] );
				i = c;
			}
			else if( str[ c ] == '-' )
				printf( "%c", str[ c ] );
	} 
	return 0;
}


