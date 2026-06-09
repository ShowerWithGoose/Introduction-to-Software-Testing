#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int i,j=0,k;
	char a[200],b[200]={""};
	scanf("%s",a);
	for(i=0;i<strlen(a);i++){
		if(a[i]!='-') b[j++]=a[i];
		else if('0'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='9'){
			k=a[i+1]-a[i-1]-1;
			for(;k>0;k--){
				b[j++]=++a[i-1];
			}
		}
		else if('a'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='z'){
			k=a[i+1]-a[i-1]-1;
			for(;k>0;k--){
				b[j++]=++a[i-1];
			}
		}
		else if('A'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='Z'){
			k=a[i+1]-a[i-1]-1;
			for(;k>0;k--){
				b[j++]=++a[i-1];
			}
		}
		else b[j++]=a[i];
	}
	puts(b);
	return 0;
}

