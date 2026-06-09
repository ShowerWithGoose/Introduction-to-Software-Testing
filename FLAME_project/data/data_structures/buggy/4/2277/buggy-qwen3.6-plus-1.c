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
        if((c>='0'&&c<='9')) // @@ [The problem states a word consists only of letters. Digits should be treated as non-letter characters that terminate a word or are skipped, but simply continuing here ignores them without terminating the current word being built in 'sentence'. For example, "since1972" becomes "since" correctly if digits terminate, but if we just continue, "since" keeps accumulating if there were more letters after. However, the bigger issue is that digits are not letters. The logic below handles non-letters by finalizing the word. This condition skips digits entirely, meaning they don't trigger the word finalization logic in the 'else if' block. So "abc1def" would become "abcdef". It should treat digits as delimiters.]
            continue;
        else if(ispunct(c)==1||c==' '||c=='\n'||c=='.'||c=='('||c==')'||c==','||c=='-')
        {
            s=0;
            int len=(int)strlen(sentence);
            for(int i=0;i<len;i++)
                sentence[i]=tolower(sentence[i]);
            if(len > 0 && ispunct(sentence[len-1])) // @@ [Added len > 0 check to prevent accessing sentence[-1] if sentence is empty. Also, the original logic attempts to strip trailing punctuation from the accumulated sentence, but since we are processing character by character and only adding letters to 'sentence' (via the else block), 'sentence' should theoretically only contain letters. However, the previous 'if' block for digits was 'continue', so digits weren't added. But what about other characters? The 'else' adds anything that isn't a digit or the specific punctuations/spaces listed. This means characters like '"' or ''' might be added to 'sentence' if they aren't caught by ispunct(c)==1 (which depends on locale/implementation) or the explicit list. The definition says "only letters". So any non-letter should terminate the word. The current logic is fragile.]
                sentence[len-1]='\0';
            int flag=0;
            if (len > 0) { // @@ [We should only process the word if there is actually a word accumulated (len > 0). If we encounter multiple delimiters in a row, len will be 0, and we shouldn't try to find/add an empty string.]
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
            }
            for(int i=0;i<len;i++)
                sentence[i]=0;
        }
        else
            sentence[s++]=c;
    }
    // @@ [After the loop finishes, if the file ends with a letter (i.e., the last word is not followed by a delimiter), the last word remains in 'sentence' and is never processed. We need to handle the remaining content in 'sentence' here.]
    qsort(information, num, sizeof(wordnode), cmp);
   for(int i=0;i<num;i++) // @@ [The original loop started at i=1, which skips the first word in the sorted array. It should start at i=0 to print all words.]
        printf("%s %d\n",information[i].word,information[i].count);
    fclose(in);
    return 0;
}