#include<stdio.h>
#include<string.h>
struct book {
	char cun[20];
	int num;
	int sign;
} keep[200],out[200];
int cmp(const void *a, const void *b) {
	struct book *A = (struct book *)a;
	struct book *B = (struct book *)b;
	return strcmp(A->cun,B->cun);
}
int main() {

	FILE*fp;
	fp=fopen("article.txt","r");
	char ch;
	int i=0,j=0,n;

	ch=fgetc(fp);
	while(ch!=EOF) {
		 if(ch<=90&&ch>=65) {
			keep[i].cun[j++]=ch+32;
			keep[i].sign=1;
		} 
		else if(ch<=122&&ch>=97) {
			keep[i].cun[j++]=ch;
			keep[i].sign=1;
		}
		else {
			keep[i].cun[j]='\0';
			i++,j=0;
		}
		ch=fgetc(fp);
	}
	n=i;
	qsort(keep, n, sizeof(struct book), cmp);
	
	for(i=0; i<n; i++) {
		if(keep[i].sign) {
			keep[i].num=1;
			for(j=i+1; j<n; j++) {
				if(strcmp(keep[i].cun,keep[j].cun)==0) {
					keep[i].num++;
					keep[j].sign=0;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
    {
        if (keep[i].sign)
        {
            printf("%s %d\n", keep[i].cun, keep[i].num);
        }
    }
    fclose(fp);
    return 0;

}



