#include <stdio.h>
#include <string.h>
int main() {
	char s[105];
	int num[105];
	int weishu=0,flag = 0,zhengfu = 0,feiling = 0,k = 0;
	scanf("%s",s);
	int i,len=strlen(s);
	for(i = 0; i< len; i++) {
		if(s[i] == '.') flag = 1;
		if(flag == 1) weishu++;
		if(s[0]=='-') zhengfu = -1;
		if(s[i] != '0'  && s[i] != '-' && s[i] != '.') feiling = 1;
		if(feiling == 1 && s[i] != '.') {
			num[k] = s[i] - '0';
			k++;
		}
	}
	if(zhengfu == -1) printf("-");
	for(i = 0; i< k; i++) {
		if(i==1) printf(".%d",num[i]);
		else printf("%d",num[i]);
	}
	int zhishu = k - weishu;
	printf("e%d",zhishu);
	return 0;

}





