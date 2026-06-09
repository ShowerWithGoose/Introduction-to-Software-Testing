#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct word_list
{
    char word[50];
    int num;
} list[1000];
int n = 0;
int read_txt(char temp[], FILE *fp);
int find_list(char temp[]);
int cmp(const void *p1, const void *p2);
int main()
{

    FILE *fp;
    fp = fopen("article.txt", "r");
    char temp[50];
    int cond;
    int location;
    while (1)
    {
        cond = read_txt(temp, fp);
        if (cond == 3)
            break;
        //printf("read---->>>> %s\n", temp);
        location = find_list(temp);
        if (location != -1)
            list[location].num++;
        else
        {
            strcpy(list[n].word, temp);
            list[n].num++;
            n++;
        }

        if (cond == 2)
            break;
    }
    int i;
    // printf("-----------------------\n");
    // for (i = 0; i < n; i++)
    //     printf("%s %d\n", list[i].word, list[i].num);

    qsort(list, n, sizeof(struct word_list), cmp);

    // printf("-----------------------\n");
    for (i = 0; i < n; i++)
        printf("%s %d\n", list[i].word, list[i].num);

    fclose(fp);
    return 0;
}

int read_txt(char temp[], FILE *fp)
{
    char a;
    int i;
    memset(temp, 0, 50);
    while (1)
    {
        a = getc(fp);
        if (isalpha(a))
            break;
        if (a == EOF)
        {
            return 3;
        }
    }
    for (i = 0;; i++)
    {
        if (isupper(a))
            a = tolower(a);
        temp[i] = a;
        // printf("%c:%d  ",a,a);
        a = getc(fp);
        if (a != EOF && (!isalpha(a)))
        {
            temp[i + 1] = '\0';
            return 1;
        }
        else if (a == EOF)
        {
            temp[i + 1] = '\0';
            return 2;
        }
    }
}

int find_list(char temp[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(list[i].word, temp) == 0)
            return i;
    }
    return -1;
}

int cmp(const void *p1, const void *p2)
{
    return strcmp(((struct word_list *)p1)->word, ((struct word_list *)p2)->word); //字典正序排序
                                                                                   // return strcmp((char*)p2,(char*)p1);		//字典逆序排序
}


