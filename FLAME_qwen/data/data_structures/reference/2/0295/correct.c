#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
long long dg[1000];
long long ret[1000];
int opt[1000];
int main() {
	char temp[1000];
	char sen[1000];
	gets(sen);
	int len = strlen(sen);
	int i, cnt = 0;
	for (i = 0; i < len; i++) {
		/*if (sen[i] == ' ')
			continue;*/
		if (isdigit(sen[i])) {
			memset(temp, 0, sizeof(temp));
			int j, k = 0;
			for (j = i; j < len; j++) {
				if (sen[j] == ' ')
					continue;
				if (isdigit(sen[j])) {
					temp[k] = sen[j];
					k++;
				} else {
					i = j;
					break;
				}

			}
			//puts(temp);
			dg[cnt] = atoi(temp);
			cnt++;
		}
	}
	if (sen[0] == '-')
		opt[0] = -1;

	else
		opt[0] = 1;
	int cnt_o = 1;
	ret[0] = dg[0];
	int m = 1;
	for (i = 1; i < len; i++) {
		if (sen[i] == '+') {
			opt[cnt_o] = 1;
			ret[cnt_o ] = dg[m];
			m++;
			cnt_o++;
		} else if (sen[i] == '-') {
			opt[cnt_o] = -1;
			ret[cnt_o ] = dg[m];
			m++;
			cnt_o++;
		} else if (sen[i] == '*') {
			ret[cnt_o-1 ] *= dg[m];
			m++;
		} else if (sen[i] == '/') {
			ret[cnt_o-1 ] /= dg[m];
			m++;
		}
	}

	long long res=0;

	for (i = 0; i < cnt_o; i++) {
		//printf("%d*%lld\n",opt[i],ret[i]);
		res+=opt[i]*ret[i];
	}
	printf("%lld",res);
	return 0;
}



