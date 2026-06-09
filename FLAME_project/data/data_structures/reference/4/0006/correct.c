#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define FEqual(a,b,eps) (fabs((a)-(b))<(eps)) 

FILE *in;
struct voc{
	char word[32];
	int num;
}index[4096];
char s[1024], t[32];
int n, l, t_read;
void getword();
void addword();
int cmp(const void*p1, const void*p2);

int main(){
	in = fopen("article.txt", "r");
	while (fgets(s, 1024, in)!=NULL){
		l=strlen(s);
		t_read=0;
		while(1){
			getword();
			if (t_read>=0){
				addword();
			}else if (t_read==-1){
				addword();
				break;
			}else break;
		}
	}
	qsort(index, n, sizeof(index[0]), cmp);
	for (int i=0; i<n; i++){
		printf("%s %d\n", index[i].word, index[i].num);
	}
	return 0;
}

void getword(){
	int flag=0;
	int j=0;
	for (int i=t_read; i<l; i++){
		if (s[i]>='A'&&s[i]<='Z'){
			t[j++]=s[i]+'a'-'A';
			flag=1;
		}else if (s[i]>='a'&&s[i]<='z'){
			t[j++]=s[i];
			flag=1;
		}else if (flag==1){
			t_read = i;
			t[j]='\0';
			return;
		}
	}
	if (flag==1) {
		t_read = -1;
		t[j]='\0';
	}
	else t_read = -2;
}

void addword(){
	for (int i=0; i<n; i++){
		if (strcmp(index[i].word, t)==0){
			index[i].num++;
			return;
		}
	}
	index[n].num=1;
	strcpy(index[n].word, t);
	n++;
}

int cmp(const void*p1, const void*p2){
	return strcmp(((struct voc*)p1)->word, ((struct voc*)p2)->word);
}



