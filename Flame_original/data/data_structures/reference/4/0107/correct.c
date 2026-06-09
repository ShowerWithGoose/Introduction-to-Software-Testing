#include <stdio.h>
#include <string.h>

int main ()
{
	FILE *in = fopen ( "article.txt" , "r" ) ;
	char c , word[100][100] ;
	int n = 0 , i = 0 ;
	while ( ( c = fgetc ( in ) ) != EOF )
	{
		if(c>='A'&&c<='z')
		{
			if ( c>='A'&&c<='Z')
			c += 32 ;
			word[n][i++] = c ;
		}
		else if ( i != 0 )
		{
			word[n][i] = '\0' ;	
			i = 0 ;
			n++ ;
		}
	}//Ω·Œ≤µ•¥ £∫word[n-1] 
	
	int j = 0 , k = 0 ;
	for ( j = 0 ; j <= n ; j++ )
	{
		for ( k = 0 ; k < n - 1 ; k++ )
		{
			int res = strcmp ( word[k] , word [k+1] ) ;
			if ( res > 0 )//Ωªªª 
			{
				char temp[100] ;
				strcpy ( temp , word[k] ) ;
				strcpy ( word[k] , word[k+1] ) ;
				strcpy ( word[k+1] , temp ) ;
			}
		}
	}//≈≈–Ú 
	
	k = 0 ;
	int cnt[100] = {0} ;
	for ( j = 0 ; j < n - 1 ; j++ )
	{
		int res = strcmp ( word[j] , word [j+1] ) ;
		if ( res == 0 )
		{
			cnt[k]++;
		}
		else
		k++;
	}
	
	k = 0 ;
	for ( j = 0 ; j < n ;)
	{
		printf ( "%s %d\n" , word[j] , cnt[k]+1 );
		j += cnt [k] + 1 ;
		k++ ;
	}
	return 0;
 } 



