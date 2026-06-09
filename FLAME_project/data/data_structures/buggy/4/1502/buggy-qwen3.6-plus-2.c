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
            if (line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z') {
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
        // @@ The loop ends after processing the last character of the line. If the line ends with a valid word (not followed by a non-alpha character within the buffer), that word is still in `word` but hasn't been added to the list because the `else` block (which triggers `add`) wasn't entered. We need to check and add the remaining word after the inner for-loop finishes.
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
                free(p); // @@ Memory leak: if the word already exists, we increment the count of the existing node but lose the pointer to the newly allocated node `p`, causing a memory leak. We should free `p` before exiting.
                goto exit;
            }
            last = last->next;
        }
        //最后一个节点
        if (strcmp(last->word, word) == 0) {
            last->rate++;
            free(p); // @@ Memory leak: same as above, if the word matches the last node, we leak the newly allocated node `p`.
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
    for (p = *head; p->next != NULL; p = p->next) { // @@ Potential crash: if `*head` is NULL, accessing `p->next` causes a segmentation fault. Although unlikely given the input, it's safer to check `p != NULL` and `p->next != NULL`. More importantly, the bubble sort logic is slightly flawed for a linked list swap of data, but logically it works for sorting data. However, the outer loop condition `p->next != NULL` will crash if head is NULL.
        for (q = (*head)->next; q != NULL; q = q->next) { // @@ Potential crash: if `*head` is NULL, `(*head)->next` crashes. Also, standard bubble sort usually compares adjacent elements or iterates differently. This implementation compares `p` with every `q` after head? No, `q` starts at head->next always. This is not a standard bubble sort. It compares `p` (starting at head) with all nodes `q` (starting at head->next). This effectively finds the minimum/maximum and swaps? No, it swaps if `p > q`. This is a selection-sort-like behavior but implemented with swaps. It will sort, but inefficiently. The main issue is safety.
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