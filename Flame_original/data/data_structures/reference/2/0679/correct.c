#include <stdio.h>
#include <string.h>
char ss[105], fh[105];
int shu[105], flag = 0, fhFlag = 0, t = 1, j = 0;
void dushu();

int main() {
	fgets(ss, 105, stdin);
	for (j = 0; ss[j] != '='; j++) {
		if (ss[j] <= '9' && ss[j] >= '0') {
			dushu();
		} else if (ss[j] == ' ')
			continue;
		else {
			fh[fhFlag] = ss[j];
			fhFlag++;
		}
	}
	if (fhFlag == 0) {
		printf("%d", shu[0]);
		return 0;
	}
	for (int i = 0; fh[i] != '\0'; i++) {
		if (fh[i] == '*') {
			shu[i + 1] *= shu[i];
			shu[i] = 0;
		} else if (fh[i] == '/') {
			shu[i + 1] = shu[i] / shu[i + 1];
			shu[i] = 0;
		}
	}
	int Flag = 0, sum = 0;
	for (int i = 0; fh[i] != '\0'; i++) {
		while (shu[i] == 0) {
			i++;
			continue;
		}
		if (Flag == 0) {
			sum = shu[i];
			Flag = 1;
		}
		if (fh[i] == '+') {
			while (shu[i + 1] == 0) {
				i++;
				continue;
			}
			sum += shu[i + 1];
		} else if (fh[i] == '-') {
			while (shu[i + 1] == 0) {
				i++;
				continue;
			}
			sum -= shu[i + 1];
		}
	}
	printf("%d", sum);
	return 0;
}

void dushu() {
	shu[flag] = ss[j] - '0';
	while (ss[j + 1] <= '9' && ss[j + 1] >= '0') {
		shu[flag] = shu[flag] * 10 + ss[j + 1] - '0';
		j++;
	}
	flag++;
	return;
}
