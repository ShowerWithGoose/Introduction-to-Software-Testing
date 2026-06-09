#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 10000
void no_space(char *, const char *);
int main()
{
	char s0[N], s[N];
	int num[N];
	char op[N];
	int i = 1, j = 1, k, t;
	int ans = 0, idx = 1, len;
	gets( s0 );
	no_space(s, s0);
	len = strlen( s );
	//printf("%s\n", s);
	for( k=0; k<len-1; k++ ) {
		
		for( t=0; '0'<=s[k]&&s[k]<='9'; k++ ) {
			t = 10*t + s[k] - '0';
			num[i] = t;
			//printf("%d\n", num[i]);
		}
		i++;
		op[j++] = s[k];
		//printf("rnm\n");
	}//
	ans = num[1];
	//for( t=1; t<i; t++) printf("%d ",num[t]);
	//putchar('\n');
	for( k=1; k<j; k++ ) {
		if( op[k]=='+' ) {
			ans += num[k+1];
			idx = 1;
		}
		else if( op[k]=='-' ) {
			ans -= num[k+1];
			idx = 1;
		}//
		else if( op[k]=='*' ) {
			if( k==1 )	{
				ans -= num[k];
				ans += num[k] * num[k+1]; 
				num[k+1] = num[k] * num[k+1];
			}
			else{
				if( op[k-idx]=='+' ) {
					ans -= num[k];
					ans += num[k] * num[k+1]; 
					num[k+1] = num[k] * num[k+1];
					
				}
				else if( op[k-idx]=='-' ) {
					ans += num[k];
					ans -= num[k] * num[k+1];
					num[k+1] = num[k] * num[k+1];
				}
				else {
					ans *= num[k+1];
				}
				idx++;
			}
		}//
		else if( op[k]=='/' ) {
			if( k==1 )	{
				ans -= num[k];
					ans += num[k] / num[k+1]; 
					num[k+1] = num[k] / num[k+1];
			}
			else{
				if( op[k-idx]=='+' ) {
					ans -= num[k];
					ans += num[k] / num[k+1]; 
					num[k+1] = num[k] / num[k+1];
					
				}
				else if( op[k-idx]=='-' ) {
					ans += num[k];
					ans -= num[k] / num[k+1];
					num[k+1] = num[k] / num[k+1];
				}
				else {
					ans /= num[k+1];
				}
				idx++;
			}
		}
	} 
	printf("%d\n", ans);
	return 0;
}

void no_space(char *s, const char *t)
{
	int i, j = 0;
	for( i=0; t[i]!='\0'; i++) {
		if( t[i]!=' ' ) {
			s[j++] = t[i];
		}
	}
	s[j] = '\0';
	return ;
}

