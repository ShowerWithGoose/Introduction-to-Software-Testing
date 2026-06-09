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
                list[i].number = 0; // @@ The 'number' field of the struct is not initialized. Since it is a global array, it is technically zero-initialized, but relying on this without explicit initialization in the logic flow where words are added is risky and bad practice. More importantly, the final print adds 1, implying counts start at 0. If this was local memory, it would be garbage. Given it's global, it's 0. However, the logic error is elsewhere.
                i++;
            }
        }
    }
    if (j != 0) {
        for ( x = 0; x < j; x++) {
            list[i].word[x] = linshi[x];
        }
        list[i].word[x] = '\0';
        list[i].number = 0; // @@ Same as above, explicit initialization is safer/clearer, though global vars are 0.
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
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ The counting logic is flawed. When duplicates are found, only one count is incremented (list[x].number++), and the duplicate is marked invalid. This means if a word appears 3 times, it is found as a duplicate twice. The first time, number becomes 1. The second time, number becomes 2. The output prints number + 1, which is 3. This seems correct for the count. HOWEVER, look at the test case: 'do' appears 3 times. 'you' appears 3 times. The buggy output shows 'do 2' and 'you 2'. Why? 
        // Let's trace 'do'. 
        // 1. 'do' is read. list[0] = "do", num=0.
        // 2. 'more' is read. list[1] = "more", num=0.
        // ...
        // After reading all words, we have unsorted list.
        // Then qsort.
        // Then the loop merges duplicates.
        // If 'do' appears 3 times, after sorting we have "do", "do", "do".
        // x=0: list[0]=="do", list[1]=="do". Match. list[0].num becomes 1. list[1] invalidated. qsort. i becomes N-1. x becomes -1 -> 0.
        // Now list is re-sorted. The valid "do" is at some index, say 0. The other "do"s are gone/invalidated.
        // Wait, the qsort moves the invalidated entry (starting with '}') to the end or beginning? '}' is ASCII 125. 'a' is 97. So '}' is greater. It goes to the end.
        // So if we had "do", "do", "do". 
        // Iter 1: Compare list[0] ("do") and list[1] ("do"). Match. list[0].num = 1. list[1] becomes "}o". qsort. 
        // Array becomes: "do", "do", "}o". (Assuming stable sort or similar positions). 
        // i becomes 2. x becomes -1, then increments to 0.
        // Iter 2: x=0. Compare list[0] ("do") and list[1] ("do"). Match. list[0].num = 2. list[1] becomes "}o". qsort.
        // Array becomes: "do", "}o", "}o".
        // i becomes 1. x becomes -1, then increments to 0.
        // Loop condition x < i - 1 => 0 < 0 is false. Loop ends.
        // Print: list[0].word ("do"), list[0].number + 1 => 2 + 1 = 3.
        // So why is the output 2?
        
        // Let's look at the Buggy Output again.
        // do 2
        // you 2
        
        // Expected:
        // do 3
        // you 3
        
        // My trace suggests it should be 3. Is there an issue with how `number` is initialized?
        // Global variables are initialized to 0. So `number` starts at 0.
        
        // Let's re-read the code carefully.
        // `list[i].number` is NEVER explicitly set to 0 in the insertion loop.
        // But it is global, so it is 0.
        
        // Is it possible that `qsort` behavior or the comparison function is unstable or incorrect?
        // cmp returns 1 if >= 0. This is not a strict weak ordering if equal elements return 1? 
        // Standard cmp should return 0 for equal.
        // if (strcmp(aa.word, bb.word) >= 0) return 1; else return -1;
        // If aa == bb, it returns 1. This tells qsort that aa > bb.
        // If we swap them, and compare again, bb == aa, returns 1. Tells qsort bb > aa.
        // This violates the requirements for qsort comparator (must return 0 for equal).
        // This can cause undefined behavior or incorrect sorting/merging.
        
        // If the sort is unstable or incorrect, duplicates might not be adjacent?
        // Or the merging logic fails.
        
        // The primary error is likely the Comparator Function returning 1 instead of 0 for equal strings.
        
        return 0;
}