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
    while (~(c = fgetc(IN))) { @@ [The expression ~(c = fgetc(IN)) is incorrect for checking EOF. fgetc returns an int, not a char, and using bitwise NOT (~) on a char causes undefined behavior and wrong EOF detection. It should be: (c = fgetc(IN)) != EOF]
        if (isalpha(c)) str[sn++] = tolower(c);
        else {
            if (!sn) continue;
            string *s = head;
            while (s != l && strcmp(s->s, str) < 0) s = s->ne;
            if (!strcmp(s->s, str)) ++(s->num);
            else {
                l[++stn] = (string) {s, 1}; @@ [This compound literal initialization is invalid in C89/C90 and may not be supported by all compilers. Also, the 's' field is uninitialized here, leading to undefined behavior when strcpy is called next. The struct should be fully initialized or fields set explicitly.]
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
    for (string *i = head; i != l; i = i->ne)
        printf("%s %d\n\n", i->s, i->num); @@ [Extra newline (\n\n) causes output format error; should be only one newline per line as per problem requirement.]
    fclose(IN);
    return 0;
}