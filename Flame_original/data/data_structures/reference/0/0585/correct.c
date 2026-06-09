#include<stdio.h>
#include<string.h>
char a[10000];
int main(){
	int k;
	gets(a);
	k=strlen(a);
	for(int i=0;i<k;i++){
		if(a[i]=='-'&&(('0'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='9')||('a'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='z')||('A'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='Z'))) {
			while(a[i-1]<a[i+1]-1) {
				printf("%c",a[i-1]+1);
				a[i-1]++;
			}}
		else printf("%c",a[i]);
		}
	
	return 0;
}


