/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct wordcount{
    char piece[30];
    int count;//频度
    struct wordcount *next;
}node,*word;
char article[1000001];
void bubblesort(word l){
    for(word first=l->next;first!=NULL;first=first->next){
        for(word second=l->next;second!=NULL;second=second->next){
            if(second->next!=NULL){
                if(strcmp(second->piece,second->next->piece)>0){
                    int temp=second->count;
                    second->count=second->next->count;
                    second->next->count=temp;
                    int len1=strlen(second->piece),len2=strlen(second->next->piece);
                    char temp2[30];
                    for(int i=0;i<len1;i++){
                        temp2[i]=second->piece[i];
                    }
            
                    for(int i=0;i<len2;i++){
                        second->piece[i]=second->next->piece[i];
                    }
                    second->piece[len2]='\0';
                    for(int i=0;i<len1;i++){
                        second->next->piece[i]=temp2[i];
                    }
                    second->next->piece[len1]='\0';
                }
            }
        }
    }
}//冒泡排序
int main()
{
    FILE *in,*mid;
    in=fopen("article.txt","r");
    mid=fopen("mid.txt","w");
    int c,len=0;
    while((c=fgetc(in))!=EOF){
        if(c>='A'&&c<='Z'){
            fputc(c-('A'-'a'),mid);
        }
        else if((c>='a'&&c<='z')||c==' '||c=='\n'){
            fputc(c,mid);
        }
    }//转小写，仅保留字母、空格和换行符
    fclose(in);
    fclose(mid);
    mid=fopen("mid.txt","r");
    int temp;
    while((temp=fgetc(mid))!=EOF){
        article[len++]=temp;
    }
    article[len]='\0';
    word head,p,r;
    head=(word)malloc(sizeof(node));
    r=head;
    for(int i=0;i<len;i++){
        int len_of_word=0;
        if((i>0&&(article[i-1]<'a'||article[i-1]>'z')&&article[i]>='a'&&article[i]<='z')||(i==0&&article[i]>='a'&&article[i]<='z')){
            p=(word)malloc(sizeof(node));
            for(int j=i;article[j]>='a'&&article[j]<='z';j++){
                p->piece[len_of_word++]=article[j];
            }
            p->piece[len_of_word]='\0';
            p->count=1;
            r->next=p;
            r=p;
        }
        i+=len_of_word; // @@ The loop increment `i++` in the `for` statement combined with `i+=len_of_word` here causes the index to skip characters. Specifically, after extracting a word of length L, `i` is increased by L. Then the `for` loop increments `i` by 1. This means the character immediately following the word is skipped. If that character is the start of another word (which shouldn't happen if separated by non-letters) or if logic relies on checking every character, this skip is problematic. More critically, if `len_of_word` is 0 (no word found at this position despite the if condition, which is logically inconsistent but possible if bounds are wrong), it behaves oddly. The main issue is that `i` should be set to `j-1` so that the next iteration starts at `j`. By doing `i += len_of_word`, `i` becomes `i + len_of_word` which is `j`. Then the for loop does `i++`, making it `j+1`. This skips the character at `j` (the first non-letter after the word). While skipping non-letters is generally fine for finding starts of words, the condition `article[i-1]<'a'...` checks the previous char. If we skip a non-letter, the next iteration checks the char after that. This actually works for finding word starts *if* the input format is strictly alternating words and non-words. However, the critical error is likely elsewhere or this double increment is just inefficient/risky. Let's look closer. Actually, the standard pattern is `i = j - 1` or just let the loop handle it. Here, `j` stops at the first non-letter. We want the next `i` to be `j`. The `for` loop will increment `i` to `j+1`. So we miss checking index `j`. Since `article[j]` is not a letter, it cannot be the start of a word. So skipping it is safe for *starting* a word. BUT, wait. Look at the condition: `article[i-1]<'a' || article[i-1]>'z'`. If we skip index `j`, the next `i` is `j+1`. We check if `article[j]` is non-letter. It is. So `article[i-1]` (which is `article[j]`) is non-letter. And `article[i]` (which is `article[j+1]`) might be a letter. So this logic *seems* to correctly identify word boundaries despite the skip. 
        // However, there is a subtle bug. If `len_of_word` is 0, `i` doesn't advance effectively relative to the scan? No, `i` advances by 1 from the for loop.
        // Let's re-read the failure. "sincec" appears. This implies "since" and "c" are merged or "c" is appended to "since".
        // In the input: "C since1972.C".
        // Processed: "c since   c" (spaces/newlines preserved, numbers removed? No, numbers are NOT preserved in `mid.txt` because the `else if` only keeps letters, spaces, newlines. Numbers are discarded completely).
        // Wait, the filtering step: `else if((c>='a'&&c<='z')||c==' '||c=='\n')`. Digits are ignored. They are not written to `mid.txt`.
        // So "since1972.C" becomes "since.c" ? No. '1','9','7','2' are skipped. '.' is skipped.
        // So "since1972.C" -> "sincec".
        // Ah! The problem says "A word is defined as a sequence of characters consisting only of letters."
        // The reference implementation treats non-letters as delimiters.
        // This implementation *removes* non-letters (except space/newline) entirely.
        // So "since1972.C" becomes "sincec" in the `article` buffer because the digits and dot are stripped, joining "since" and "c" together.
        // This is the fundamental logical error. Non-letter characters should act as separators, not be deleted.
    }
    r->next=NULL;//完成单词链表创建

    word flag=head->next;
    while(flag!=NULL){
        p=flag;
        while(p->next!=NULL){
            if(strcmp(flag->piece,p->next->piece)==0){
                flag->count++;
                word q=p->next;
                p->next=q->next;
                free(q);
            }
            else{
                p=p->next;
            }
        }
        flag=flag->next;
    }
    bubblesort(head);
    p=head->next;
    while(p!=NULL){
        printf("%s %d\n",p->piece,p->count);
        p=p->next;
    }
    return 0;
}