#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct wordtype
{
    int times;
    char wordstr[20];
    struct wordtype *next;
} * word, wordval;
int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    word current, head = NULL, searchpnt, psearchpnt;
    char tmpc = 0, tmpstr[20] = {0}, tmpcstr[2] = {0};
    while ((tmpc = fgetc(in)) != EOF)
    {
        if (tmpc <= 'Z' && tmpc >= 'A')
            tmpc += 'a' - 'A';
        if (tmpc <= 'z' && tmpc >= 'a')
        {
            tmpcstr[0] = tmpc;
            tmpcstr[1] = '\0';
            strcat(tmpstr, tmpcstr);
        }
        else
        {
            if (strlen(tmpstr))
            {

                if (head == NULL)
                {
                    current = (word)malloc(sizeof(wordval));
                    strcpy(current->wordstr, tmpstr);
                    current->times = 1;
                    current->next = NULL;
                    head = current;
                }
                else
                {
                    searchpnt = head;
                    psearchpnt = head;
                    while (searchpnt != NULL && strcmp(searchpnt->wordstr, tmpstr) < 0)
                    {
                        if (searchpnt != head)
                            psearchpnt = psearchpnt->next;
                        searchpnt = searchpnt->next;
                    }
                    if (searchpnt == NULL)
                    {
                        current = (word)malloc(sizeof(wordval));
                        strcpy(current->wordstr, tmpstr);
                        current->times = 1;
                        current->next = NULL;
                        psearchpnt->next = current;
                    }
                    else
                    {
                        if (strcmp(searchpnt->wordstr, tmpstr) == 0)
                            searchpnt->times++;
                        else
                        {
                            current = (word)malloc(sizeof(wordval));
                            strcpy(current->wordstr, tmpstr);
                            current->times = 1;
                            current->next = searchpnt;
                            if (searchpnt != head)
                                psearchpnt->next = current;
                            else
                                head = current;
                        }
                    }
                }
                memset(tmpstr, 0, sizeof(tmpstr));
            }
        }
    }

    for (current = head; current != NULL; current = current->next)
        printf("%s %d\n", current->wordstr, current->times);
    current = head;
    while (head != NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
    fclose(in);
    return 0;
}
