#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct wordnode
{
    char word[100];
    int count;
} wordnode;
int cmp(const void *a,const void *b)
{
    wordnode *p=(wordnode *)a;
    wordnode *q=(wordnode *)b;
    return (strcmp(p->word, q->word));
}
int main(void)
{
    FILE* in = fopen("article.txt", "r");
    wordnode information[50];
    char sentence[1000]={0};
    int num=0;
    char c;
    int s=0;
    while((c=fgetc(in))!=EOF)
    {
        if((c>='0'&&c<='9'))
            continue;
        else if(ispunct(c)==1||c==' '||c=='\n'||c=='.'||c=='('||c==')'||c==','||c=='-')
        {
            s=0;
            int len=(int)strlen(sentence);
            for(int i=0;i<len;i++)
                sentence[i]=tolower(sentence[i]);
            if(ispunct(sentence[len-1]))
                sentence[len-1]='\0';
            int flag=0;
            for(int i=0;i<num;i++)
            {
                if(strcmp(sentence, information[i].word)==0)
                {
                    information[i].count++;flag=1;break;
                }
            }
            if(flag==0)
            {
                for(int i=0;i<len;i++)
                {
                    information[num].word[i]=sentence[i];
                }
                information[num].word[len]='\0';
                information[num].count=1;
                num++;
            }
            for(int i=0;i<len;i++)
                sentence[i]=0;
        }
        else
            sentence[s++]=c;
    }
    qsort(information, num, sizeof(wordnode), cmp);
   for(int i=1;i<num;i++) // @@ [Loop starts at index 1, skipping the first word (index 0), leading to missing output for the lexicographically smallest word]
        printf("%s %d\n",information[i].word,information[i].count);
    fclose(in);
    return 0;
}