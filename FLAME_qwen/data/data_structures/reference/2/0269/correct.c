#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[105], ss[105];
int step;
int getNum()
{
	int num = 0;
	while( isdigit( s[step] ) )
	{
		num = num * 10 + (s[step++] - '0');
	}
	return num;
}

int cal( int sign )
{
	int num = 0, tmp = 0, flag = 0;
	num = getNum();

	while( 1 )
	{
		if(s[step] == '+')
		{
			step++;
			return sign * num + cal(1);
		}
		else if(s[step] == '-')
		{
			step++;
			return sign * num + cal(-1);
		}
		else if(s[step] == '=')
		{
			return sign * num;
		}

		else if( s[step] == '*' )
		{
			step++;
			flag = 1;
		}
		else if( s[step] == '/' )
		{
			step++;
			flag = 0;
		}
		
		else if( isdigit( s[step] ) )
		{
			tmp = getNum();
			if( flag == 1 ) num *= tmp;
			else if( flag == 0 ) num /= tmp;
		}
	}
}
int main()
{
	int i, j;
	gets( ss );
	int len = strlen( ss );
	for( i = 0, j = 0; i < len; i++ )
	{
		if( ss[i] != ' ' )
		{
			s[j++] = ss[i];
		}
	}
	s[j] = '\0';
	
	printf( "%d", cal( 1 ) );
	return 0;
}



