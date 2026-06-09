#include <stdio.h>
int main()
{
	char a, b;
	int k=0, t=1, he=0, shu=0, shu1=0;
	for ( ; ; ){
		if (k == 0) {
			a = getchar();
		}
		else if (k == 1) {
			a = b;
			k = 0;
		}
		if (a >= '0' && a <= '9'){
			shu = shu * 10 + a - '0';
		}
		else if (a == '+'){
			if (t == 1){
				he += shu; shu = 0;
			}
			else if (t == 2){
				he -= shu; shu = 0;
			}
			t = 1;
		}
		else if (a == '-') {
			if (t == 1){
				he += shu; shu = 0;
			}
			else if (t == 2){
				he -= shu; shu = 0;
			}
			t = 2;
		}
		else if (a == '*') {
			while (b = getchar()) {
				if (b >= '0' && b <= '9'){
				shu1 = shu1 * 10 + b - '0';
				}
				else if (b != ' ') {
					k = 1; break;
				}
			}
			shu = shu * shu1;
			shu1 = 0;
		}
		else if (a == '/') {
			while (b = getchar()) {
				if (b >= '0' && b <= '9'){
				shu1 = shu1 * 10 + b - '0';
				}
				else if (b != ' ') {
					k = 1; break;
				}
			}
			shu = shu / shu1;
			shu1 = 0;
		}
		else if (a == '=') {
			if (t == 1){
				he += shu;
			}
			else if (t == 2){
				he -= shu;
			}
			printf ("%d", he);
			return 0;
		}
	}
}



