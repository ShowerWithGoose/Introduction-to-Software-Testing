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
            } else if(get[0] != '\0') {
                get[k] = '\0';
                k=0;
                pos++;

                //将get加入count
                int judge = 0;
                for(int i=0; i<=num; i++) { // @@ [This loop runs up to `i<=num`, which includes an uninitialized entry `count[num]`. This causes unnecessary comparisons and may lead to undefined behavior or performance degradation. It should be `i < num`.]
                    if(strcmp(count[i].word, get) == 0) {
                        count[i].cnt++;
                        judge = 1;
                        break;
                    }
                }
                if(judge == 0) {
                    strcpy(count[num].word, get);
                    count[num].cnt++; // @@ [This sets count[num].cnt to 1, but earlier the array was initialized to 0. However, the real issue is that this linear search for every word leads to O(n^2) time complexity, which causes Time Limit Exceeded on larger inputs.]
                    num++;
                }
                guiling(get);
            }

            //最后一个单词
            if(pos == len) {
                if(get[0] != '\0') {
                    get[k] = '\0';
                    k=0;

                    //将get加入count
                    int judge = 0;
                    for(int i=0; i<=num; i++) { // @@ [Same error as above: should be `i < num`. Also contributes to O(n^2) inefficiency.]
                        if(strcmp(count[i].word, get) == 0) {
                            count[i].cnt++;
                            judge = 1;
                            break;
                        }
                    }
                    if(judge == 0) {
                        strcpy(count[num].word, get);
                        count[num].cnt++; // @@ [Again, this naive insertion with linear search per word causes quadratic time complexity, leading to Time Limit Exceeded.]
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