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

int ans[100], ans[100];
void ha(int x, int n){
	if(x > n){
		int j = 1;
		for(; j <= n; j++) printf("%d ", ans[j]);
		printf("\n");
		 
		return; 
	}
	int i = 1;
	for(; i <= n; i++){
		if(ans[i] == 0){
			ans[x] = i; 
			ans[i] = 1;
			ha(x+1, n);
			ans[i] = 0; 
		} 
	} 
	
}

int main(){
	int n, x = 1;
	scanf("%d", &n);
	
	ha(x, n);
	
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





