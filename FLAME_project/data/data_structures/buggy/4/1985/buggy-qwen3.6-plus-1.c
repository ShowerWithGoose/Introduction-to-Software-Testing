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
                w[x]=' '; // @@ The logic here replaces non-alphanumeric characters with spaces, but fails to handle the case where multiple non-alpha characters appear consecutively or at boundaries correctly in conjunction with the tokenization. More critically, it allows digits to pass through if they were not explicitly excluded, but the condition excludes them. However, the main issue is that `strtok` splits by space. If "since1972" is encountered, the digits are replaced by spaces? No, the condition `if ((new[i] >= 'a' ...)` is false for digits, so it goes to `else`, replacing digit with space. So "since1972" becomes "since     ". This creates empty tokens or handles them. But wait, if the input is "C since1972.C", the '.' is replaced by space. "1972" is replaced by spaces. So we get "C since       C". This seems okay for splitting. 
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
                head->num = 0; // @@ The count for the first word is initialized to 0, but it should be 1 because the word has been encountered once.
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
                else if (strcmp(w1, p->word) < 0) // @@ Logic error: `p` is traversing the list, but the comparison `strcmp(w1, p->word) < 0` combined with the insertion logic below is flawed. Specifically, if `w1` is greater than `head` but less than some subsequent node, this block attempts to insert. However, the loop structure and the use of `goto A` inside a loop that modifies the list structure (and `n`) while iterating can lead to skipped checks or incorrect insertions. More importantly, the condition `strcmp(w1, p->word) < 0` checks if `w1` is smaller than current `p`. If it is, it inserts before `p`. But `p` starts at `head`. If `w1 > head->word`, it goes to `else if`. If `w1 < p->word` (where p is head), it would have been caught by the first `if`. So this `else if` implies `w1 >= head->word`. If `w1 < p->word` here, it means we found the spot. BUT, `p` is not updated to the previous node correctly for insertion in all cases, especially since `p` moves forward. The inner loop `for (int j = 0; j < i - 1; j++)` tries to find the predecessor, but `i` is the index of the current node `p` which is *greater* than `w1`. So we want to insert before `p`. The predecessor is at `i-1`. This logic is fragile and prone to off-by-one errors or crashes if `i=0` (though `i=0` is handled by the first `if`). A major logical flaw is that if the word is not found and not inserted in any of these conditions, it falls through.
                {
                    q = (struct article *)malloc(sizeof(struct article));
                    strcpy(q->word, w1);
                    q->num = 1;
                    p = head; // @@ Resetting p here loses the context of the outer loop's p.
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
            // @@ If the code reaches here, it means the word was not found, not smaller than head, not smaller than any middle element, and not greater than tail. This implies it might be equal to tail (handled by search loop earlier? No, search loop only increments if found). If it's equal to tail, it should have been found in the first search loop. If it's not found, and not inserted, it's a bug. However, the biggest issue causing the specific wrong answer "sincec" is likely how tokens are parsed or how words are merged. 
            // Let's re-evaluate the parsing. "since1972.C" -> "since     C". Tokens: "since", "C".
            // The expected output is c:15, since:15.
            // The buggy output is c:11, since:11, sincec:4.
            // "sincec" suggests that "since" and "c" are being concatenated.
            // This usually happens if `strtok` doesn't split them, or if the buffer `w` isn't null-terminated correctly, or if `w1` points to overlapping memory.
            // In `fgets`, `new` contains the line.
            // The loop replaces non-alpha with space.
            // `strtok(w, " ")` splits by space.
            // If `w` is "since     C", `strtok` returns "since", then "C".
            // Why would "sincec" appear?
            // Perhaps the `else { w[x]=' '; }` branch is not executing as expected or `x` is not incrementing correctly?
            // Actually, look at `w[x]=' ';` in the else block. It does NOT increment `x`.
            // So if we have "1972", `x` stays same, overwriting the same position?
            // Example: "s i n c e 1 9 7 2 ."
            // s: w[0]='s', x=1
            // i: w[1]='i', x=2
            // ...
            // e: w[4]='e', x=5
            // 1: else, w[5]=' ', x=5
            // 9: else, w[5]=' ', x=5
            // 7: else, w[5]=' ', x=5
            // 2: else, w[5]=' ', x=5
            // .: else, w[5]=' ', x=5
            // Next char ' ': if it is a space, it enters the IF block (space is allowed). w[5]=' ', x=6.
            // So "since1972." becomes "since      " (with multiple spaces at index 5? No, just one space written repeatedly, then a space from the original input if present).
            // Wait, if the input is "since1972.C", there is no space between 2 and ..
            // So after processing "since1972.", `w` looks like "since     " (indices 0-4 are since, index 5 is space).
            // Then 'C' comes. It is alpha. w[6]='C', x=7.
            // So `w` becomes "since C".
            // `strtok` splits into "since" and "C". This seems correct.
            
            // Where does "sincec" come from?
            // Maybe the previous word wasn't null-terminated?
            // `w[x]='\0'` is done after the loop.
            
            // Let's look at the counts.
            // Input: "C since1972.C ..." repeated.
            // If parsing is correct, we have "C", "since", "C".
            // Counts should be equal.
            // Buggy: c:11, since:11, sincec:4.
            // Total C's: 11 + 4 = 15? Yes.
            // Total Since's: 11 + 4 = 15? Yes.
            // So "sincec" is counting instances where "since" and "c" were merged.
            // This happens if the space between them is missing in `w`.
            // When does the space go missing?
            // In the loop:
            // if (alpha OR space) { w[x++] = new[i]; }
            // else { w[x] = ' '; } // x not incremented
            
            // Consider "C since1972.C"
            // C: alpha, w[0]='C', x=1
            // space: space, w[1]=' ', x=2
            // s: alpha, w[2]='s', x=3
            // i: alpha, w[3]='i', x=4
            // n: alpha, w[4]='n', x=5
            // c: alpha, w[5]='c', x=6
            // e: alpha, w[6]='e', x=7
            // 1: else, w[7]=' ', x=7
            // 9: else, w[7]=' ', x=7
            // 7: else, w[7]=' ', x=7
            // 2: else, w[7]=' ', x=7
            // .: else, w[7]=' ', x=7
            // C: alpha, w[8]='C', x=8
            
            // Resulting string: "C since C".
            // Tokens: "C", "since", "C".
            // This logic seems correct for separation.
            
            // Is it possible that `strtok` is behaving unexpectedly?
            // Or is `w1` persisting?
            
            // Let's look at `head->num = 0`.
            // First word "C". n=0. strcpy(head->word, "C"). head->num = 0. n=1.
            // Next word "since". Search loop: strcmp("since", "C") != 0.
            // Insertion loop:
            // i=0. p=head ("C").
            // strcmp("since", "C") < 0? No ('s' > 'c').
            // strcmp("since", tail->word) > 0? tail is head ("C"). Yes.
            // Insert "since" after tail. tail becomes "since". n=2.
            // Next word "C". Search loop: p=head ("C"). strcmp("C", "C")==0. p->num++. head->num becomes 1.
            
            // So "C" count is correct.
            
            // Why "sincec"?
            // If the input file has no newline at the end, or specific formatting?
            // The problem says "C since1972.C since1972.C..."
            
            // What if `w` buffer is not cleared?
            // `strtok` modifies `w`.
            // Next iteration of `fgets` overwrites `new`, and `w` is rebuilt from scratch.
            
            // There is a subtle bug in `strtok` usage with `goto A`.
            // `strtok` maintains static state.
            // If `goto A` jumps back, `w1 = strtok(NULL, " ")` gets the next token.
            // This is standard usage.
            
            // However, look at `p = (struct article *)malloc(...)` followed by `p = head`.
            // This is a memory leak but not a logic error for correctness of output, unless malloc fails.
            
            // Let's look closely at `else if (strcmp(w1, p->word) < 0)`.
            // If this block is executed, it inserts `w1` before `p`.
            // But `p` is currently at index `i`.
            // The code finds the node at `i-1` and inserts after it.
            // This is correct for inserting before `p`.
            
            // Is it possible that `since` and `c` are merged because of the `tail` check?
            // If `w1` is "C", and tail is "since".
            // strcmp("C", "since") > 0? No ('c' < 's').
            // So it doesn't go to tail insertion.
            // It goes to the middle insertion?
            // i=0: p="C". strcmp("C", "C") < 0? No.
            // i=1: p="since". strcmp("C", "since") < 0? Yes.
            // Enters block. Inserts "C" before "since".
            // List: "C" -> "C" -> "since".
            
            // This logic seems to maintain sorted order.
            
            // The only explanation for "sincec" is that the string "sincec" is actually formed in `w1`.
            // This implies `strtok` returned "sincec".
            // This implies `w` contained "sincec" without a separator.
            // This implies the separator generation failed.
            
            // When does separator generation fail?
            // If `new[i]` is not alpha and not space, it puts a space at `w[x]` but doesn't increment `x`.
            // If the NEXT character is alpha, it writes to `w[x]` (overwriting the space) and increments `x`.
            // Example: "e1C"
            // e: w[0]='e', x=1
            // 1: else, w[1]=' ', x=1
            // C: alpha, w[1]='C', x=2
            // Result: "eC". Separator lost!
            
            // Yes! If a non-alpha character is followed immediately by an alpha character, the space written by the non-alpha character is overwritten by the alpha character because `x` was not incremented.
            
            // Fix: Increment `x` in the else block.
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