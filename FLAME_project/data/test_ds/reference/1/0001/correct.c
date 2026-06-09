#include<stdio.h>
#include<string.h>

int check(char a, char b){
	if(('a' <= a && a <= 'z' && 'a' <= b && b <= 'z')
	   || ('A' <= a && a <= 'Z' && 'A' <= b && b <= 'Z')
	   || ('0' <= a && a <= '9' && '0' <= b && b <= '9')){
	   	if(a < b) return 1;
	}
	return 0;
}
int main(){
	char s[10000], t[10000];
	scanf("%s", s);
	int len = strlen(s);
	int i, j = 0;
	for(i = 0; i < len; i++){
		if(s[i] == '-'){
			if(i == 0 || i == len - 1){
				t[j++] = s[i];
				continue;
			}
			if(check(s[i - 1], s[i + 1])){
				char exp = s[i - 1] + 1;
				while(exp < s[i + 1]){
					t[j++] = exp;
					exp += 1;
				}
			}else{
				t[j++] = s[i];
			}
		}else{
			t[j++] = s[i];
		}
	}
	printf("%s\n", t);
	return 0;
}

