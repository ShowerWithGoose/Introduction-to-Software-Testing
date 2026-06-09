#include <stdio.h>
#include <string.h>

int main() {
	char ch[110] = {};
	int diyiwei;
	gets(ch);
	
	int ll = strlen(ch);
	for (diyiwei = 0; ch[diyiwei] == '0' || ch[diyiwei] == '.'; diyiwei++);//去掉开头的0,得到第一位
	
	if (strchr(ch, '.')) {
		int dot = strchr(ch, '.') - ch;//小数点的位置
		int i = ll - 1;
		for (; ch[i] == '0'; i--);
		ch[i+1] = '\0';//去掉末尾的0
		int zhishu = dot - diyiwei - 1;
		if (zhishu < 0) zhishu ++;
		printf("%c", ch[diyiwei]);//打出小数点之前的
		int flag = 0;
		for (int j = diyiwei + 1; ch[j] != '\0'; j++) 
			if (ch[j] != '.') flag ++;
		if (flag) {
			printf(".");
			for (int j = diyiwei + 1; ch[j] != '\0'; j++) 
				if (ch[j] != '.') printf("%c", ch[j]);		
		}
		printf("e%d", zhishu);
	}else {
		printf("%c", ch[diyiwei]);
		int zhishu = 0, flag = 0;
		for (int j = diyiwei + 1; ch[j] != '\0'; j++){
			zhishu ++;
			if (ch[j] != '0') flag ++;
		}
		if (flag) {
			printf(".");
			for (int j = diyiwei + 1; ch[j] != '\0'; j++) {
				if (ch[j] != '0') printf("%c", ch[j]);
			}		
		}
		printf("e%d", zhishu);
	}
	
	return 0;
}

