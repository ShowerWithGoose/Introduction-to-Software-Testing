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
    while (~(c = fgetc(IN))) { // @@ [The expression ~(c = fgetc(IN)) is incorrect. fgetc returns an int (to accommodate EOF), but c is declared as char. Also, ~ is bitwise NOT, not a comparison with EOF. This causes undefined behavior and likely infinite loop or crash. Should be: (c = fgetc(IN)) != EOF]
        if (isalpha(c)) str[sn++] = tolower(c);
        else {
            if (!sn) continue;
            string *s = head;
            while (s != l && strcmp(s->s, str) < 0) s = s->ne; // @@ [At program start, l[0] (pointed by head) is uninitialized. s->s may contain garbage, causing strcmp to crash or behave unpredictably. Also, the linked list logic is flawed because l[0] is used as sentinel but never initialized properly.]
            if (!strcmp(s->s, str)) ++(s->num); // @@ [If s == l (i.e., head hasn't moved), s->s is uninitialized, so strcmp may crash. Also, when inserting first word, this condition fails but insertion logic assumes s points to a valid node.]
            else {
                l[++stn] = (string) {s, 1}; // @@ [This compound literal syntax is invalid in C89/C90 and may not be supported by all compilers. Also, the .s field is not initialized here, only via strcpy next line—but order of initialization is fragile.]
                strcpy(l[stn].s, str);
                if (s == head) head = l + stn;
                else {
                    string *i;
                    for (i = head; i->ne != s; i = i->ne); // @@ [If the list is empty or broken, this loop may run indefinitely or dereference null/uninitialized pointer. Also, initial node l[0] has ne uninitialized, so traversal is unsafe.]
                    i->ne = l + stn;
                }
            }
            memset(str, 0, sizeof(str));
            sn = 0;
        }
    }
    for (string *i = head; i != l; i = i->ne) // @@ [After processing, if no words were read, head == l, so loop doesn't run—but if words exist, the loop condition assumes l is a sentinel at end, but l[0] was used as head initially and may still be in list. Also, if file ends without non-alpha char, last word is never processed.]
        printf("%s %d\n\n", i->s, i->num); // @@ [Output has two newlines (\n\n) per line, but problem requires exactly one newline per line.]
    fclose(IN);
    return 0;
}