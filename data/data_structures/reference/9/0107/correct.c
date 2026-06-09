#include <stdio.h>

struct line 
{
	int sx ;
	int sy ;
	int ex ;
	int ey ;
	int cnt ;
	struct line *prev , *next;
}l[101],t;

int main()
{
	int N = 0 ;
	scanf ( "%d" , &N ) ;
	
	int i = 1 ;
	for ( i = 1 ; i <= N ; i++ )
	{
		scanf ( "%d %d %d %d" , &l[i].sx , &l[i].sy , &l[i].ex , &l[i].ey );
	}
	
	for ( i = 1 ; i <= N ; i++ )
	{
		int j = 1 ;
		for ( j = 1 ; j <= N ; j++ )
		{
			if ( j == i ) 
			continue;
			if ( l[i].sx == l[j].ex && l[i].sy == l[j].ey )
			{
				l[i].prev = &l[j];
				l[j].next = &l[i];
				break ;
			}
		}
	}
	
	int max = 1 , mx = 0 , my = 0 ; 
	for ( i = 1 ; i <= N ; i++ )
	{
		t = l[i] ;
		int cnt = 1 ;
		while ( t.prev != NULL)
		{
			t = *t.prev ;
			cnt ++;
		}
		if ( cnt > max)
		{
			max = cnt ; 
			mx = t.sx ;
			my = t.sy ;
		}
	}
	
	printf ("%d %d %d" , max , mx , my ) ;
	return 0;
}

