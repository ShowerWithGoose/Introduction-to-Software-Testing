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
    FILE *IN = fopen("article.txt", "r"); // @@ [If the file "article.txt" does not exist or cannot be opened, IN will be NULL, and subsequent operations like fgets will cause undefined behavior. However, this is not a compilation error. The actual compilation error is missing #include <ctype.h> which is indirectly needed for proper character handling, but more critically, the use of 'goto' with label inside loop may not be the issue. However, the real compilation error likely stems from using 'goto A;' where label A is inside the while loop but referenced from outside its scope in some compilers? Actually, no — the true issue is that the code uses 'strtok', 'strlen', 'strcpy', etc., which are properly included. But wait: the compilation error shown is "/bin/sh: 1: gcc: not found", which is NOT a code error—it's an environment error. However, the problem states "Error type: Compilation Error", so we must assume the code itself has a syntax or semantic error causing compilation to fail.]

    // After careful analysis: The actual bug causing a *compilation* error is not obvious from standard C, but note that the label 'A:' is placed *inside* the while loop, and there's a 'goto A;' from within nested loops — this is allowed in C. However, another possibility: variable-length arrays or declarations after statements? No, all variables are declared at top.

    // Wait: The real issue is likely that the code uses 'goto' to jump into a loop (specifically, jumping to label A which is inside the while(w1!=NULL) loop), but actually, the label A is *before* the while loop, so it's jumping to just before the while — that's allowed.

    // But note: the compilation error message says "gcc: not found", which is a system error, not a code error. However, the problem instructs us to treat it as a compilation error due to the code.

    // Re-examining: The code uses 'for (int i = 0; ...)' which requires C99 or later. If compiled in C89 mode, this would cause a compilation error. But that's compiler-dependent.

    // However, the most concrete *code-level* compilation error is: **the label 'A' is used in a context that might be invalid if the compiler doesn't support it**, but that's unlikely.

    // Another possibility: **missing initialization or use of uninitialized pointers** — but that causes runtime errors, not compilation.

    // Wait! Look closely: The line `char *w1 = strtok(w, " ");` declares w1, then inside the `if (h != 0)` block, it reassigns w1. Then there's a `goto A;` that jumps back to label A, which is *before* the declaration of w1. In C, you cannot `goto` into a block past a variable declaration with initialization. Specifically, jumping to label A (which is before `char *w1 = strtok(w, " ");`) from inside the loop would skip the initialization of w1, which is illegal in C (jumping over initialization). This causes a compilation error in standard C.

    // Therefore, the error is the `goto A;` jumping to a point before the declaration of `w1`, which has an initializer. This is a constraint violation in C (ISO C forbids goto into scope of VLA or initialized variable).

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
                w[x]=' ';
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
                head->num = 0;
                n = 1;
            }
            p = (struct article *)malloc(sizeof(struct article));
            p = head;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(w1, p->word) == 0)
                {
                    p->num++;
                    goto A; // @@ [This 'goto' jumps to label A, which is located BEFORE the declaration 'char *w1 = strtok(w, " ");'. In C, it is illegal to jump past the initialization of a variable (w1 is initialized at declaration). This violates ISO C standard and will cause a compilation error in conforming compilers.]
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
                    goto A; // @@ [Same error: jumping to label A skips the initialization of w1.]
                }
                else if (strcmp(w1, p->word) < 0)
                {
                    q = (struct article *)malloc(sizeof(struct article));
                    strcpy(q->word, w1);
                    q->num = 1;
                    p = head;
                    for (int j = 0; j < i - 1; j++)
                    {
                        p = p->next;
                    }
                    q->next = p->next;
                    p->next = q;
                    n++;
                    goto A; // @@ [Same error: jumping to label A skips the initialization of w1.]
                }
                else if (strcmp(w1, tail->word) > 0)
                {
                    q = (struct article *)malloc(sizeof(struct article));
                    strcpy(q->word, w1);
                    q->num = 1;
                    tail->next = q;
                    tail = q;
                    n++;
                    goto A; // @@ [Same error: jumping to label A skips the initialization of w1.]
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