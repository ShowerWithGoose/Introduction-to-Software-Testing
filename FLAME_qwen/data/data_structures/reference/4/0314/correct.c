#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define clear(a) memset(a,0,sizeof(a))
typedef struct blank
{
    char word[20];
    int num;
}WordCollect;
int cmp(const void *a,const void *b);
int main()
{
    int word_num=0,flag=0,swi;
    char save[20];
    int i1,i2;
    WordCollect vc[1000];
    char c;
    FILE *in;
    in=fopen("article.txt","r");
    while((c=fgetc(in))!=EOF)
    {
        if(flag==0)
        {
            if(isalpha(c))
            {
                save[flag]=tolower(c);
                flag++;
            }
        }
        else
        {
            if(isalpha(c))
            {
                save[flag]=tolower(c);
                flag++;
            }
            else
            {
                swi=0;
                for(i1=0;i1<word_num;i1++)
                {
                    if(strcmp(save,vc[i1].word)==0)
                    {
                        vc[i1].num++;
                        swi=1;
                        break;
                    }
                }
                if(swi==0)
                {
                    strcpy(vc[word_num].word,save);
                    vc[word_num].num++;
                    word_num++;
                }
                flag=0;
                clear(save);
            }
        }
    }
    qsort(vc,word_num,sizeof(vc[0]),cmp);
    for(i2=0;i2<word_num;i2++)
    {
        printf("%s %d\n",vc[i2].word,vc[i2].num);
    }
    fclose(in);
    return 0;
}
int cmp(const void *a,const void *b)
{
    return strcmp((*(WordCollect *)a).word,(*(WordCollect *)b).word);
}
