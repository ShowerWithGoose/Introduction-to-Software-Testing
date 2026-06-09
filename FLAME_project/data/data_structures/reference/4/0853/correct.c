#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main() {
	FILE *in;
	in = fopen("article.txt", "r");
	if (in == NULL) {
		printf("Can't open");
		return 1;
	}
	int x,i,j,k=0,p=0,q;
	char a[1000],d[1000];
	char b[1000][1000],e[1000][1000];
	int c[1000],f[1000];
	for(i=0; i<1000; i++) {
		c[i]=1;
	}
	while(fgets(a,1000,in)!=NULL) {
		x=strlen(a);
		for(i=0; i<x; i++) {
			if(a[i]>='A'&&a[i]<='Z') {
				a[i]=a[i]+'a'-'A';
				p=0;
				for(j=i;; j++) {
					if( a[j]>='a'&&a[j]<='z') {
						b[k][p]=a[j];
						p++;
					} else if(a[j]>='A'&&a[j]<='Z') {
						a[j]=a[j]+'a'-'A';
						b[k][p]=a[j];
						p++;
					} else break;
				}
				b[k][p]='\0';
				k++;
				i=j;
			} else if(a[i]>='a'&&a[i]<='z') {
				p=0;
				for(j=i;; j++) {
					if( a[j]>='a'&&a[j]<='z') {
						b[k][p]=a[j];
						p++;
					} else if(a[j]>='A'&&a[j]<='Z') {
						a[j]=a[j]+'a'-'A';
						b[k][p]=a[j];
						p++;
					} else break;
				}
				b[k][p]='\0';
				k++;
				i=j;
			}
		}
	}
	for(i=0; i<k; i++) {
		if(c[i]==0) {
			continue;
		}
		for(j=i+1; j<k; j++) {
			if(strcmp(b[i],b[j])==0) {
				c[i]++;
				c[j]=0;
			}
		}
	}
	x=0;
	for(i=0; i<k; i++) {
		if(c[i]!=0) {
			strcpy(e[x],b[i]);
			f[x]=c[i];
			x++;
		}
	}
	for(i=0; i<x; i++) {
		for(j=i+1; j<x; j++) {
			for(p=0;; p++) {
				if(e[i][p]>e[j][p]) {
					strcpy(d,e[i]);
					memset(e[i],0,sizeof(e[i]));
					strcpy(e[i],e[j]);
					memset(e[j],0,sizeof(e[j]));
					strcpy(e[j],d);
					memset(d,0,sizeof(d));
					q=f[i];
					f[i]=f[j];
					f[j]=q;
					break;
				} else if(e[i][p]<e[j][p]) {
					break;
				}
			}
		}
	}
	for(i=0; i<x; i++) {
		printf("%s %d\n",e[i],f[i]);
	}
}



