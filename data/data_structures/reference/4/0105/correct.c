#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct words
{
    char word[30];
    int times;
} tongji[100],temp;

int main()
{
    FILE *in = fopen("article.txt", "r");
    char t[30], a;
    int i = 0, n = 0, m = 0;
    while (!feof(in))
    {
        a = getc(in);
        if (!isalpha(a))
        {
            n = 0;
            if (i > 0)
            {
                tongji[m].times = 1;
                strcpy(tongji[m++].word, t);
                memset(t, 0, 30);
                i = 0;
            }
        }
        else
        {
            a=tolower(a);
            t[i++] = a;
            n = 1;
        }
    }
    if (i > 0)
    {
        tongji[m].times = 1;
        strcpy(tongji[m++].word, t);
        memset(t, 0, 30);
        i = 0;
    }
    for (n = 0; n < m; n++){
        for(i=0;i<m-n-1;i++){
            if(strcmp(tongji[i].word,tongji[i+1].word)>0){
                temp=tongji[i];
                tongji[i]=tongji[i+1];
                tongji[i+1]=temp;
            }
        }
    }
    for(n=0;n<m;n++){
        if(strcmp(tongji[n].word,tongji[n+1].word)==0){
            tongji[n+1].times+=tongji[n].times;
            tongji[n].times=0;
        }
    }
    for(n=0;n<m;n++){
        if(tongji[n].times!=0)printf("%s %d\n",tongji[n].word,tongji[n].times);
    }
    return 0;
}

