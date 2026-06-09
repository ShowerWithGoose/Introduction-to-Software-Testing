#include<stdio.h>
#include<string.h>
struct wc {
	char word[100];
	int number;
} woc[500];
char s[5000];
int i,j,k,n,cnt=0;

char trans(char a){
	if(a>='A'&&a<='Z') a=a-'A'+'a';
	else a=a;
	return a;
}

int alpha(char a) {
	if(a>='a'&&a<='z') return 1;
	else return 0;
}

void sort(struct wc woc[],int n) {
	int i, j, k, flag;
	struct wc tmp;
	for(i=0; i<n; i++) {
		woc[i].number=1;
	}
	for (i = 0; i < n; i++) {
		flag = 0;
		for (j = 0; j < n-1; j++) {
			if(strcmp(woc[j].word ,woc[j+1].word)>0) {
				tmp=woc[j];
				woc[j]=woc[j+1];
				woc[j+1]=tmp;
				flag = 1;
			} else if(strcmp(woc[j].word ,woc[j+1].word)==0) {
				woc[j].number+=woc[j+1].number;
				for(k=j+1; k<n; k++) {
					woc[k]=woc[k+1];
				}
				n--;
				j--;
				flag=1;
			}
		}
		if (0 == flag) break;
	}
	
	for(i=0; i<n; i++) {
		printf("%s %d\n",woc[i].word,woc[i].number);
	}
}

int main() {
	i=0;
	j=0;
	k=0;
	n=0;
	cnt=0;
	FILE *fp;
	fp=fopen("article.txt","r");
	
	while(fgets(s,5000,fp)!=NULL) {
		i=0;
		n=strlen(s);
		for(i=0;i<n;i++) s[i]=trans(s[i]);
		
		for(i=0; i<n; i++) {
			if(alpha(s[i])) {
				k=0;
				for(j=i; j<n; j++) {
					if(alpha(s[j])) {
						woc[cnt].word[k]=s[j];
						k++;
					} else {
						break;
					}
				}
				i=j;
				woc[cnt].number++;
				cnt++;
			}
		}
		for(i=0;i<5000;i++) s[i]='\0';
	}
	
	sort(woc,cnt);
	
	return 0;
}

