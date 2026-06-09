#include<stdio.h>
#include<string.h>

int main(){
	char s[100000], t[100000];
	gets(s);
	int len = strlen(s);
	int i, j = 0;
	for(i = 0; i < len; i++){
		if(s[i] == ' ') continue;
		t[j++] = s[i];
	}
	len = strlen(t);
	int num[100000], cnt = 0, nownum = 0;
	char op[100000];
	for(i = 0; i < len; i++){
		if('0' <= t[i] && t[i] <= '9'){
			nownum = nownum * 10 + (t[i] - '0');
		}else{
			num[cnt] = nownum;
			nownum = 0;
			op[cnt] = t[i];
			cnt++;
		}
	}
	int cnt_not = 0;
	nownum = num[0];
	for(i = 0; i < cnt; i++){
		if(op[i] == '*'){
			nownum *= num[i + 1];
		}else if(op[i] == '/'){
			nownum /= num[i + 1];
		}else{
			num[cnt_not] = nownum;
			op[cnt_not] = op[i];
			nownum = num[i + 1];
			cnt_not++;
		}
	}
	nownum = num[0];
	for(i = 0; i < cnt_not; i++){
		if(op[i] == '-'){
			nownum -= num[i + 1];
		}else if(op[i] == '+'){
			nownum += num[i + 1];
		}else{
			break;
		}
	}
	printf("%d\n", nownum);
	return 0;
}

