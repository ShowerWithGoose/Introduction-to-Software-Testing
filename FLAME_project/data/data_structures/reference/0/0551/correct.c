#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
char a[30];
int main(){
	gets(a);
	int len;
	len=strlen(a);
	putchar(a[0]);
	for(int i=1;i<len;i++){
		if(a[i]=='-'&&((a[i-1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])||(a[i-1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])||(a[i-1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1]))){
			for(int j=1;a[i+1]-a[i-1]>=j;j++){
				putchar(a[i-1]+j);
			}i+=1;
		}else putchar(a[i]);
	}
	return 0;
}


