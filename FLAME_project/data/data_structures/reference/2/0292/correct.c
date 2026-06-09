#include <stdio.h>

int main() {
	
	char ch[500] = {}, fh[500] = {}, fh_2[200] = {};
	int shu[500] = {0}, shu_2[200] = {0};
	int ans = 0;
	int j = 0, k = 0, l = 0, m = 0;
	
	gets(ch);
	
	for (int i = 0; ch[i] != '\0'; i++) {
		if (ch[i] != ' ') ch[j++] = ch[i];
	}
	ch[j] = '\0';
	
	for (int i = 0; i < j; i++) {
		if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '=')
			fh[k++] = ch[i];
		else if (ch[i] >= '0' && ch[i] <= '9'){
			int weishu = 1;
			for ( ; ch[i+weishu] >= '0' && ch[i+weishu] <= '9'; weishu ++);
			int num = 0, w = 1, tmp = weishu;
			while (tmp --) {
				num += (w * (ch[i+tmp] - '0'));
				w *= 10;
			}
			shu[l++] = num;
			i += weishu - 1;
		}
	}	
	
	for (int i = 0; i <= k; i++) {
		switch (fh[i]) {
			case '*':
				shu[i+1] *= shu[i];	break;
			case '/':
				shu[i+1] = shu[i] / shu[i+1];	break;
			case '+':
			case '-':
			case '=':
				fh_2[m] = fh[i];
				shu_2[m] = shu[i];
				m ++; 
				break;
			default:
				break;
		}
	}
	
	ans += shu_2[0];
	for (int i = 0; i <= m ; i++) {
		if (fh_2[i] == '+')
			ans += shu_2[i+1];
		else 
			ans -= shu_2[i+1];
	}
	
	printf("%d", ans);
	return 0;
}



