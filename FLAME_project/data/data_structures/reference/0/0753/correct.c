#include <stdio.h>

int main(){
	char s[1000], a[1000];
	scanf("%s", s);
	int i = 0, j = 0;
	for(; s[i] != '\0'; i++){
		if(s[i] == '-'){
			if(s[i+1] <= s[i-1]){
				a[j++] = s[i];
				continue;
			}
			if(s[i-1]<='9' && s[i-1]>='0' && (s[i+1]>'9' || s[i+1]<'0')){
				a[j++] = s[i];
				continue;
			}
			else if(s[i-1]<='z'&& s[i-1]>='a'&& (s[i+1]>'z' || s[i+1]<'a')){
				a[j++] = s[i];
				continue;
			}
			else if(s[i-1]<='Z' && s[i-1]>='A' && (s[i+1]>'Z' || s[i+1]<'A')){
				a[j++] = s[i];
				continue;
			}
			else{
				int k = 1;
				for(; k < s[i+1] - s[i-1]; k++) a[j++] = s[i-1] + k;
				i++;
			}
			
		}
		a[j++] = s[i];
	}
	a[j] = '\0';
    printf("%s\n", a);
}







