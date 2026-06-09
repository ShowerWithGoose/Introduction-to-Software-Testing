#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node *List;
typedef List Position;
struct node
{
    char *word;
    int count;
    Position next;
};
void Insert(List L, char *word, int len)
{
    Position P = L->next;
    while (P != NULL)
    {
        if (strcmp(P->word, word) == 0)
        {
            P->count++;
            return;
        }
        P = P->next;
    }
    Position T = (Position)malloc(sizeof(struct node));
    T->word = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(T->word, word);
    T->count = 1;

    P = L->next;
    if (P == NULL)
    {
        T->next = NULL;
        L->next = T;
        return;
    }
    if (strcmp(P->word, word) > 0)
    {
        T->next = P;
        L->next = T;
        return;
    }
    while (P != NULL)
    {
        if (P->next == NULL && strcmp(P->word, word) < 0)
        {
            T->next = NULL;
            P->next = T;
            return;
        }
        else if (strcmp(P->word, word) < 0 && strcmp(P->next->word, word) > 0) // @@ Accessing P->next->word when P->next might be NULL causes undefined behavior or crash, and the logic fails to insert at the end correctly if the loop terminates without finding a spot. The condition `P->next == NULL` is handled in the previous `if`, but if that `if` is false (meaning `strcmp(P->word, word) >= 0` which contradicts the outer context or implies equality handled earlier), this logic is flawed. More critically, if the list is not sorted initially or insertion logic doesn't maintain sort order strictly during traversal, this fails. However, the primary logical error here is that if `P->next` is not NULL, we access `P->next->word`. If the word should be inserted after the last element, the first `if` inside this loop handles it. But if the loop continues, it assumes `P->next` exists. The real issue is that this insertion logic is overly complex and buggy for maintaining a sorted list. A simpler traversal with a `prev` pointer is standard. But specifically, if `P->next` is NULL, the first `if` catches it. If `P->next` is NOT NULL, it accesses `P->next->word`. This part is technically safe from NULL dereference here, BUT the logic `strcmp(P->word, word) < 0 && strcmp(P->next->word, word) > 0` misses the case where the new word is equal to `P->next->word` (should have been caught earlier) or if the sorting invariant is broken. The biggest issue is actually that the code does not handle the case where the word falls between `P` and `P->next` correctly if `P` advances past the correct spot without triggering the condition. Wait, if `P` advances, it means `strcmp(P->word, word) < 0` was true (otherwise it would have been inserted before or at P). So we are looking for the first `P->next` such that `P->next->word > word`. This logic seems ostensibly correct for sorted insertion IF the list is sorted. However, there is a subtle bug: if `P->next` is NULL, the first `if` handles it. If `P->next` is not NULL, it checks. If neither condition is met, it means `strcmp(P->next->word, word) <= 0`. If it's `< 0`, we need to advance. If it's `== 0`, it should have been found in the initial scan. So if we reach here, `P->next->word` must be `< word`? No, if `P->next->word < word`, we should advance. The current code only advances if the `else if` is false. If `strcmp(P->next->word, word) < 0`, the `else if` is false, so it advances. This seems logically okay for insertion. 
        // HOWEVER, the major error causing "Wrong Answer" or "File not found" is likely the file path.
        // Let's look at main.
        {
            T->next = P->next;
            P->next = T;
            return;
        }
        P = P->next;
    }

    return;
}
int main()
{
    char str[100];
    FILE *fp;
    if ((fp = fopen("C:/Users/abcde/Desktop/vscode-c/test/c/homework-three/five/article.txt", "r")) == NULL) // @@ The problem states the file is named "article.txt" located in the current directory. Using an absolute path specific to the developer's machine will cause "File not found" on the judging system. It should be fopen("article.txt", "r").
    {
        printf("File not found");
        return 0;
    }

    char c;
    int i = 0;
    List L = (List)malloc(sizeof(struct node));
    L->next = NULL;
    while ((c = fgetc(fp)) != EOF)
    {
        if (isalpha(c))
        {
            str[i++] = tolower(c);
        }
        if (!isalpha(c) && i > 0)
        {
            int len = 0;
            str[i] = '\0';

            len = strlen(str);

            Insert(L, str, len);
            i = 0;
            str[0] = '\0';
        }
    }
    Position P = L->next;
    while (P != NULL)
    {
        printf("%s %d\n", P->word, P->count);
        P = P->next;
    }
    fclose(fp);

    return 0;
}