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
    char c, str[99], sn = 0; // @@ 'c' should be declared as 'int' to correctly store the 'EOF' value returned by fgetc; using 'char' may cause incorrect loop termination or infinite loops.
    while (~(c = fgetc(IN))) { // @@ Using '~' to check for EOF is non-standard and unreliable; it should be '(c = fgetc(IN)) != EOF'.
        if (isalpha(c)) str[sn++] = tolower(c);
        else {
            if (!sn) continue;
            string *s = head;
            while (s != l && strcmp(s->s, str) < 0) s = s->ne;
            if (!strcmp(s->s, str)) ++(s->num);
            else {
                l[++stn] = (string) {s, 1}; // @@ Compound literal syntax is a C99 feature and will cause a compilation error in C89/C90 standard environments.
                strcpy(l[stn].s, str);
                if (s == head) head = l + stn;
                else {
                    string *i;
                    for (i = head; i->ne != s; i = i->ne);
                    i->ne = l + stn;
                }
            }
            memset(str, 0, sizeof(str));
            sn = 0;
        }
    }
    for (string *i = head; i != l; i = i->ne) // @@ Declaring a variable inside the 'for' loop initialization is C99 syntax, which causes a compilation error in strict C89/C90 mode.
        printf("%s %d\n\n", i->s, i->num); // @@ Outputs two newlines per line, violating the required output format of exactly one newline per line.
    fclose(IN);
    return 0;
}