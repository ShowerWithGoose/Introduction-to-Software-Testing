#include<stdio.h>
#include<string.h>
#include<math.h>
char c[1000],a;
int i=0;
int main() {
	scanf("%s",c);
	for( ; i<=strlen(c)-2; i++) {
		if(c[i]=='-') {
			a=c[i-1]+1;
			while(a<c[i+1]) {
				printf("%c",a);
				a++;
			}
			i++;
		}
		
		if(c[i+1]!='-')printf("%c",c[i]);
		else {
			if(c[i]>='0'&&c[i]<='9') {
				if(c[i+2]>c[i]&&c[i+2]<='9') {
					a=c[i];
					while(a<=c[i+2]) {
						printf("%c",a);
						a++;
					}
					i+=2;
				} else {
					printf("%c-",c[i]);
					i++;
				}
			}
			if(c[i]>='a'&&c[i]<='z') {
				if(c[i+2]>c[i]&&c[i+2]<='z') {
					a=c[i];
					while(a<=c[i+2]) {
						printf("%c",a);
						a++;
					}
					i+=2;
				} else {
					printf("%c-",c[i]);
					i++;
				}
			}
			if(c[i]>='A'&&c[i]<='Z') {
				if(c[i+2]>c[i]&&c[i+2]<='Z') {
					a=c[i];
					while(a<=c[i+2]) {
						printf("%c",a);
						a++;
					}
					i+=2;
				} else {
					printf("%c-",c[i]);
					i++;
				}
			}
		}
	}
	printf("%c",c[i]);
	return 0;
}




