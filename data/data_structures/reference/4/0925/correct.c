#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
	struct zi {
		char a[100];
		int n;
	} zidian[500];
int cmp(const void*,const void*);
int main() {

	char c,c1[100];
		memset(c1,0,sizeof(c1));
	int n1=0,n2=0,n3;
	FILE *in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF) {

		c=tolower(c);

		if(c<='z'&&c>='a') {
			c1[n1]=c;
			n1++;
		}

		else {

			if(c1[0]<='z'&&c1[0]>='a') {
				for(n3=0; n3<=n2; n3++) {
					if(strcmp(c1,zidian[n3].a)==0) {
						zidian[n3].n++;
						goto L;
					}
				}
				strcpy(zidian[n3].a,c1);
				zidian[n3].n++;

				n2++;
			}
L:				memset(c1,0,sizeof(c1));
			n1=0;
		}
	}
	qsort(zidian,n2+1,sizeof(zidian[0]),cmp);
	for(n3=1; n3<=n2; n3++)
		printf("%s %d\n",zidian[n3].a,zidian[n3].n);
	return 0;
}
int cmp(const void*d,const void*b) {
	return strcmp(((struct zi*)d)->a,((struct zi*)b)->a);
}

