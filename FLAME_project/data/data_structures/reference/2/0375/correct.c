#include <stdio.h>
int main(){
	char s[10000] = {0}, a[10000] = {0};
	
	gets(s);
	int i=0, k=0;
	for (i=0, k=0; s[i] != '\0'; i++, k++){
		if (s[i] == ' '){
			k--;
		}
		else a[k] = s[i];
	}//È¥³ý¿Õ¸ñ
	
	int x = 0, tmp = 0, ans=0, tmp2 = 0, tmp3 = 0;
	for (x=0; a[x] != '\0'; x++){
		if (a[x] <= '9' && a[x] >= '0'){
			
			int flag = 0;
			flag = a[x-1] == '-'? 1:0;
			tmp=0;
			for ( ; a[x] <= '9' && a[x] >= '0'; x++){
			
				tmp = tmp*10+a[x]-'0';
			}
			if (a[x] == '='){
				ans = flag ==1 ? -tmp:tmp;
			}
			if (a[x] == '*' || a[x] == '/'){
				
			while (a[x] == '*' || a[x] == '/'){
				int flag2 = 0;
				flag2 = a[x] == '*'? 1:0;
				tmp2 = 0;
				for (x++ ; a[x] <= '9' && a[x] >= '0'; x++){
				
				tmp2 = tmp2*10+a[x]-'0';
				}
				if (flag2 == 1) tmp *= tmp2;
				else tmp /= tmp2;
			}
			ans += flag == 1 ? -tmp:tmp;
			tmp = 0;
			}
			if (a[x] == '+' || a[x] == '-'){
			
			while (a[x] == '+' || a[x] == '-'){
				
				ans += flag ==1 ? -tmp:tmp;
				x++;
				
			}
			x--;
			}
		}
	}
	
	
	
	printf("%d", ans);
	return 0;
}







