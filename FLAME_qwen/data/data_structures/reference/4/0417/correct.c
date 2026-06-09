#include <stdio.h>
#include <string.h>
#include <ctype.h>
char ans[1000][100];
char now[100];
int num[1000] = {0};

int place[1000];

int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    char c;
    int len = 0;
    int all = 0;
    int i, j;
    while ((c = fgetc(in))!=EOF) {
        if (isalpha(c)) {
            c = tolower(c);
            now[len] = c;
            len++;
        } else if (len>0){
            now[len] = '\0';
            for (i=1; i<=all; i++) {
                if (strcmp(now, ans[i])==0) {
                    num[i]++;
                    break;
                }
            }
            if (i>all) {
                all++;
                strcpy(ans[all], now);
            }
            len = 0;
        }
    }
    for (i=1; i<=all; i++)
        place[i] = i;
    
    for (i=1; i<all; i++) {
        for (j=1; j<=all-i; j++) {
            if (strcmp(ans[place[j]], ans[place[j+1]])>0) {
                int t = place[j];
                place[j] = place[j+1];
                place[j+1] = t;
            }
        }
    }
    
    for (i=1; i<=all; i++)
        printf("%s %d\n", ans[place[i]], num[place[i]]+1);
    
    fclose(in);
    return 0;
}



