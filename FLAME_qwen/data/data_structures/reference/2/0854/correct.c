#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a) : (b))
#define MIN(a,b) ((a)>(b)?(a) : (b))
int main() {
	char a[10000], b[10000], c[10000], e[10000];
	int d[10000];
	gets(a);
	int i, j = 0, k = 0, m = 1;
	int sum;
	for (i = 0; i < strlen(a); i++) {
		if (a[i] != 32) {
			b[j++] = a[i];
		}
	}
	j = 0;
	for (i = 0; i < strlen(b); i++) {
		if (b[i] == '*' || b[i] == '/' || b[i] == '+' || b[i] == '-' || b[i] == '=') {
			for (k = 0; j < i; k++) {
				c[k] = b[j++];
			}
			j += 1;
			c[k] = '\0';
			d[m] = atoi(c);
			e[m++] = b[i];
		}
	}
	m -= 1;
	i = 1;
	j = 1;
	e[0]='+';
    for(i=1;i<=m;i++)
    {
		if(e[i]=='*'||e[i]=='/')
		{
			(e[i]=='*')?(d[i+1]=d[i]*d[i+1]):(d[i+1]=d[i]/d[i+1]);
			(e[i-1]=='+')?(e[i]='+'):(e[i]='-');
			d[i]=0;
		} 
	}
		sum=d[1];
	for(i=1;i<=m;i++)
	{
		if(e[i]=='+')
		{
			sum+=d[i+1];
		}
		else if(e[i]=='-'){
			sum-=d[i+1];
		}
		else break;
	}
	printf("%d",sum);
}



