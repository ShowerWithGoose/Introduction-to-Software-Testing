#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _node {
    char word[20];
    int rate;
    struct _node* next;
}Node;

void add(Node** head, char word[]);
void sort(Node** head);
void print(Node* head);

int main()
{
    FILE* fp = fopen("article.txt", "r");
    int i, j;
    char word[20] = { 0 }; 
    char line[200] = { 0 };
    Node* head = NULL;

    while (fgets(line, 200, fp) != NULL) {
        j = 0;
        for (i = 0; i < strlen(line); i++) {
            if (line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z') { // @@ [Operator precedence error: && has higher precedence than ||, so the condition is evaluated as (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'), which is correct, but the logic is fine; however, the issue is that the condition should use parentheses for clarity, but it's not an error per se. The actual error is that the loop may process the last word incorrectly if the line ends without a non-alphabetic character.]
                word[j++] = tolower(line[i]);
            }
            else {
                if (word[0] != '\0') {
                    add(&head, word);
                    j = 0;
                    //清空word
                    for (int k = 0; k < 20; k++) {
                        word[k] = '\0';
                    }
                }
            }
        }
    }

    fclose(fp);
    sort(&head);
    print(head);
    
    return 0;
}

void add(Node** head, char word[]) {
    int i;
    Node* p = (Node*)malloc(sizeof(Node));
    for (i = 0; i < strlen(word); i++) {
        p->word[i] = word[i];
    }
    p->word[i] = '\0';
    p->rate = 1;
    p->next = NULL;

    //插入链表
    Node* last = *head;
    if (last != NULL) {
        while (last->next != NULL) {
            if (strcmp(last->word, word) == 0) {
                last->rate++;
                goto exit;
            }
            last = last->next;
        }
        //最后一个节点
        if (strcmp(last->word, word) == 0) {
            last->rate++;
            goto exit;
        }
        last->next = p;
    }
    else {
        *head = p;
    }

exit:;
}

void sort(Node** head) {
    Node* p, * q;
    for (p = *head; p->next != NULL; p = p->next) { // @@ [Error: The outer loop condition p->next != NULL may cause issues if the list has only one node, but the main problem is that the sorting algorithm is incorrect. The inner loop starts from (*head)->next, which means it always compares from the second node, and the outer loop iterates over all nodes, but the swapping logic does not properly sort the list in lexicographic order because it compares p with q but q starts from the second node each time, leading to incorrect comparisons and potential infinite loops or unsorted output.]
        for (q = (*head)->next; q != NULL; q = q->next) {
            if (strcmp(p->word, q->word) > 0) {
                //交换word
                char tempWord[20] = { 0 };
                strcpy(tempWord, p->word);
                strcpy(p->word, q->word);
                strcpy(q->word, tempWord);

                //交换rate
                int temp = p->rate;
                p->rate = q->rate;
                q->rate = temp;
            }
        }
    }
    
}

void print(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%s ", p->word);
        printf("%d\n", p->rate);
        p = p->next;
    }
}