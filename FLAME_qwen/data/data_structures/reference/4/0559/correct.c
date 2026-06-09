#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
struct word {
	char name[30];
	int frequency;
};
struct word a[2000];
FILE *in;
char line[310] = {0};
char buf[30];
int cmp(const void *p1, const void *p2)
{
	struct word m =*(struct word *)p1;
	struct word n =*(struct word *)p2;
	if(strcmp(m.name,n.name)<0){
		return -1;
	}
	else if(strcmp(m.name,n.name)>0){
		return 1;
	}
	return 0;
}

int main() {
	in=fopen("article.txt","r");
	int cnt = 0, mark = -1,puct=1;
	//
	//
	int j=0;
	while (fgets(line,1023,in)!=NULL) {
		//注意小写
		int len = strlen(line);
		for (int i = 0,  k = 0; i < len; i++) {

			if (isalpha((int)line[i])) {
				buf[k] = tolower(line[i]) ;
				k++;
				puct=0;
			}
			else if((ispunct(line[i])||line[i]==' '||line[i]=='\0'||line[i]=='\n')&&puct==0){
				puct=1;
				if (cnt == 0) {
					strcpy(a[j].name, buf);
					a[j].frequency = 1;
					cnt++;
					j++;
				} else {
					for (int m = 0; m < cnt; m++) {
						int temp1=strlen(a[m].name);
						int temp2=strlen(buf);

						if (strcmp(a[m].name, buf)==0) {
							mark = m;
							break;
						} else {
							continue;
						}
					}
					//找到了就是m;
					if (mark == -1) {
						strcpy(a[j].name, buf);
						a[j].frequency = 1;
						cnt++;
						j++;
					} else {
						a[mark].frequency++;
					}
				}
				k = 0;
				mark=-1;
				memset(buf, 0, sizeof(buf));
			}

		}
	}
	qsort(a,cnt,sizeof(a[0]),cmp);

	for (int i = 0; i < cnt; i++) {
		printf("%s %d\n", a[i].name, a[i].frequency);
	}
	return 0;
}

