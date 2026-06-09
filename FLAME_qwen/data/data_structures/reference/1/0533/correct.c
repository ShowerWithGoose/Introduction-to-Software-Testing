#include <stdio.h>
#include <string.h>
int hash[11] ;

long long p(long long a, long long b) {
	long long res = 1;
	while (b) {
		if ((b & 1) == 1)
			res *= a;
		b >>= 1;
		a *= a;
	}
	return res;
}

long long judge(long long a, int n) {
	memset(hash, 0, sizeof hash);
	while (a) {
		hash[a % 10] = 1;
		a = a / 10;
	}
	for (int i = 1; i <= n; i++) {
		if (hash[i] == 0)
			return 0;
	}
	return 1;
}

int main() {
	long long a = 0;
	long long n = 0;
	scanf("%lld", &n);

	long long start = 0, end = 0;

	for (int i = 1; i <= n; i++) {
		start += ( n - i + 1) * p(10, i - 1);
	}
	for (int i = 1; i <= n; i++) {
		end += i * p(10, i - 1) ;
	}

	for (a = start; a >= start && a <= end; a++) {

		if (judge(a, n)) {

			int i = 1;
			long long b = a;
			while (b) {
				hash[i++] = b % 10;
				b /= 10;
			}

			for (i = n; i >= 1; i--)
				printf("%d ", hash[i]);
			printf("\n");

		}

	}

	return 0;
}



