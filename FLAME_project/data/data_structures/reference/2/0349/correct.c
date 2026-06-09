#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
char str[ 100000 ];
int stack[ 100000 ];
int top = -1;
char op[ 10000 ];
int top2 = -1;
int pri( char c )
{
	if( c == '*' || c == '/' )
		return 1;
	else return 0;
}
int main()
{
	gets( str );
	int i, j;
	int t;
	for( i = 0; str[ i ] != '=' ; i++ )
	{
		if( str[ i ] == ' ' )
			continue;
		if( isdigit( str[ i ] ) )
		{
			j = i;
			t = 0;
			while( isdigit( str[ j ] ) )
			{
				t*=10;
				t += str[ j ] - '0';
				j++;
			}
			stack[ ++top ] = t;
			i = j - 1;
		}
		else if( top2 == -1 || pri( op[ top2 ] ) < pri( str[ i ] ) )
			op[ ++top2 ] = str[ i ];
		else if( pri( op[ top2 ] ) == pri( str[ i ] ) )
		{
			if( op[ top2 ] == '*' )
				stack[ top - 1 ] = stack[ top - 1 ] * stack[ top ];
			else if( op[ top2 ] == '/' )
				stack[ top - 1 ] = stack[ top - 1 ] / stack[ top ];
			else if( op[ top2 ] == '+' )
				stack[ top - 1 ] = stack[ top - 1 ] + stack[ top ];
			else if( op[ top2 ] == '-' )
				stack[ top - 1 ] = stack[ top - 1 ] - stack[ top ];
			top--;
			top2--;
			op[ ++top2 ] = str[ i ];
		}
		else if( pri( op[ top2 ] ) > pri( str[ i ] ) )
		{
			while( top2 >= 0 )
			{
				if( op[ top2 ] == '*' )
					stack[ top - 1 ] *= stack[ top ];
				else if( op[ top2 ] == '/' )
					stack[ top - 1 ] = stack[ top - 1 ] / stack[ top ];
				else if( op[ top2 ] == '+' )
					stack[ top - 1 ] = stack[ top - 1 ] + stack[ top ];
				else if( op[ top2 ] == '-' )
					stack[ top - 1 ] = stack[ top - 1 ] - stack[ top ];
				top--;
				top2--;
			}
			op[ ++top2 ] = str[ i ];
		}
	}
	
	while( top2 >= 0 )
	{
		if( op[ top2 ] == '*' )
			stack[ top - 1 ] *= stack[ top ];
		else if( op[ top2 ] == '/' )
			stack[ top - 1 ] = stack[ top - 1 ] / stack[ top ];
		else if( op[ top2 ] == '+' )
			stack[ top - 1 ] = stack[ top - 1 ] + stack[ top ];
		else if( op[ top2 ] == '-' )
			stack[ top - 1 ] = stack[ top - 1 ] - stack[ top ];
		top--;
		top2--;
	}
	
	printf( "%d", stack[ top ] );
	return 0;
}


