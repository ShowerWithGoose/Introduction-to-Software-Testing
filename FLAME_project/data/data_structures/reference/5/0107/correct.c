#include <stdio.h>
#include <stdlib.h>

typedef struct _node 
{
	int a ;
	int n ;
	struct _node *next ;
}node;

node *head = NULL , *p , *tail = NULL ;

struct putin
{
	int a;
	int n;
}x1[100] , x2[100] ;

void insert ( int resn , int resa )
{
	node * temp = NULL ;
	for ( temp = head ; temp != tail ; temp = temp->next)
	{
		if ( resn <= temp -> n && resn > temp ->next ->n)
		break;
	}
	
	if ( temp->n == resn )
	{
		temp->a += resa ;
		return ;
	}
	
	if ( temp == tail && resn < tail->n)
	{
		tail ->next = p ;
		p->n = resn ;
		p->a = resa ;
		tail = p ;
		return ;
	}
	
	p->a = resa ;
	p->n = resn ;
	p->next = temp ->next ;
	temp -> next = p;
}

int main()
{
	char c = '\0' ;
	
	int i = 0 ;
	while ( c != '\n' )
	{
		scanf ( "%d %d" , &x1[i].a , &x1[i].n );
		i++ ;
		c = getchar() ;
	}
	
	c = '\0' ;
	int j = 0 ;
	while ( c != '\n' )
	{
		scanf ( "%d %d" , &x2[j].a , &x2[j].n );
		j++ ;
		c = getchar() ;
	}
	
	int m = 0 , k = 0 ;
	for ( m = 0 ; m < i ; m++ )
	{
		for ( k = 0 ; k < j ; k++ )
		{
			int resn = x1[m].n + x2[k].n ;
			int resa = x1[m].a * x2[k].a ;
			
			p = (node *) malloc ( sizeof(node) );
			if ( head ==NULL )
			{
				p->a = resa ;
				p->n = resn ;
				head = p ;
				tail = p ;
			}
			
			else 
			{
			insert( resn , resa );
			}
		}
	}
	
	node *temp =NULL ;
	for ( temp = head ; temp != tail ; temp = temp->next)
	{
		printf ("%d %d " , temp->a , temp -> n);
	}
	printf ("%d %d " , temp->a , temp -> n);
	return 0;
}

