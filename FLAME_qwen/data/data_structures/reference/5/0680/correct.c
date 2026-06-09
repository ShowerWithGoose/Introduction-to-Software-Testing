#include<stdio.h>
#include<stdlib.h>
struct math {
	int x;
	int y;
} pol[100];
struct thma {
	int a;
	int b;
} mal[100];
struct res {
	int p;
	int q;
} result[10000];
int cmp(const void *mn,const void *nm) {
	struct res *ab=mn;
	struct res *ba=nm;
	return (ba->q)-(ab->q);
}
int flag[100];
char a[100];
char b[100];
int main() {
	int i=0,j=0,k,n=0,t=0,len1,len2;
	char c;
	do {
		scanf("%d%d%c",&pol[i].x,&pol[i].y,&c);
		i++;
	} while(c!='\n');
	j=i;
	i=0;
	do {
		scanf("%d%d%c",&mal[i].a,&mal[i].b,&c);
		i++;
	} while(c!='\n');
	k=i;
	for(i=0; i<j; i++) {
		for(n=0; n<k; n++) {
			result[t].p=pol[i].x*mal[n].a;
			result[t].q=pol[i].y+mal[n].b;
			t++;
		}
	}
	qsort(result,t,sizeof(result[0]),cmp);
	for(i=0; i<t; i++) {
		for(j=i+1; j<t; j++) {
			if(result[i].q==result[j].q&&flag[i]==0) {
				result[i].p+=result[j].p;
				flag[j]++;
			}
		}
	}
	for(i=0; i<t; i++) {
		if(flag[i]==0) {
			printf("%d %d ",result[i].p,result[i].q);
		}
	}
}

