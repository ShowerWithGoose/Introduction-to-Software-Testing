#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct word{
	char c[80];
	int num;
	struct word *llind, *rlind;
}*tree[10010];
int getword(FILE *bfp, char word[]){
	int i = 0;
	int temp;
	while((temp = fgetc(bfp)) != EOF){
		if(temp == '\f') return 1;
		else if(isalpha(temp)){
			word[i]=tolower(temp);
			i++;
		}
		else if(i > 0){
			word[i] = '\0';
			return 0;
		}
	}
	return EOF;
}
struct word *insert(struct word *p, char *w){
    if(p == NULL){
        p = (struct word *)malloc(sizeof(struct word));
        p->num = 1;
        p->llind = p->rlind = NULL;
        strcpy(p->c, w);
    }else{
        if(strcmp(w, p->c) < 0){
            p->llind = insert(p->llind, w);
        }else if(strcmp(w, p->c) > 0){
            p->rlind = insert(p->rlind, w);
        }else if(strcmp(w, p->c) == 0){
            p->num++;
        }
    }
    return p;
}
void printtree(struct word *p) {
    if(p == NULL){
        return;
    }else{
        printtree(p->llind);
        if(p->num != 0){
        	printf("%s %d\n", p->c, p->num);
		}
        printtree(p->rlind);
        return;
    }
}
char ch[80];
int main(){
	FILE *fp;
	fp = fopen("article.txt", "r");
	while(getword(fp, ch) != EOF){
		insert(tree, ch);
	}
	printtree(tree);
	return 0;
}



