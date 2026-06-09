// 哈希映射
// 结构体

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


struct Word
{
    char s[20];
    int num;

}word[100];


int cmp(const void* e1, const void* e2)
{
    return strcmp( (*(struct Word*)e1).s, (*(struct Word*)e2).s);
}


int main()
{
    FILE* in;

    in = fopen("article.txt", "r");

    char ch = fgetc(in);

    int count = 0;
    while(ch != EOF)
    {
    int i = 0;

    if(isalpha(ch))
    {
        while(isalpha(ch))
        {
        if(isupper(ch))
    {
        ch = tolower(ch);
    }

    word[count].s[i++] = ch;
    ch = fgetc(in);
        }
    
    word[count].s[i] = '\0';
    word[count].num = 1;

    count++;
    }
    
    ch = fgetc(in);
    }

    qsort(word, count, sizeof(word[0]), cmp);

    for(int i = 0; i < count - 1; i++)
    {
    int k = i;

    while(strcmp( word[k].s, word[i + 1].s ) == 0 )
    {
        word[k].num++;
        word[i + 1].num = 0;

        i++;
    }
    }

    for(int i = 0; i < count; i++)
    {
        if(word[i].num != 0)
        {
            printf("%s %d\n", word[i].s, word[i].num);
        }
    }

    fclose(in);

    return 0;
}