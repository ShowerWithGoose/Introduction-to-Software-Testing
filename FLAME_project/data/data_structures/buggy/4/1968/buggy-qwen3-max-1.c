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
    while (~(c = fgetc(IN))) { // @@ [The expression ~(c = fgetc(IN)) is incorrect. fgetc returns EOF (typically -1) on end-of-file, and ~(-1) is 0, which breaks the loop correctly, but the issue is that 'c' is declared as char, not int. When fgetc returns a value like 0xFF (which is valid for extended ASCII), if char is signed, it becomes -1, which equals EOF, causing premature termination. Also, using char for fgetc result is unsafe.]
        if (isalpha(c)) str[sn++] = tolower(c);
        else {
            if (!sn) continue;
            string *s = head;
            while (s != l && strcmp(s->s, str) < 0) s = s->ne;
            if (!strcmp(s->s, str)) ++(s->num);
            else {
                l[++stn] = (string) {s, 1}; // @@ [This initializes .ne to 's', but does not set the previous node's next pointer correctly in all cases. Also, the list initialization is flawed: 'head' starts pointing to l[0], which is uninitialized, and l[0].s is empty, leading to incorrect comparisons.]
                strcpy(l[stn].s, str);
                if (s == head) head = l + stn;
                else {
                    string *i;
                    for (i = head; i->ne != s; i = i->ne); // @@ [This loop assumes the list is properly linked, but initial setup is broken. Also, if 's' is not reachable from 'head', this loops infinitely or crashes.]
                    i->ne = l + stn;
                }
            }
            memset(str, 0, sizeof(str));
            sn = 0;
        }
    }
    for (string *i = head; i != l; i = i->ne)
        printf("%s %d\n\n", i->s, i->num); // @@ [Extra newline (\n\n) causes blank lines between outputs, but expected output has only one newline per line.]
    fclose(IN);
    return 0;
}