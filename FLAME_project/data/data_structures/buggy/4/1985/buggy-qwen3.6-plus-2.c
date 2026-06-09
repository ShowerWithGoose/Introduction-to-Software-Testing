#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct article
{
    char word[50];
    int num;
    struct article *next;
};
typedef struct article AR;

AR *head, *tail, *p, *q;

int main()
{
    FILE *IN = fopen("article.txt", "r");
    char w[100], new[100];
    p = (struct article *)malloc(sizeof(struct article));
    head = p;
    tail = p;
    p->next = NULL;
    int n = 0;
    int x = 0;
    int h;
    while (fgets(new, sizeof(new), IN))
    {
        h = 0;
        x = 0;
        for (int i = 0; i < strlen(new); i++)
        {
            if ((new[i] >= 'a' && new[i] <= 'z') || (new[i] >= 'A' && new[i] <= 'Z') || new[i] == ' ')
            {
                w[x] = new[i];
                x++;
            }else{
                w[x]=' '; // @@ The logic here replaces non-alphanumeric characters with spaces, but fails to handle the case where a word is immediately followed by a non-alpha character without a space, effectively merging them if the previous char was alpha. More critically, it doesn't isolate words correctly according to the definition "sequence of characters consisting only of letters". For example "since1972" becomes "since     ", which strtok handles, but "C since1972.C" becomes "C since      C". The major issue is that digits are replaced by spaces, which is correct for separation, but the logic for extracting pure letter sequences is flawed in combination with how `strtok` and the rest of the code handle it. However, the primary logical error leading to the wrong output "sincec" is likely in the insertion/search logic or how words are tokenized. Let's look closer. "since1972.C" -> "since      C". strtok splits this into "since" and "C". This seems okay for separation. 
            }
        }
        w[x]='\0';
        if(x==0){
            continue;
        }
        char *w1 = strtok(w, " ");
    A:
        if (h != 0)
        {
            w1 = strtok(NULL, " ");
        }
        while (w1 != NULL) // 一行
        {
            h++;
            for (int i = 0; i < strlen(w1); i++)
            {
                if (w1[i] >= 'A' && w1[i] <= 'Z')
                {
                    w1[i] -= 'A' - 'a';
                }
            } // 预处理
            if (n == 0)
            {
                strcpy(head->word, w1);
                head->num = 0; // @@ The count for the first word is initialized to 0 instead of 1. It should be 1 because the word has been encountered once.
                n = 1;
            }
            p = (struct article *)malloc(sizeof(struct article)); // @@ Memory leak: memory is allocated here but immediately overwritten in the next line.
            p = head;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(w1, p->word) == 0)
                {
                    p->num++;
                    goto A;
                }
                p = p->next;
            } // 已有中寻找
            p = head;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(w1, head->word) < 0)
                {
                    q = (struct article *)malloc(sizeof(struct article));
                    strcpy(q->word, w1);
                    q->num = 1;
                    q->next = head;
                    head = q;
                    n++;
                    goto A;
                }
                else if (strcmp(w1, p->word) < 0) // @@ Logic Error: This condition checks if w1 is less than the current p->word. However, p is iterating from head. If w1 is greater than head but less than some subsequent node, this block attempts to insert. But the loop structure is flawed. It iterates through the list, but the conditions inside don't correctly identify the insertion point for a sorted list in all cases, especially combined with the `goto A`. Specifically, if `w1` is not less than `head->word`, it enters the loop. Inside, if `w1 < p->word`, it tries to insert before `p`. But `p` starts at `head`. If `w1 > head->word`, the first `if` fails. The `else if` checks `w1 < p->word`. If `p` is `head`, this is redundant with the first `if`. As `p` moves, this checks if `w1` belongs before `p`. This is standard sorted insertion logic, BUT the loop continues to increment `p` regardless. The `goto A` breaks out. The issue is likely that the loop doesn't correctly handle the case where the word should be appended or inserted in the middle correctly due to `p` advancement and index `i` mismatch. 
                {
                    q = (struct article *)malloc(sizeof(struct article));
                    strcpy(q->word, w1);
                    q->num = 1;
                    p = head; // @@ Logic Error: `p` is reset to head here, but the loop variable `i` and the outer loop context are messed up. The inner loop `for (int j = 0; j < i - 1; j++)` tries to find the predecessor. If `i` is the index where `w1 < p->word` was found, we need to insert before `p`. The predecessor is at `i-1`. This logic is fragile and incorrect because `p` was modified in the previous search loop and then reset. 
                    for (int j = 0; j < i - 1; j++)
                    {
                        p = p->next;
                    }
                    q->next = p->next;
                    p->next = q;
                    n++;
                    goto A;
                }
                else if (strcmp(w1, tail->word) > 0)
                {
                    q = (struct article *)malloc(sizeof(struct article));
                    strcpy(q->word, w1);
                    q->num = 1;
                    tail->next = q;
                    tail = q;
                    n++;
                    goto A;
                }
                p = p->next;
            } // 创建新的word
        }
    }
    fclose(IN);
    p = head;
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", p->word, p->num);
        p = p->next;
    }
    return 0;
}