#include<stdio.h>
int main()
{
	int stack[100] = {0} ;
	int top = -1 , op = 0 ;
	scanf( "%d" , &op ) ;
	while ( op != -1)
	{
		if ( op == -1 )
		break ;
		
		if ( op == 1 )
		{
			if ( top == 99 )
			printf ( "error " ) ;
			else
				{
					scanf( "%d" , &stack[ ++top ] ) ;
				}
		}
		
		if ( op == 0 )
		{
			if ( top == -1)
			printf ( "error " ) ;
			else
			{
				printf ( "%d " , stack[ top-- ] ) ;
			}
		}
		
		scanf( "%d" , &op ) ;
	}
	return 0;
}

