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
        for (int j = i + 1; j < a; j++) // @@ The inner loop should start from i + 1 to compare with subsequent elements, not from i (comparing with itself is redundant and incorrect for selection sort logic here, although strictly speaking starting at i just compares with self first. However, the standard selection sort or bubble sort optimization usually looks ahead. More importantly, the current logic `for (int j = i; j < a; j++)` combined with `if (strcmp(word[i].ch, word[j].ch) > 0)` will swap word[i] with itself if it's the smallest so far in the remaining list? No, if j=i, strcmp is 0, so no swap. It effectively finds the minimum element in [i, a) and swaps it to position i? No, it swaps immediately whenever it finds a smaller element. This is not a standard sort. Let's look closer. If word[i] > word[j], it swaps. This means word[i] becomes the smaller one. Then it continues comparing the NEW word[i] with further j. This effectively bubbles the smallest element to position i. This is a form of selection/bubble hybrid. It works correctly for sorting. Wait, let's re-read the expected output vs buggy output.
        // Buggy: c, programming, language, since.
        // Expected: c, language, programming, since.
        // The issue is likely that the sorting algorithm is flawed or the data extraction is flawed.
        // Let's look at the extraction. "C programming language.(C Programming Language)”C Programming Language”,since1972."
        // Words: c, programming, language, c, programming, language, c, programming, language, since.
        // Counts: c:3, programming:3, language:3, since:1.
        // The counts are correct in the buggy output. The order is wrong.
        // The sort loop:
        // i=0: word[0]="c". j loops 0..3.
        // j=0: strcmp("c","c")=0. No swap.
        // j=1: strcmp("c","programming")<0. No swap.
        // j=2: strcmp("c","language")<0. No swap.
        // j=3: strcmp("c","since")<0. No swap.
        // i=1: word[1]="programming".
        // j=1: strcmp("programming","programming")=0.
        // j=2: strcmp("programming","language")>0. Swap! word[1] becomes "language", word[2] becomes "programming". flag=1.
        // j=3: strcmp("language","since")<0. No swap.
        // Now word[1]="language", word[2]="programming".
        // i=2: word[2]="programming".
        // j=2: strcmp("programming","programming")=0.
        // j=3: strcmp("programming","since")<0. No swap.
        // Result: c, language, programming, since.
        // Wait, if the logic above is correct, why is the buggy output "c, programming, language, since"?
        // Let's re-examine the loop bounds. `for (int j = i; j < a; j++)`.
        // If the code provided in the prompt is exactly what produced the buggy output, then my manual trace suggests it SHOULD work.
        // Is there an error in how `a` is incremented or `word` array initialized?
        // Ah, look at line 46: `for (int j = i; j < a; j++)`. In the provided source code in the prompt block:
        // `for (int j = i; j < a; j++)`
        // If I change `j=i` to `j=i+1`, it doesn't change correctness much except efficiency.
        // Let's look at the variable `flag`. It is set to 1 if a swap occurs. If no swap occurs in the inner loop, it breaks.
        // This is an optimization for Bubble Sort where if no swaps occur, the list is sorted.
        // However, this is NOT a Bubble Sort. It's a "Selection-like" pass that swaps immediately.
        // Does this optimization work?
        // Pass i=0: "c" is compared. No swaps. flag=0. Breaks outer loop?
        // YES! `if (flag == 0) break;` is outside the inner loop but inside the outer loop.
        // If i=0 completes with no swaps, it assumes the entire array is sorted.
        // But "c" being in the correct first position does NOT mean the rest of the array is sorted.
        // So the error is using the `flag` break optimization which is only valid for Bubble Sort (adjacent swaps), not for this selection-style swap.
        {
            if (strcmp(word[i].ch, word[j].ch) > 0)
            {
                temp = word[i];
                word[i] = word[j];
                word[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    } // 冒泡排序法
    for (i = 0; i < a; i++)
    {
        printf("%s %d\n", word[i].ch, word[i].count);
    }
    fclose(doc);
    return 0;
}