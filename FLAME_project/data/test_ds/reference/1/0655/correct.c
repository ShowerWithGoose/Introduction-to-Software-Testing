#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))

int main() {
	int i,j,len;
	char c[10005],b[10005],k;
	scanf("%s",c);
	len =strlen (c);
	for(i=0,j=0;i<len ;i++){
		if (c[i]=='-'){
			if(c[i-1]>='a'&&c[i+1]<='z'&&c[i-1]<c[i+1]){
				for(k=c[i-1]+1;k<c[i+1];k++){
					b[j++]=k;
				}
			}
			else if(c[i-1]>='A'&&c[i+1]<='Z'&&c[i-1]<c[i+1]){
				for(k=c[i-1]+1;k<c[i+1];k++){
					b[j++]=k;
				}
			}
			else if (c[i-1]>='0'&&c[i+1]<='9'&&c[i-1]<c[i+1]){
				for(k=c[i-1]+1;k<c[i+1];k++){
					b[j++]=k;
				}
			}else b[j++]=c[i];
			i++;
		}
		b[j++]=c[i];
	}
	b[j]='\0';
	printf("%s",b);
	getchar();
	getchar();
	return 0;
}

