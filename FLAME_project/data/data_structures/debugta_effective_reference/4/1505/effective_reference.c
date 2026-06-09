#include <stdio.h>
#include <string.h>
#define MAXWORD 32
typedef struct{
    char str[MAXWORD];
    int cnt;
} Str;
int cmp(const void *a, const void *b) {
    Str *aa = (Str *)a;
    Str *bb = (Str *)b;
    int n;
    if(strcmp(aa->str, bb->str) > 0) n = 1;
    if(strcmp(aa->str, bb->str) < 0) n = -1;
    if(strcmp(aa->str, bb->str) == 0) n = 0;
    return n;
}
int isLetter(int c) {
    if(c == EOF)
        return 1;
    return (c>='a'&&c<='z' || c>='A'&&c<='Z');
}
int main() {
    char str[MAXWORD];
    FILE *fp;
    Str start[200];
    int num = 0;
    int i, j, nuWord = 1;
    int c;

    fp = fopen("article.txt", "r");
    while(1) {
        i = 0;
        while(isLetter(c = fgetc(fp))) {
            if(c == EOF)
                break;
            str[i] = c;
            i++;
        }
        if(c == EOF)
            break;
        str[i] = '\0';
        if(str[0] == '\0')
            continue;

        //换小写
        for(i = 0; str[i] != '\0'; i++) {
            str[i] = (str[i]>='A'&&str[i]<='Z')? str[i]+32 : str[i];
        }

        //去标点
//        for(i = j = 0; tmp[i]!='\0'; i++)
//            if(tmp[i] >= 'a'&&tmp[i] <= 'z' || tmp[i] >= 'A'&&tmp[i] <= 'Z')
//                tmp[j++] = tmp[i];
//        tmp[j]='\0';

//        for(i = 0; i < num; i++) {
//            for(j = 0; words[i].str[j] != '\0'; j++)
//                words[i].str[j] = (words[i].str[j]>='A'&&words[i].str[j]<='Z')? words[i].str[j]+32 : words[i].str[j];
//        }

        nuWord = 1;
        for(i = 0; i < num; i++)
            if(strcmp(str, start[i].str) == 0) {
                nuWord = 0;
                start[i].cnt++;
                break;
            }
        if(nuWord == 1) {
            strcpy(start[num].str, str);//include '\0'
            start[num].cnt = 1;
            num++;
        }
    }

//    for(i = 0; i < num; i++) {
//        for(j = 0; words[i].str[j] != '\0'; j++)
//            words[i].str[j] = (words[i].str[j]>='A'&&words[i].str[j]<='Z')? words[i].str[j]+32 : words[i].str[j];
//    }
    qsort(start, num, sizeof(start[0]), cmp);

    for(i = 0; i < num; i++) {
        printf("%s %d\n", start[i].str, start[i].cnt);
    }
    return 0;
}

#if 0
{

typedef struct node {
    char word[MAXWORD];
    int cnt;
    struct node *next;
} node;
node *head = NULL;
int getWord(FILE *in, char *w);
int searchWord(char *w);
int insertWord(node *p, char *w);

int main () {
    char word[MAXWORD];
    FILE *in;
    in = fopen("article.txt", "r");

    while(getWord(in, word) != EOF) {
        a = searchWord();
        if(a == 0)
            insertWord;
        else
            add;
    }
    bubble_sort();

    for(){
        printf();
    }
}

int searchWord(char *w) {
    node *p, *q = NULL;
    for(p = head; p != NULL; q = p, p = p->next) {

    }
}
int insertWord(node *p, char *w) {
    node *q;
    q = (node *)malloc(sizeof(node));
    if(q == NULL)
        return -1;
}
int getWord(FILE *in, char *w) {
    char *start, *end;
    start = w;
    int c;
    while((c = fgetc(in)) != EOF) {
        if(w>='a'&&w<='z' || w>='A'&&w<='Z')
            w++;
        else

    }
    while(w>='a'&&w<='z' || w>='A'&&w<='Z')
        w++;
    end = w-1;
}

}
#endif // 0

