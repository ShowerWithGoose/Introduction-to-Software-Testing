#include<stdio.h>
#include<string.h>
#define N 10000
int is_ok(char, char);
int main()
{
	char src[N], dst[2*N];
	int i = 0, j = 0, flag, k;
	gets( src );
	for( i=0; src[i]!='\0'; i++ ) {
		if( src[i]=='-' ) {
			if( is_ok(src[i-1], src[i+1]) ) {
				for( flag=src[i+1]-src[i-1],k=1; k<flag; k++ )
					dst[j++] = src[i-1] + k;
			}
			else dst[j++] = src[i];
		}
		else {
			dst[j++] = src[i];
		}
	}
	dst[j] = '\0';
	puts( dst );
	return 0;
}

int is_ok(char a, char b)
{
	if( '0'<=a && a<='9' && '0'<=b && b<='9' )
		return ( a<b )? 1: 0;
	else if( 'a'<=a && a<='z' && 'a'<=b && b<='z' )
		return ( a<b )? 1: 0;
	else if( 'A'<=a && a<='Z' && 'A'<=b && b<='Z')
		return ( a<b )? 1: 0;
	return 0;
}

