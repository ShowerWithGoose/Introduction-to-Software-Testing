#include <stdio.h>
int main(){
	char s[10000]={0}, a[10000]={0};
	gets(s);
	int i=0,k=0;
	for (i=0; s[i] != '\0'; i++,k++){
		if (s[i] == '-'){
			if (s[i-1] >= 'a' && s[i+1] <= 'z' && s[i-1] <= s[i+1]){
				int j=0;
				for (j=1; s[i-1]+j != s[i+1]; j++) a[k++] = s[i-1]+j;
				k--;
			}
			else if (s[i-1] >= 'A' && s[i+1] <= 'Z' && s[i-1] <= s[i+1]){
				int j=0;
				for (j=1; s[i-1]+j != s[i+1]; j++) a[k++] = s[i-1]+j;
				k--;
			}
			else if (s[i-1] >= '0' && s[i+1] <= '9' && s[i-1] <= s[i+1]){
				int j=0;
				for (j=1; s[i-1]+j != s[i+1]; j++) a[k++] = s[i-1]+j;
				k--;
			}
			else a[k]=s[i];
		}
		else a[k]=s[i];
		
		
		
	}
	
	printf("%s", a);
	return 0;
}

