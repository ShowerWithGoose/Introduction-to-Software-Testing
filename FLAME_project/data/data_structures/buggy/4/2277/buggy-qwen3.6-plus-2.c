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
        if((c>='0'&&c<='9')) // @@ The problem states a word consists only of letters. Digits should be treated as non-letter characters that break words, similar to punctuation, not just skipped. Skipping them merges adjacent letter sequences (e.g., "since1972" becomes "since" correctly here by accident if followed by punct, but "abc123def" would become "abcdef"). More importantly, the logic for handling delimiters is flawed.
            continue;
        else if(ispunct(c)==1||c==' '||c=='\n'||c=='.'||c=='('||c==')'||c==','||c=='-') // @@ ispunct(c) returns non-zero for punctuation, not necessarily 1. Also, this condition misses other whitespace like '\t' or '\r'. It's better to check !isalpha(c).
        {
            s=0;
            int len=(int)strlen(sentence);
            for(int i=0;i<len;i++)
                sentence[i]=tolower(sentence[i]);
            if(len > 0 && ispunct(sentence[len-1])) // @@ Added len > 0 check to prevent accessing sentence[-1] if sentence is empty.
                sentence[len-1]='\0';
            int flag=0;
            if (len == 0) { // @@ If the sentence buffer is empty (e.g., consecutive delimiters), we should skip processing to avoid adding empty strings or incorrect counts.
                 // Do nothing
            } else {
                for(int i=0;i<num;i++)
                {
                    if(strcmp(sentence, information[i].word)==0)
                    {
                        information[i].count++;flag=1;break;
                    }
                }
                if(flag==0)
                {
                    // strcpy is safer and cleaner than manual loop
                    strcpy(information[num].word, sentence);
                    information[num].count=1;
                    num++;
                }
            }
            // Reset sentence buffer properly
            memset(sentence, 0, sizeof(sentence));
            s = 0; // @@ s was reset at start of block, but good to ensure consistency.
        }
        else
            sentence[s++]=c;
    }
    // Handle the last word if file doesn't end with a delimiter
    if (s > 0) {
        int len = (int)strlen(sentence);
        for(int i=0;i<len;i++)
            sentence[i]=tolower(sentence[i]);
        if(len > 0 && ispunct(sentence[len-1]))
             sentence[len-1]='\0';
        
        if (strlen(sentence) > 0) {
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
                strcpy(information[num].word, sentence);
                information[num].count=1;
                num++;
            }
        }
    }

    qsort(information, num, sizeof(wordnode), cmp);
   for(int i=0;i<num;i++) // @@ Original code started from i=1, skipping the first word in the sorted list. It should start from i=0.
        printf("%s %d\n",information[i].word,information[i].count);
    fclose(in);
    return 0;
}