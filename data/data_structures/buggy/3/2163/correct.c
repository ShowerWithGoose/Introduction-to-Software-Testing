#include <stdio.h>
#include <string.h>

int main() {
	char shuzi[1001];
	char shuzi2[1001];
	scanf("%s", shuzi);
	int len = strlen(shuzi);
	int k = 0;


	if (shuzi[0] == '0' && (shuzi[len - 2] == '.')) {
		int sum = len - 2;
		printf("%ce-%d", shuzi[len - 1], sum);
	}

	else if (shuzi[0] == '0' && shuzi[len - 2] == '0' && shuzi[len - 2] != '.') {
		int sum = len - 2;
		printf("%ce-%d", shuzi[len - 1], sum);
	}

	else if (shuzi[0] == '0' && shuzi[len - 2] != '0') {
		int sum = 0;
		for (int i = 0; i < len; i++) {
			if (shuzi[i] != '0' && shuzi[i] != '.') {
				break;
			}
			sum++;
		}

		for (int i = 0; i < len; i++) {
			if (shuzi[i] != '0') {
				break;
			}
			sum++;
		}
		sum = sum - 2;
		int xin = 2;
		shuzi2[0] = shuzi[sum + 1];
		shuzi2[1] = '.';
		for (int i = sum + 2; i < len; i++) {
			shuzi2[xin] = shuzi[i];
			xin++;
		}
		for (int i = 0; i < xin; i++) {
			printf("%c", shuzi2[i]);
		}
		printf("e-%d", sum);

	}

	else if (shuzi[0] != '0' && shuzi[1] == '.') {
		int sum = len - 2;

		printf("%se0", shuzi);
	}


	else {
		for (int i = 0; i < len; i++) {
			if (shuzi[i] == '.') {
				k = i;
				shuzi2[0] = shuzi[0];
				shuzi2[1] = '.';
				for (int i = 2; i <= k; i++) {
					shuzi2[i] = shuzi[i - 1];
				}
				for (int i = k + 1; i < len; i++) {
					shuzi2[i] = shuzi[i];
				}
			}
		}

		printf("%se%d", shuzi2, k - 1);
	}

	return 0;
}
















