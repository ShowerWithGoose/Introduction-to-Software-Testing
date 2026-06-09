#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define M 1000000
#define ll long long
#define ull unsigned long long

ll gcd(ll a, ll b);

ll lcm(ll a, ll b);

int divide(int m, int n);

int cmp(const void *a, const void *b);

int main(){
	char s[105], a[105];
	scanf("%s", s);
	int i = 0, j = 0, e;
	if(s[0] == '0'){
		e = 1;
		for(i = 2; s[i] != '\0' && s[i] == '0'; i++, e++);

		a[j++] = s[i++];
		if(s[i] != '\0') a[j++] = '.';
		
		for(; s[i] != '\0'; a[j++] = s[i++]) ;
		
		a[j++] = 'e';
		a[j++] = '-';	
	}
	
	else{
		e = 0;
		
		a[j++] = s[i++];
		a[j++] = '.';
		
		for(; s[i] != '.' && s[i] != '\0'; e++, a[j++] = s[i++]);
		for(i++; s[i] != '\0'; a[j++] = s[i++]);
		
		a[j++] = 'e';	
	}
		
	a[j++] = '\0';
	printf("%s%d", a, e);
}



ll gcd(ll a, ll b){
	return b? gcd(b, a%b):a;
}

ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}

int cmp(const void *pa, const void *pb){
	int a = *((int *)pa);
	int b = *((int *)pb);
	return a>b? -1:1;
}

int divide(int m, int n){
	if(m < 1||n < 1) return 0;
	if(m == 1||n == 1) return 1;
	if(n < m) return divide(n, n);
	if(n == m)return divide(m - 1, n) + 1;
	return divide(m, n-m) + divide(m-1, n);
}



