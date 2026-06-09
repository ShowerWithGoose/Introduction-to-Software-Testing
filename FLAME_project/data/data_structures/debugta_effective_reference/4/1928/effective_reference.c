// 哈希映射
// 结构体

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


struct Word
{
    char s[20];
    int count;

}word[100];


int cmp(const void* e1, const void* e2)
{
    return strcmp( (*(struct Word*)e1).s, (*(struct Word*)e2).s);
}


int main()
{
    FILE* in;

    in = fopen("article.txt", "r");

    char c = fgetc(in);

    int i = 0;
    while(c != EOF)
    {
    int i = 0;

    if(isalpha(c))
    {
        while(isalpha(c))
        {
        if(isupper(c))
    {
        c = tolower(c);
    }

    word[i].s[i++] = c;
    c = fgetc(in);
        }
    
    word[i].s[i] = '\0';
    word[i].count = 1;

    i++;
    }
    
    c = fgetc(in);
    }

    qsort(word, i, sizeof(word[0]), cmp);

    for(int i = 0; i < i - 1; i++)
    {
    int k = i;

    while(strcmp( word[k].s, word[i + 1].s ) == 0 )
    {
        word[k].count++;
        word[i + 1].count = 0;

        i++;
    }
    }

    for(int i = 0; i < i; i++)
    {
        if(word[i].count != 0)
        {
            printf("%s %d\n", word[i].s, word[i].count);
        }
    }

    fclose(in);

    return 0;
}
