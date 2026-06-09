#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct node {
	char w[50];
	int c;
} a[5000], b;

bool v[5000] = {0};
int cnt = 0;
char s[50];

void proc() {
	int l = strlen(s);

	for (int i = 0; i < l; i++) {

		if ((s[i] >= 'A' && s[i] <= 'Z'))
			s[i] += 32;
	}

	for (int i = 0; i < l; i++) {

		if (!(s[i] >= 'a' && s[i] <= 'z')) {
			for (int j = i; j < l - 1; j++) {

				s[j] = s[j + 1];
			}

			s[l - 1] = '\0';
			i--;
			l--;
		}
	}
}

/*
void t(){
	char q=fgetc(fp);
	char s[50],cn=0;
	while(q!=-1){
		if ((q >= 'A' && q <= 'Z'))
			q += 32;
		if (!(q >= 'a' && q <= 'z')){
			s[cn]='\0';
			strcpy(b.w,s);
		}
		else{
			s[cn++]=q;
		}
		q=fgetc(fp);
	}
}
*/
int main() {
	FILE *fp = fopen("article.txt", "r");
	char q = fgetc(fp);
	char s[50], cn = 0;

	while (q != -1) {
		if ((q >= 'A' && q <= 'Z'))
			q += 32;
		if (!(q >= 'a' && q <= 'z')) {
			s[cn] = '\0';
			if(cn>0){
			int lab = 0;
			for (int i = 1; i <= cnt; i++) {
				if (!strcmp(a[i].w, s)) {
					a[i].c++;
					lab = 1;
					break;
				}
			}
			if (!lab) {
				a[++cnt].c = 1;
				strcpy(a[cnt].w, s);
			}
			cn=0;
			s[0]='\0';
		}
		} else {
			s[cn++] = q;
		}
		q = fgetc(fp);
	}
	/*
		while (fscanf(fp, "%s", s) != EOF) {
			proc();

			if (cnt == 0) {
				cnt++;
				strcpy(a[cnt].w, s);
				a[cnt].c = 0;
			}

			int lab = 0;

			for (int i = 1; i <= cnt; i++) {

				if (!strcmp(a[i].w, s)) {
					a[i].c++;
					lab = 1;
					break;
				}
			}

			if (!lab) {
				a[++cnt].c = 1;
				strcpy(a[cnt].w, s);
			}
		}
	*/
	for (int k = 1; k <= cnt; k++) {

		int sh;
		char z[50] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

		for (int i = 1; i <= cnt; i++) {

			if (!v[i]) {
				if (strcmp(z, a[i].w) > 0) {
					strcpy(z, a[i].w);
					sh = i;
				}
			}
		}

		printf("%s %d\n", a[sh].w, a[sh].c);
		v[sh] = 1;
	}
	return 0;
}
