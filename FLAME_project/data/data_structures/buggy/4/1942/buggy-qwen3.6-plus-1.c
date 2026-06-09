#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct danci {
    char word[100];
    int number;
} list[100];

int cmp(const void *a, const void *b) {
    struct danci aa = *((struct danci *)a);
    struct danci bb = *((struct danci *)b);
    if (strcmp(aa.word, bb.word) >= 0)
        return 1;
    else
        return -1;
}
char ch;
char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) {
        if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
            if ('A' <= ch && ch <= 'Z')
                ch = ch - ('A' - 'a');
            linshi[j] = ch;
            j++;
        } else {
            if (j == 0)
                continue;
            else {
                for (x = 0; x < j; x++)
                    list[i].word[x] = linshi[x];
                j = 0;
                list[i].word[x] = '\0';
                list[i].number = 0; // @@ The 'number' field is not initialized to 0 when a new word is added. Since the struct is global, it might be 0, but relying on implicit initialization is risky, and more importantly, the logic below adds 1 to the count during printing. If we initialize to 0 here, the final print logic needs to match. However, the main bug is in the counting logic.
                i++;
            }
        }
    }
    if (j != 0) {
        for ( x = 0; x < j; x++) {
            list[i].word[x] = linshi[x];
        }
        list[i].word[x] = '\0';
        list[i].number = 0; // @@ Same as above, initialization missing.
        i++;
    }
    qsort(list, i, sizeof(struct danci), cmp);
    for (int x = 0; x < i - 1; x++) {
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++;
            list[x + 1].word[0] = '}';
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ The counting logic is flawed. It only increments count when duplicates are found adjacent after sorting, but it initializes counts to 0 (implicitly or explicitly). If a word appears 3 times, e.g., "do", the first pass finds pair 1-2, increments list[0].number to 1. Then it marks list[1] as invalid and resorts. The third "do" is now at index 1. The loop continues. But the logic `list[x].number++` only counts the *merge* events, not the total occurrences. Specifically, if we have 3 identical words, we merge two into one (count becomes 1+1=2? No, init 0, ++ makes 1). Then we have 2 items left. We merge again? The logic is extremely fragile and incorrect for counts > 2. A standard approach is to initialize count to 1 and increment when merging, or simply iterate and count. Here, `number` starts at 0. When two match, `list[x].number` becomes 1. This represents 2 words? No, it's just a counter of merges. Finally, `+1` is added. So 1 merge -> 1+1=2. Correct for 2 words. For 3 words: First merge (words 1&2) -> count 1. Resort. Word 3 is next to merged word. Second merge -> count 2. Print 2+1=3. This seems logically okay for the count IF the merge happens correctly. HOWEVER, the issue is that `list[x+1]` is marked with '}' which sorts it to the end. But `i` is decremented. The `qsort` sorts `i` elements. The element marked with '}' is still in the array but effectively moved to the end of the valid range? No, `qsort` sorts the whole block. The '}' character is large, so it goes to the end. Then `i--` reduces the considered size. This *might* work. 
        // Let's re-evaluate the failure. "do" appears 3 times. "you" appears 3 times.
        // Input: "do ... do ... do".
        // Sorted: do, do, do.
        // x=0: list[0]==list[1]. list[0].num becomes 1. list[1] becomes '}'. i becomes 2. x becomes -1 (then 0).
        // Array state roughly: [do(num=1), }, do(num=0)]. Sorted by cmp: '}' is large. 
        // Wait, cmp returns 1 if aa >= bb. This is not a strict weak ordering if equal returns 1. It should return 0 for equal. This can cause undefined behavior in qsort.
        // But let's look at the output. "do 2" instead of "do 3".
        // If the sort is unstable or incorrect due to cmp, duplicates might not be adjacent.
        // Also, `list[x+1].word[0] = '}'` modifies the word. When it is sorted again, it moves.
        // The primary error is likely the `cmp` function returning 1 for equal elements, violating qsort requirements, leading to incorrect sorting and thus incorrect grouping.
        // Additionally, the counting logic `list[x].number++` relies on finding adjacent duplicates. If sorting fails, they aren't adjacent.
        
    return 0;
}