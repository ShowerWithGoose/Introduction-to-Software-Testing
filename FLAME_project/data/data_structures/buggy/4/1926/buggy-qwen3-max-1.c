#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char w[20];
    int num;
    struct node *next;
} node;
typedef struct node* word;

int main()
{
    int i=0,count=0;
    char dc[100]= {'\0'},ch;
    FILE *in;
    in=fopen("article.txt","r");
    word p,list=NULL;
    list=(word)malloc(sizeof(node));
    list->next=NULL;
    list->num=0;
    while((ch=fgetc(in))!=EOF)
    {
        if(ch>='A'&&ch<='Z')
        {
            ch='a'+ch-'A';
            dc[i]=ch;
            i++;
        }
        else if(ch>='a'&&ch<='z')
        {
            dc[i]=ch;
            i++;
        }
        else if(dc[i-1]>='a'&&dc[i-1]<='z')
        {
            for(word q=list; q!=NULL; q=q->next)
            {
                if(strcmp(q->w,dc)==0)
                {
                    q->num++;
                    count++;
                }
            }
            if(count==0)
            {
                for(word r=list; r!=NULL; r=r->next)
                {
                    if(r->num==0)
                    {
                        strcpy(r->w,dc);
                        r->num=1;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                    else if(strcmp(r->w,dc)<0&&r->next==NULL)
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc);
                        p->num=1;
                        p->next=r->next;
                        r->next=p;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                    else if(strcmp(r->w,dc)<0&&strcmp(r->next->w,dc)>0)
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc);
                        p->num=1;
                        p->next=r->next;
                        r->next=p;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                    else if(strcmp(list->w,dc)>0)
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc);
                        p->num=1;
                        p->next=list;
                        list=p;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                }
                for(int j=0; j<100; j++)
                    dc[j]='\0';
            }
            i=0;
            count=0;
        }
    }
    for(word q=list->next; q!=NULL; q=q->next)
    {
        printf("%s %d\n",q->w,q->num);
    } // @@ [The output skips the first word because the list head is a dummy node and the real words start from list->next, but the dummy node was initialized with num=0 and never used to store a real word. However, the main issue is that the program fails to handle the last word if the file doesn't end with a non-letter character. Additionally, the logic for inserting in lexicographical order is flawed and doesn't maintain sorted order correctly. Most critically, the buggy output shows "tou" instead of "to", which indicates that the word extraction is incorrect due to improper handling of word boundaries — specifically, the condition `else if(dc[i-1]>='a'&&dc[i-1]<='z')` assumes that a word ends only when a non-letter follows a letter, but it doesn't reset `i` properly when a word is zero-length or when multiple delimiters occur. Also, the dummy head node causes the first real word to be stored in the dummy node itself (when r==list and r->num==0), but then later insertions may not sort correctly relative to it. The core error causing "tou" is that the input contains "to you", and due to incorrect parsing (possibly reading 'u' as part of "to" because of buffer not being cleared or index mishandling), it becomes "tou". Actually, looking at the expected vs buggy: "tou" appears instead of "to". This suggests that the word "to" is being corrupted. In the input: "Do more than others expect you to do...", the word "to" is followed by space then "do". The bug likely comes from the fact that after processing 'o' of "to", the next character is space (non-letter), so it triggers the else-if. But note: the code uses `dc[i-1]` to check if last char was letter — but if i==0 (no letters yet), then dc[-1] is accessed! However, in this case, i>0. But more importantly, the buffer `dc` is not null-terminated before using `strcmp`. The code builds `dc` by assigning characters but never puts a '\0' at position i before using it in strcmp. So `dc` contains leftover characters from previous words. For example, after "you", dc might be "you\0..." but then when reading "to", it writes 't','o' at positions 0,1, but i=2, and then in the else-if block, it uses `dc` without setting dc[2]='\0'. So if previously dc had "you", and now we write "to" at start, but don't null-terminate, then dc becomes "to\0..." only if previous content was cleared. But the clearing happens AFTER processing, not before. So during strcmp, dc may contain "to" plus leftover letters like 'u' from "you", making "tou". Specifically: after "you", dc = {'y','o','u', ...}. Then for "to": i=0, read 't' -> dc[0]='t'; i=1, read 'o' -> dc[1]='o'; then space triggers else-if. Now dc[0]='t', dc[1]='o', but dc[2] is still 'u' from before! So the string is "tou" because there's no null terminator at index 2. The code never sets dc[i] = '\0' before using it in strcmp. This is the critical error.]
    fclose(in);
    return 0;
}