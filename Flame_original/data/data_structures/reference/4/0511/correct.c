#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wordlist
{
    char word[50];
    int frequency;
    struct wordlist *former;
    struct wordlist *next;
} node;

int main()
{
    FILE *in;
    node *head, *p1, *p2, *op;
    char line[1024];
    char *read, *read_word;
    read_word = (char *)malloc(sizeof(char) * 50);
    int i;

    if ((in = fopen("article.txt", "r")) == NULL)
    {
        perror("article.txt");
        exit(0);
    }

    p1 = p2 = (node *)malloc(sizeof(node));
    memset(p1->word, 0, 50);
    p1->frequency = 0;
    head = p1;
    p1->next = NULL;
    while (fgets(line, 1024, in) != NULL)
    {
        for (read = line; *read != '\n' && *read != '\0'; read++)
        {
            i = 0;
            if (isalpha(*read))
            {
                while (isalpha(*read))
                {
                    if (*read >= 'A' && *read <= 'Z')
                        read_word[i++] = *read - 'A' + 'a';
                    if (*read >= 'a' && *read <= 'z')
                        read_word[i++] = *read;
                    read++;
                }
                read_word[i] = '\0';
                for (op = head; op != NULL; op = op->next)
                {
                    if (head->word[0] == '\0')
                    {
                        strcpy(op->word, read_word);
                        op->frequency++;
                    }
                    else
                    {
                        if (strcmp(head->word, read_word) > 0)
                        {
                            p1 = (node *)malloc(sizeof(node));
                            memset(p1->word, 0, 50);
                            p1->frequency = 0;

                            p1->next = head;
                            head->former = p1;
                            head = p1;

                            strcpy(p1->word, read_word);
                            p1->frequency++;
                            break;
                        }
                        else if (strcmp(op->word, read_word) < 0 && op->next == NULL)
                        {
                            p1 = (node *)malloc(sizeof(node));
                            memset(p1->word, 0, 50);
                            p1->frequency = 0;

                            op->next = p1;
                            p1->former = op;
                            p1->next = NULL;

                            strcpy(p1->word, read_word);
                            p1->frequency++;
                            break;
                        }
                        else if (strcmp(op->word, read_word) < 0 && strcmp(op->next->word, read_word) > 0)
                        {
                            p1 = (node *)malloc(sizeof(node));
                            memset(p1->word, 0, 50);
                            p1->frequency = 0;

                            p1->next = op->next;
                            op->next->former = p1;
                            op->next = p1;
                            p1->former = op;

                            strcpy(p1->word, read_word);
                            p1->frequency++;
                            break;
                        }
                        else if (strcmp(op->word, read_word) == 0)
                        {
                            op->frequency++;
                            break;
                        }
                    }
                }
                memset(read_word, 0, 50);
            }
        }
    }

    for (op = head; op != NULL; op = op->next)
    {
        printf("%s %d\n", op->word, op->frequency);
    }

    return 0;
}

