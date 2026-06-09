#include<stdio.h>
#include<string.h>
char a[1000],b[1000],*p,*q;int i;
int main() {

	p=a;
	q=b;
	gets(a);
	for(i=0; i<strlen(a); i++) {
		if(i==0&&a[i]=='-') {
			*q=a[i];
			q++;
			continue;
		}
		if(i==strlen(a)-1&&a[i]=='-') {
			*q=a[i];
			break;
		}
		if(i>0&&a[i]=='-') {
			if(a[i+1]=='-') {
				*q=a[i];
				q++;
				continue;
			}

			if('0'<=a[i-1]&&a[i-1]<='9'&&a[i+1]>a[i-1]&&'0'<=a[i+1]&&a[i+1]<='9') {

				for(; *(q-1)<a[i+1]; q++) {
					*q=*(q-1)+1;
				}
				q--;
				continue;

			} else if('a'<=a[i-1]&&a[i-1]<='z'&&a[i+1]>a[i-1]&&'a'<=a[i+1]&&a[i+1]<='z') {

				for(; *(q-1)<a[i+1]; q++) {
					*q=*(q-1)+1;
				}
				q--;
				continue;


			} else if('A'<=a[i-1]&&a[i-1]<='Z'&&a[i+1]>a[i-1]&&'A'<=a[i+1]&&a[i+1]<='Z') {

				for(; *(q-1)<a[i+1]; q++) {
					*q=*(q-1)+1;
				}
				q--;
				continue;

			}

		} *q=a[i];

		q++;
	}

	puts(b);



	return 0;
}

