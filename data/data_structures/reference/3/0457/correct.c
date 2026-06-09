#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char str[1024];
	char base[1024];
	int exp;
	int exp_pos;
	int head_zero_nums;
	int tail_zero_nums;
	int i, j;
	int flag;
	
	scanf("%s", str);
	if (str[0] == '0' && str[1] == '\0') {puts("0e0"); return 0;}
	strcpy(base, str);
	exp_pos = -1;
	for (i = 0, j = 0; base[i] != '\0'; i++) if(base[i] != '.') base[j++] = base[i]; else exp_pos = i;
	base[j] = '\0';
	head_zero_nums = 0;
	for (i = 0, j = 0, flag = 0; base[i] != '\0'; i++) if(base[i] != '0' || flag) {base[j++] = base[i], flag = 1;} else head_zero_nums++;
	base[j] = '\0';
	tail_zero_nums = 0;
	for (i = strlen(base) - 1; i >= 0&& base[i] == '0'; i--) if (base[i] == '0') base[i] = '\0', tail_zero_nums++;
	putchar(base[0]);
	if (base[1] != '\0')
	{
		putchar('.');
		for (i = 1; base[i] != '\0'; i++) putchar(base[i]);
	}
	putchar('e');
	if (exp_pos != -1) exp = exp_pos - head_zero_nums - 1;
	else exp = strlen(str) - 1;
	printf("%d", exp);
	return 0;
}

