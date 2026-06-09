#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define lli long long int
FILE *in;
char s[100001],t[100001];
struct zi {
	char a[10001];
	int cnt;
} ans[10001];
int fi(const void *p1,const void *p2) {
	struct zi *m=(struct zi *)p1;
	struct zi *n=(struct zi *)p2;
	return strcmp(m->a,n->a);
}
int l,i,j,be,end,num,flag;
int main() {
	in=fopen("article.txt","r");
	num=0;
	while(fgets(s,100000,in)!=NULL) {
		l=strlen(s);
		for(i=0; i<l; i++) {
			if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) {
				j=0;
				while((s[i+j]>='a'&&s[i+j]<='z')||(s[i+j]>='A'&&s[i+j]<='Z')) {
					if(s[i+j]>='A'&&s[i+j]<='Z')
						s[i+j]=s[i+j]-'A'+'a';
					t[j]=s[i+j];
					j++;
				}
				t[j]='\0';
				i=i+j;
				flag=0;
				for(j=1; j<=num; j++) {
					if(!strcmp(ans[j].a,t)) {
						flag=1;
						ans[j].cnt++;
					}
				}
				if(!flag) {
					num++;
					for(j=0; j<strlen(t); j++) {
						ans[num].a[j]=t[j];
					}
					ans[num].cnt++;
				}
			}
		}
	}
	qsort(ans+1,num,sizeof(struct zi),fi);
	for(i=1; i<=num; i++) {
		printf("%s %d\n",ans[i].a,ans[i].cnt);
	}
	return 0;
}



