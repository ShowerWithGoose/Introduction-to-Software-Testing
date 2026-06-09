#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE {
    char a[10];
    int num;
}node;
int cmp(const void*p11,const void*p22){
	node* p1=(node*)p11;
	node*p2=(node*)p22;
	return(strcmp(p1->a,p2->a));
	}

int main() {
    int n, k, i=0, j=0;
    node b[100];
	char c[10],ch;
    FILE* fp;
    fp = fopen("article.txt", "r");
    ch=fgetc(fp);
    while(ch!=EOF){
    	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
			c[i]=tolower(ch);
			i++;
			}
			else if(ch==' '||ch=='\n'||','||'.'){
				for(k=0;k<i;k++){
					b[j].a[k]=c[k];
					b[j].num=1;
				}
				b[j].a[i]='\0';
				j++;
				i=0;
			}
    	ch=fgetc(fp);
	}
    k = j;
    for (i = 0;i < k;i++) {
        for (j = i+1;j < k;j++) {
            if (strcmp(b[i].a, b[j].a) == 0) {
                b[j].num += b[i].num;
                b[i].num = 0;
            }
        }
    }
	qsort(b,k,sizeof(node),cmp);
    for (i = 0;i < k;i++) {
        if (b[i].num != 0&b[i].num<100) {
            printf("%s %d\n", b[i].a, b[i].num);
        }
    }
    fclose(fp);
    return 0;
}



