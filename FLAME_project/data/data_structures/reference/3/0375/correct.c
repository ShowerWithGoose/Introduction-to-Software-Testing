#include <stdio.h>
int main(){
	char s[2000]={0}, ans[2000]={0};
	gets(s);
	int k=0;
	int one;
	int cnt;
	if (s[0] == '0'){
		int i=2;
		for (i=2; s[i] == '0'; i++);
		
		cnt = i-1;
		
		one = s[i] - '0';
		
		
		for (i++; s[i] != '\0'; i++, k++){
			ans[k] = s[i];
		}
			ans[k] = 'e';
			k++;
			ans[k] = '-';
			k++;
		if (k-2 == 0){
			
			printf("%d%s%d", one, ans, cnt);
			
		}
		else {
			printf("%d.%s%d", one, ans, cnt);
		}
	}
	else {
		int m=0;
		one = s[m] - '0';
		for (m=0; s[m] != '.'; m++);
		cnt = m-1;
		for (m = 1; s[m] != '\0'; m++, k++){
			if (s[m] == '.') {
			k--;
				continue;
			}
			ans[k] = s[m];
		}
		ans[k] = 'e';
	
		printf("%d.%s%d", one, ans, cnt);
		
		
	}
	
		
	
	
	return 0;
}

