#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<string.h>
#include <stdio.h>
struct word {
    char name[100];
    int num;
    int turn;
}a[1000];
char s[100];   char ss[100];
int main()
{
    FILE* p;
    p = fopen("article.txt", "r");
    int l1, i, j = 0, k = 0, cnt = 0, t;
    while (fgets(s,sizeof(s),p) != NULL)
    {
        l1 = strlen(s);
        for (i = 0; i < l1; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
        }
        for (i = 0; i < l1; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                a[k].name[j] = s[i];
                j++;
            }
            else if (s[i] == ' '||s[i]=='.'||s[i]==';') // @@ The condition for detecting word boundaries is incomplete. It only handles spaces, dots, and semicolons, but fails to handle other punctuation marks, digits, or newlines (\n) present in the input. This causes words separated by other characters (like digits in "1970" or newlines) to be merged or processed incorrectly, leading to wrong word extraction and counts.
            {
                a[k].num += 1; // @@ Logic error: `a[k].num` is incremented here as if counting occurrences, but it should just mark that a word has ended. The actual counting logic later assumes `num` holds the count of this specific instance (usually 1), but this line adds 1 for every delimiter, which is conceptually mixed up with the final aggregation. More critically, if the previous character was not a letter, this might create empty words or misalign indices. However, the primary issue causing WA is the boundary detection above.
                cnt += 1;
                k += 1;
                j = 0;
            }
            else
                continue;
        }
        memset(s, 0, sizeof(s));
    }
    // @@ Missing handling for the last word in the file if it doesn't end with a delimiter handled above (e.g., if file ends with a letter). The loop finishes without saving the last accumulated word in `a[k]`.
    for (i = 0; i < cnt; i++)
    {
        for (j = cnt ; j > i; j--) // @@ Loop boundary error: `j` starts at `cnt`, which is out of bounds for array `a` (valid indices 0 to cnt-1). Accessing `a[j]` when `j==cnt` reads uninitialized memory, leading to undefined behavior and incorrect comparisons. It should start at `cnt - 1`.
        {
            if (strcmp(a[i].name, a[j].name) == 0)
            {
                a[i].num += a[j].num;
                a[j].num = 0;
            }
        }
    }
    for (j = 0; j < cnt; j++)
    {
        for (i = 0; i < cnt - 1; i++)
        {
            if (strcmp(a[i].name, a[i + 1].name) > 0)
            {
                strcpy(ss, a[i].name);    t = a[i].num;
                strcpy(a[i].name, a[i + 1].name);    a[i].num = a[i + 1].num;
                strcpy(a[i + 1].name, ss);    a[i + 1].num = t;
            }
        }
    }
    for (i = 0; i < cnt; i++)
    {
        if (a[i].num != 0)
            printf("%s %d\n", a[i].name, a[i].num);
    }
    fclose(p);
}