#include<stdio.h>
#include<string.h>
int main(){
	int i, j;
	char a[100], b[100];
	gets(a);
	for(i = 0, j = 0; a[i] != '\0'; i++){
		if(a[i] != '-') b[j++] = a[i];
		else if((a[i-1] <= '9' && a[i-1] >= '0' && a[i+1] <= '9' && a[i+1] >= '0' && a[i-1] < a[i+1]) || (a[i-1] <= 'z' && a[i-1] >= 'a' && a[i+1] <= 'z' && a[i+1] >= 'a'&&a[i-1] < a[i+1]) || (a[i-1] <= 'Z' && a[i-1] >= 'A' && a[i+1] <= 'Z' && a[i+1] >= 'A'&&a[i-1] < a[i+1])){
			char k = a[i-1];
			while(b[j-1] < a[i+1]-1){
				b[j++] = ++k;
			}
		}
		else b[j++] = '-';
	}
	b[j] = '\0';
	puts(b);
	return 0;
}



