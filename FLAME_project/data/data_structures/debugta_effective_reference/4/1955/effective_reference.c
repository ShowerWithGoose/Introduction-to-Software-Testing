#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct FRE {
    char word[100];
    int time;
    struct FRE* next;
};

int getWord(FILE*, char*);
int searchWord(struct FRE*, char*);
struct FRE* BubbleSort(struct FRE*);

int num = 0;
int main() {
    struct FRE *head, *ptr, *q;
    char inWord[1000];
    FILE* in = fopen("article.txt", "r");
    head = ptr = (struct FRE*)malloc(sizeof(struct FRE));

    while (getWord(in, inWord) != EOF) {
        // printf("%s\n",inWord);
        if (searchWord(head, inWord) == 0) {
            strcpy(ptr->word, inWord);
            ptr->time = 1;
            memset(inWord, 0, sizeof(inWord));
            num++;
            ptr->next = (struct FRE*)malloc(sizeof(struct FRE));
            ptr = ptr->next;
        }
    }
    ptr = BubbleSort(head)->next;
    for (int i = 0; i < num; i++) {
        printf("%s %d\n", ptr->word, ptr->time);
        q = ptr;
        ptr = ptr->next;
        free(q);
    }
    fclose(in);
    return 0;
}

int getWord(FILE* fp, char* w) {
    int c;
    while (!isalpha(c = fgetc(fp)))
        if (c == EOF)
            return c;
        else
            continue;
    do {
        *w++ = tolower(c);
    } while (isalpha(c = fgetc(fp)));
    *w = '\0';
    return 1;
}

int searchWord(struct FRE* first, char* w) {
    int i, flag = 0;
    struct FRE* search = first;
    for (i = 0; i < num; i++) {
        if (strcmp(search->word, w) == 0) {
            flag = 1;
            search->time++;
            break;
        }  //
        else
            search = search->next;
    }
    return flag;
}

struct FRE* BubbleSort(struct FRE* first) {
    struct FRE *cur, *tail;
    cur = first;
    tail = NULL;
    if (cur == NULL || cur->next == NULL) {
        return first;
    }
    while (cur != tail) {
        while (cur->next != tail) {
            if (strcmp(cur->word, cur->next->word) > 0) {
                struct FRE temp;
                strcpy(temp.word, cur->word);
                temp.time = cur->time;
                strcpy(cur->word, cur->next->word);
                cur->time = cur->next->time;
                strcpy(cur->next->word, temp.word);
                cur->next->time = temp.time;
            }
            cur = cur->next;
        }
        tail = cur;
        cur = first;
    }
    return first;
}
