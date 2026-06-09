#include<stdio.h>
#include<string.h>
void pre(char *, char *);
int main()
{
	char s0[150], s[150];
	int i, j, len;
	gets( s0 );
	pre(s, s0);
	len = strlen( s );
	if( s[0]=='0' ) {
		i = 1;
		while( s[++i]=='0' );
		if( s[i+1]!='\0' )
			printf("%c.%se-%d\n", s[i], s+i+1, i-1);
		else
			printf("%ce-%d\n", s[i], i-1);
	}
	else if( s[0]!='0' && s[1]=='.' ) {
		if( s[2]!='\0' ) printf("%se0\n", s);
		else printf("%ce0\n", s[0]);
	}
	else {
		if( s[len-1]!='.' ) {
			i = 1;
			while( s[++i]!= '.' );
			printf("%c.", s[0]);
			j = 1;
			while( j<len ) {
				if( s[j]=='.') {
					j++;
					continue;
				}
				printf("%c", s[j++]);
			}
			printf("e%d\n", i-1);
		}
		else if( s[len-1]=='.' ) {
			i = 1;
			while( s[++i]!= '.' );
			s[i] = '\0';
			printf("%c.", s[0]);
			printf("%se%d\n", s+1, i-1);
		}
	}	
	return 0;	
}

void pre(char *s1, char *s2)
{
	int i;
	i = strlen( s2 );
	while( s2[--i]=='0') s2[i] = '\0';
	if( s2[0]=='-' ) {
		printf("-");
		strcpy(s1, s2+1);
	}
	else strcpy(s1, s2);
	return ;
}












