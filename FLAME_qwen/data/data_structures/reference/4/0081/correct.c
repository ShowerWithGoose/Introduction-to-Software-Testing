#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    char s[32];
    int cnt;
} list[10000], temp;
int listnumnow;
int searchword(int listnumber, char *s, struct node *list);
void insertword();

int main()
{
    //逐行处理
    FILE *in;
    in = fopen("article.txt", "r");
    char word[100] = {0};
    int position_now = 0;
    char c;
    while ((c = fgetc(in)) != EOF)
    {
        if (isalpha(c))
        {
            int i = 0;
            word[i] = tolower(c);
            while (c = fgetc(in))
            {
                if (isalpha(c) == 0)
                    break;
                else
                    word[++i] = tolower(c);
            }

            int len = i + 1;
            word[++i] = '\0';
            // printf("$$$%s\n", word);
            //  printf("%d\n", searchword(listnumnow, word, list));
            if (searchword(listnumnow, word, list) == -1)
            {
                strcpy(list[listnumnow].s, word);
                list[listnumnow++].cnt++;
            }
            else
                (list[searchword(listnumnow, word, list)].cnt)++;

            // if (searchword(listnumnow,word,list[]) == 0)
            // {
            //     insertword()
            //         cnt++;
            // }
            // else{
            //     cnt++;
            // }
        }
    }

    // printf("%d", listnumnow);

    for (int i = 0; i < listnumnow; i++)
        for (int j = i; j < listnumnow; j++)
            if (strcmp(list[i].s, list[j].s) > 0)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }

    for (int i = 0; i < listnumnow; i++)
        printf("%s %d\n", list[i].s, list[i].cnt);
    return 0;
}

int searchword(int listnumber, char *store, struct node *list)
{
    int i;
    for (i = 0; i < listnumber; i++)
        if (strcmp(store, list[i].s) == 0)
            return i;
    return -1;
}
