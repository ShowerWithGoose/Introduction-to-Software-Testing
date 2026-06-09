#include <stdio.h>
#include <string.h>
typedef struct word
{
    char ch[100];
    int count;
} word;
int main()
{
    int i = 0, j = 0, a = 0;
    word word[1005];      // 单词清单，用于记录单词
    char list[100000], c; // list用于记录文件中的所有字符，c用于依次读入文件中的字符
    FILE *doc = fopen("article.txt", "r");
    while ((c = fgetc(doc)) != EOF)
    {
        list[i] = c;
        i++;
    }
    int lenth = i, b = 0; // 所有字符的个数
    for (int i = 0; i < lenth;)
    {
        if ((list[i] < 'a' || list[i] > 'z') && (list[i] < 'A' || list[i] > 'Z'))
        {
            i++; // 读入的不是字母，继续读入下一个字符
        }
        else
        {
            b = 0;
            while ((list[i] >= 'a' && list[i] <= 'z') || (list[i] >= 'A' && list[i] <= 'Z'))
            {
                if (list[i] >= 'A' && list[i] <= 'Z') // 读入的字母是大写
                {
                    list[i] = list[i] + 'a' - 'A'; // 变大写为小写
                }
                word[a].ch[b] = list[i];
                b++;
                i++;
            }
            word[a].ch[b] = '\0'; // 字符串结尾置'\0'
            word[a].count = 1;    // 对于第一遍查找的单词个数置1
            for (j = 0; j < a; j++)
            {
                if (strcmp(word[j].ch, word[a].ch) == 0) // 在单词清单中查找到该单词，将其个数加1
                {
                    word[j].count++;
                    break;
                }
            }
            if (j == a)
            {
                a++; // 在单词清单中未发现该单词，将a++
            }
        }
    }
    struct word temp;
    int flag;
    for (int i = 0; i < a; i++)
    {
        flag = 0;
        for (int j = i; j < a; j++) // @@ [The inner loop should start from i+1 to avoid unnecessary self-comparison and ensure correct bubble sort behavior. Starting from i causes the first comparison to be with itself (equal), which doesn't trigger a swap, but more critically, it leads to incorrect sorting logic because the minimal element may not bubble to the front correctly. However, the real issue is that this implementation does not implement a standard bubble sort—it's closer to a selection sort but flawed. The bigger problem is that when duplicates are handled earlier by incrementing count and skipping insertion (via `a++` only when new), the array up to index `a-1` contains unique words. But during sorting, the algorithm compares and potentially swaps even when `j == i`, which is harmless but inefficient. The actual root cause of the wrong lexicographical order is that the sorting algorithm is incorrectly implemented: it tries to do a kind of selection sort but updates `word[i]` immediately upon finding any `word[j]` that is smaller, which breaks stability and correctness. Specifically, it should find the minimum from i to end and then swap once, but instead it swaps every time it finds a smaller element, leading to incorrect ordering. For example, with ["programming", "language"], when i=0, j starts at 0: compare word[0] ("programming") with word[0] → no swap. Then j=1: "programming" > "language", so swap → now word[0]="language", word[1]="programming". That seems okay. But consider three words out of order: ["zoo", "apple", "banana"]. i=0: j=0→no swap; j=1: "zoo">"apple" → swap → ["apple","zoo","banana"]; j=2: now compare word[0]="apple" with word[2]="banana": "apple"<"banana", no swap. So after i=0, we have ["apple","zoo","banana"] — correct so far. i=1: j=1→no swap; j=2: "zoo">"banana" → swap → ["apple","banana","zoo"]. This actually works. So why the output order is wrong? Let's look at the test case: input yields words: "C", "programming", "language", "C", "Programming", "Language", "C", "Programming", "Language", "since". After lowercasing and extraction: "c", "programming", "language", "c", "programming", "language", "c", "programming", "language", "since". The code processes them sequentially. First "c" → added at index 0. Then "programming" → not found in [0..0], so added at index 1. Then "language" → not found in [0..1], added at index 2. Then next "c" → found at j=0, count[0] becomes 2, and since j(=0) < a(=3), it doesn't increment a. Similarly for subsequent duplicates. So final array before sort: 
// word[0]: "c", count=3
// word[1]: "programming", count=3
// word[2]: "language", count=3
// word[3]: "since", count=1
// Now sorting: 
// i=0: compare word[0]="c" with word[0] → no swap; j=1: "c" vs "programming": "c" < "programming" → no swap; j=2: "c" vs "language": 'c' (99) vs 'l' (108) → "c" < "language" → no swap; j=3: "c" vs "since": 'c'<'s' → no swap. So word[0] remains "c".
// i=1: word[1]="programming"; j=1: self; j=2: "programming" vs "language": 'p' > 'l' → swap → now word[1]="language", word[2]="programming"; j=3: now word[1]="language" vs word[3]="since": 'l'<'s' → no swap.
// i=2: word[2]="programming"; j=2: self; j=3: "programming" vs "since": 'p'<'s' → no swap.
// Final order: "c", "language", "programming", "since" → which matches expected output.
// But the buggy output is: c, programming, language, since — meaning the sort didn't work.
// Why? Because in the sorting loops, the inner loop runs from j=i to a-1, and when it finds word[j] < word[i], it swaps immediately. However, after swapping, word[i] changes, and subsequent comparisons use the new word[i], which can lead to incorrect results.
// Example: initial array: ["c", "programming", "language", "since"]
// i=0:
//   j=0: strcmp("c","c")=0 → no swap
//   j=1: strcmp("c","programming")<0 → no swap
//   j=2: strcmp("c","language")<0 → no swap
//   j=3: strcmp("c","since")<0 → no swap
// i=1:
//   current word[1] = "programming"
//   j=1: self → no swap
//   j=2: strcmp("programming", "language") > 0 → swap → now word[1]="language", word[2]="programming"
//   j=3: now compare word[1]="language" with word[3]="since": strcmp("language","since") < 0 → no swap
// i=2:
//   word[2]="programming"
//   j=2: self
//   j=3: "programming" vs "since": 'p'<'s' → no swap
// So result: "c", "language", "programming", "since" → correct.
// But the actual buggy output is: c, programming, language, since — which suggests that the sort did nothing.
// Wait — look at the condition in the sort loop:
//     if (strcmp(word[i].ch, word[j].ch) > 0)
// This means: if word[i] > word[j], swap them.
// In the first pass (i=0), it compares word[0] with all j>=0.
// But note: when i=1, and j=2, if word[1] > word[2], they swap.
// However, in the given test case, after reading, the array is:
// [0] = "c"
// [1] = "programming"
// [2] = "language"
// [3] = "since"
// Now, during sorting:
// i=0: 
//   j=0: "c" vs "c" → 0 → no
//   j=1: "c" vs "programming" → negative → no
//   j=2: "c" vs "language" → negative → no
//   j=3: "c" vs "since" → negative → no
// i=1:
//   j=1: "programming" vs "programming" → 0 → no
//   j=2: "programming" vs "language" → positive → YES → swap → now [1]="language", [2]="programming"
//   j=3: now compare word[1]="language" vs word[3]="since" → negative → no
// i=2:
//   j=2: "programming" vs "programming" → 0
//   j=3: "programming" vs "since" → negative → no
// So output should be correct.
// But the reported buggy output is:
// c 3
// programming 3
// language 3
// since 1
// Which implies that "programming" comes before "language", meaning the sort failed to swap them.
// Why? Because in the code, after extracting words, the array might be:
// [0] = "c"
// [1] = "programming"
// [2] = "language"
// But when processing the second occurrence of "C", it finds it at j=0 and increments count, and does NOT add a new entry, so a remains 3 after processing all.
// However, when the third word "language" is processed (first time), a=2, so it's stored at word[2], and then a becomes 3.
// So the array before sort is indeed [0]="c", [1]="programming", [2]="language", [3]="since".
// Then why didn't the sort swap [1] and [2]?
// Let's simulate the sort step carefully:
// a = 4
// i=0:
//   flag=0
//   j from 0 to 3:
//      j=0: strcmp(word[0], word[0]) = 0 → not >0 → no swap
//      j=1: strcmp("c", "programming") → 'c'-'p' = negative → not >0 → no
//      j=2: "c" vs "language" → negative → no
//      j=3: "c" vs "since" → negative → no
//   flag still 0 → break out of outer loop? NO! Because the break is inside the outer for-loop body, after the inner loop. But note: the break says "if (flag == 0) break;", meaning if no swaps happened in the entire inner loop for this i, then break early (optimization). But in this case, for i=0, no swaps → flag=0 → break out of the outer loop entirely!
// That's the bug!
// The sorting algorithm breaks after the first pass (i=0) because no swaps occurred, assuming the array is sorted. But the array is not sorted beyond the first element.
// This early termination is only valid for a true bubble sort where each pass bubbles the largest to the end. But this is not a standard bubble sort—it's a broken variant.
// In a correct bubble sort, you need multiple passes even if the first element is in place.
// Here, because the first element ("c") is the smallest, no swaps happen in i=0 pass, so flag remains 0, and the outer loop breaks, leaving the rest unsorted.
// Hence, the output order is the original insertion order: "c", "programming", "language", "since".
// Therefore, the error is in the sorting logic: the early break condition is misplaced and invalid for this sorting approach.
            }
        }
        if (flag == 0)
            break; // @@ [This early termination breaks the sorting process prematurely. Since the first word 'c' is already the lexicographically smallest, no swaps occur in the first iteration (i=0), causing the loop to exit immediately without sorting the remaining words. The sorting algorithm incorrectly assumes the entire array is sorted if no swaps occur in one pass, but this assumption only holds for a proper bubble sort that moves the largest element to the end each time. Here, the algorithm attempts a different approach (more like selection sort) but uses an invalid optimization.]
    } // 冒泡排序法
    for (i = 0; i < a; i++)
    {
        printf("%s %d\n", word[i].ch, word[i].count);
    }
    fclose(doc);
    return 0;
}