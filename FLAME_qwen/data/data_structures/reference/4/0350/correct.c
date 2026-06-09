#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char a[1050],b[1000000][55];
struct Node {
	char name[55];
	long long cnt;
} word[1000];
int is(char e) {
	if(('a'<=e && e<='z') || ('A'<=e && e<='Z')) return 1;
	return 0;
}
int flag[1000000];
int cmp(const void*a,const void *b) {
	struct Node * c=(struct Node *)a;
	struct Node * d=(struct Node *)b;
	return strcmp(c->name,d->name);
}
int main() {
	int i=0,j=0,k=0,x,y,z,n=1,m=1;
	FILE *in,*out;
	if((in = fopen("article.txt", "r")) == NULL) {
		printf("Can't open file article!\n");
		return -1;
	}
	while(fgets(a,1024,in)) {
		for(i=0; i<strlen(a); i++) {
			if(is(a[i])) {
				for(j=i; j<strlen(a); j++) {
					if(!is(a[j])) {
						break;
					}
					if('a'<=a[j] && a[j]<='z') {
						b[m][j-i]=a[j];
					} else {
						b[m][j-i]=a[j]-'A'+'a';
					}
//					printf("%c",b[m][j-i]) ;
				}
				m++;
				i=j-1;
			}
		}
	}
	for(i=1; i<=m; i++) {
		if(flag[i]==0){
			for(k=0;k<strlen(b[i]);k++){
				word[n].name[k]=b[i][k];
				word[n].cnt=1;
				flag[i]=1;
			}
			for(j=i+1;j<=m;j++){
				if(strcmp(b[i],b[j])==0){
					word[n].cnt++;
					flag[j]=1;
				}
			}
			n++;
		}
		else{
			continue;
		}
	}
//	printf("%d",cnt);
	qsort(word+1,n,sizeof(word[1]),cmp);
	for(i=1; i<=n; i++) {
		if(word[i].cnt!=0)
		printf("%s %lld\n",word[i].name,word[i].cnt);
	}
	return 0;
}


