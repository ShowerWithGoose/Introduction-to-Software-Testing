#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct mes {
    char word[20];
    int cnt;
};

void lower(char line[]) {
    int len = strlen(line);
    for(int i=0; i<len; i++) {
        if(line[i]>='A' && line[i]<='Z') {
            line[i] = tolower(line[i]);
        }
    }
}

void dele(char line[]) {
    int len = strlen(line);
    for(int i=0; i<len; i++) {
        if((line[i]<'a' || line[i]>'z') && line[i]!=' ') {
            line[i] = ' ';
            /* for(int j=i; j<len; j++){
                line[j] = line[j+1];
            }
            line[len-1] = '\0';
            i--;
            len--; */
        }
    }
}

int rise(const void *p1, const void *p2) {
    struct mes *d1 = (struct mes *)p1;
    struct mes *d2 = (struct mes *)p2;
    if(strcmp(d1->word, d2->word)<0) return -1;
    else if(strcmp(d1->word, d2->word)>0) return 1;
    else return 0;
}

void guiling(char get[]) {
    for(int i=0; i<20; i++) {
        get[i] = '\0';
    }
}

int main() {
    char line[1000];
    struct mes count[10000];
    for(int i=0; i<10000; i++) {
        count[i].cnt = 0;
    }

    FILE *article = fopen("article.txt","r");

    int num=0;
    char get[20];
    while(fgets(line,1000,article) != NULL) {
        lower(line);
        dele(line);
        guiling(get);

        //取单词
        int pos=0, k=0,len=strlen(line);
        while(pos<len) {
            //最后一个单词之前
            if(line[pos] != ' ') {
                get[k] = line[pos];
                k++;
                pos++;
            } else if(get[0] != '\0') { // @@ Missing else branch to increment pos when line[pos] is space and get is empty, causing infinite loop.
                get[k] = '\0';
                k=0;
                pos++;

                //将get加入count
                int judge = 0;
                for(int i=0; i<=num; i++) {
                    if(strcmp(count[i].word, get) == 0) {
                        count[i].cnt++;
                        judge = 1;
                        break;
                    }
                }
                if(judge == 0) {
                    strcpy(count[num].word, get);
                    count[num].cnt++;
                    num++;
                }
                guiling(get);
            } // End of else if

            //最后一个单词
            if(pos == len) { // @@ This check is inside the loop; when the last character is not a space, pos reaches len only after the loop condition fails, so this block never executes, causing the last word to be missed (but not the TLE).
                if(get[0] != '\0') {
                    get[k] = '\0';
                    k=0;

                    //将get加入count
                    int judge = 0;
                    for(int i=0; i<=num; i++) {
                        if(strcmp(count[i].word, get) == 0) {
                            count[i].cnt++;
                            judge = 1;
                            break;
                        }
                    }
                    if(judge == 0) {
                        strcpy(count[num].word, get);
                        count[num].cnt++;
                        num++;
                    }
                    guiling(get);
                }
            }
        }
    }

    qsort(count, num, sizeof(struct mes), rise);
    for(int i=0; i<num; i++) {
        printf("%s %d\n", count[i].word, count[i].cnt);
    }

    fclose(article);
    return 0;
}