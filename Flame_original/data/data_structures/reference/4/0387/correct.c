#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int l, d, e, i = 0, n,k,len,j;
struct word {
	char ss[111][111];
	int num;
};
char s[1105][142];
char str[1111];
char temp[1111];
int main() {
	FILE *fp;
	fp = fopen("article.txt", "r");
	while ((fgets(str,100,fp)) != NULL) {
		l=strlen(str);
		for(i=0; i < l; i++ ) {
			if(isupper(str[i]))
				str[i]=tolower(str[i]);//´óÐ´»»³ÉÐ¡Ð´
			if(isalpha(str[i])) {
				s[n][j]=str[i];
				j++;
			}
			if(!isalpha(str[i])) {
				s[n][j]='\0';
				j=0;
				n++;
			}
		}
		//printf("%s",str);

	}
	for(i=0; i<n; i++) {
		for (j = i + 1; j < n; j++) {
			if (strcmp(s [i], s[j]) > 0) {
				strcpy(temp, s [j]);
				strcpy(s[j], s [i]);
				strcpy(s [i], temp);
			}
		}
	}
//	for(i=0; i<n; i++)
//	printf("%s\n",s[i]);
	int num=1;
	for(i =0 ; i<n; i++) {
		if(strlen(s[i])!=0) {
			j=i+1;
			while(strcmp(s[i],s[j])==0) {
				num++;
				j++;
			}
			printf("%s %d\n",s[i],num);
			num=1;
			i=j-1;
		}
	}


	fclose(fp);

}





