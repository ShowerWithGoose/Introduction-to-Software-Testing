#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define maxn 100005

typedef struct STRING {struct STRING *ne; int num; char s[99];} string;
string l[maxn], *head = l;
int stn;
int main(void)
{
    FILE *IN = fopen("article.txt", "r");
    char c, str[99], sn = 0;
    while (~(c = fgetc(IN))) {
        if (isalpha(c)) str[sn++] = tolower(c);
        else {
            if (!sn) continue;
            string *s = head;
            while (s != l && strcmp(s->s, str) < 0) s = s->ne; // @@ The linked list traversal logic is incorrect. The condition `s != l` should be `s != l + stn + 1` or similar to check the end of allocated nodes, and the comparison `strcmp(s->s, str) < 0` may cause infinite loop or incorrect insertion because the list is not sorted properly.
            if (!strcmp(s->s, str)) ++(s->num);
            else {
                l[++stn] = (string) {s, 1};
                strcpy(l[stn].s, str);
                if (s == head) head = l + stn;
                else {
                    string *i;
                    for (i = head; i->ne != s; i = i->ne); // @@ This loop may never terminate if `s` is not in the list (e.g., when `s` points to `l` which is a sentinel but not part of the linked chain), causing undefined behavior.
                    i->ne = l + stn;
                }
            }
            memset(str, 0, sizeof(str));
            sn = 0;
        }
    }
    for (string *i = head; i != l; i = i->ne)
        printf("%s %d\n\n", i->s, i->num); // @@ The output format is incorrect. It prints two newlines instead of one, and does not match the required format "word count\n". Also, the count should not be incremented by 1 as in the reference program.
    fclose(IN);
    return 0;
}