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
    while (~(c = fgetc(IN))) { // @@ [The expression ~(c = fgetc(IN)) is incorrect for checking EOF. fgetc returns an int, and EOF is typically -1. Using bitwise NOT (~) on a char (which is signed or unsigned depending on platform) leads to incorrect loop termination and potential misinterpretation of byte values like 0xFF as valid characters. This causes garbage like "iâ" in output.]
        if (isalpha(c)) str[sn++] = tolower(c);
        else {
            if (!sn) continue;
            string *s = head;
            while (s != l && strcmp(s->s, str) < 0) s = s->ne;
            if (!strcmp(s->s, str)) ++(s->num);
            else {
                l[++stn] = (string) {s, 1}; // @@ [This compound literal syntax is invalid in C without proper field designators. It should be { .ne = s, .num = 1 } or assign fields individually. However, the bigger issue is that 'l' is used as sentinel but never initialized properly as an empty list head. Also, 'head' initially points to l[0], which is uninitialized and may contain garbage.]
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
        printf("%s %d\n\n", i->s, i->num); // @@ [Extra newline (\n\n) causes blank lines between outputs, violating the requirement of one word per line with no extra spaces or blank lines. Expected is single \n.]
    fclose(IN);
    return 0;
}