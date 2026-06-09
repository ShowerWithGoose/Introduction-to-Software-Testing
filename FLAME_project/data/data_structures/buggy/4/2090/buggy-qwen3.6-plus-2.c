#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    char word[30];
    int count;
    struct node *next;
};
struct node *wordlist=NULL;
int getword(FILE *in,char *w){
    int c;
    while(!isalpha(c=fgetc(in))){
        if(c==EOF) return EOF;
        else continue;
    }
    do{
        *w++=tolower(c);
    }while(isalpha(c=fgetc(in)));
    *w='\0';
    return 1;
}
void insertword(struct node *p,char* w){
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    q->count=1;
    strcpy(q->word,w);
    q->next=NULL;
    if(p==NULL){
        q->next=wordlist;
        wordlist=q;
    }
    else{
        q->next=p->next;
        p->next=q;
    }
}
void searchword(char* w){
    struct node *p,*q=NULL;
    for(p=wordlist;p!=NULL;q=p,p=p->next){
        if(strcmp(w,p->word)<0){
            insertword(q,w);
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->count++;
            break;
        }
        else if(p->next==NULL){ // @@ The logic for inserting at the end is flawed. If the new word is lexicographically greater than the last word, it should be inserted after the last word. However, the loop condition `p!=NULL` will terminate when p becomes NULL (after processing the last node). The check `p->next==NULL` inside the loop handles insertion after the current last node only if the loop hasn't broken yet. But if the word is greater than all existing words, the loop finishes without inserting. Specifically, if `w` is greater than `p->word` and `p->next` is not NULL, it continues. If `p->next` IS NULL, it inserts. This part seems okay for appending. However, the main issue is likely that `will` is counted twice or `you` is counted incorrectly due to initialization or loop logic. Let's look closer. The initialization reads one word and creates the first node. Then the loop processes the rest. The word "will" appears once in the text. "you" appears 3 times. The buggy output shows "will" 2 and "you" 4. This suggests an off-by-one error where the first word is counted again or the last word is processed incorrectly. Wait, looking at the input: "I will give you...". First word read is "I". It is added to wordlist. Then `while(getword(in,s)!=EOF)` reads "will", "give", "you"... The word "you" appears at the end of line 1, line 3, and line 4. That's 3 times. The buggy output says 4. The word "will" appears once. Buggy output says 2. This implies that the first word "I" might be interfering or the list handling is duplicating entries. Actually, look at `searchword`. If the list is empty, it's handled by `main`'s initialization. If `searchword` is called with a word that matches the first node, it increments. If the input file has "I" at the start, `main` adds it. Then `getword` reads "will". `searchword("will")` compares with "i". "will" > "i". `p->next` is NULL. So `insertword(p, "will")` is called. This appends "will" after "i". Correct. Next "give". "give" > "i"? No, 'g' > 'i' is false. 'g' < 'i'. So `strcmp("give", "i") < 0`. `insertword(q, "give")` where q is NULL (since p was head). `insertword(NULL, "give")` puts "give" at the head. List: give -> i -> will. Next "you". "you" > "give". Continue. "you" > "i". Continue. "you" > "will". `p->next` is NULL. Insert after "will". List: give -> i -> will -> you. Counts are all 1. Next "some". "some" < "you"? Yes. "some" > "will"? 's' > 'w' is false. 's' < 'w'. So "some" < "will". Break? No, loop continues. `strcmp("some", "will") < 0` is true. `insertword(q, "some")`. q is pointer to "will". Inserts "some" after "will". List: give -> i -> will -> some -> you. This maintains sorted order? No. "some" comes before "you" but after "will". Lexicographically: give, i, some, will, you. The list is now give -> i -> will -> some -> you. This is NOT sorted. The `searchword` function assumes the list is sorted and inserts in place. But if it inserts "some" between "will" and "you", the list remains sorted IF "some" > "will" and "some" < "you". "some" > "will" is false ('s' < 'w'). So it should have been inserted before "will". In the previous step, when processing "some": p starts at "give". "some" > "give". Next p="i". "some" > "i". Next p="will". "some" < "will". So it breaks and inserts after q ("i"). So list becomes give -> i -> some -> will -> you. This is correct. Why are counts wrong? "will" 2, "you" 4. Total words in text: I, will, give, you, some, advice, about, life, Eat, more, roughage, Do, more, than, others, expect, you, to, do, and, do, it, pains, Remember, what, life, tells, you. Unique words sorted: about, advice, and, do, eat, expect, give, i, it, life, more, others, pains, remember, roughage, some, tells, than, to, what, will, you. Counts: do: 3 (Do, do, do), you: 3, will: 1, life: 2, more: 2. The buggy output has will:2, you:4. This is exactly +1 for both. This suggests the first word "I" is being counted as "will" or something? No. Notice that `main` initializes `wordlist` with the first word. Then the `while` loop processes the rest. If the file ends with a newline, `getword` might behave differently? No. Let's look at `getword`. It returns 1 on success, EOF on failure. The loop `while(getword(in,s)!=EOF)` processes all subsequent words. Is it possible that the first word is processed twice? No. Is it possible that the last word is processed twice? No. Look at `searchword` again. `else if(p->next==NULL){ insertword(p,w); }`. This inserts if the word is larger than the current largest. It does NOT break. So the loop continues? No, `p` becomes `p->next` which is NULL (because we just set `p->next` to the new node in `insertword`? No, `insertword` modifies `p->next`. But the `for` loop increment `p=p->next` happens AFTER the body. If we insert at the end, `p->next` was NULL. `insertword` sets `p->next` to new node. Then `p=p->next` makes `p` point to the new node. Then `p!=NULL` is true. Loop continues. Now `p` is the new node. `q` is the old last node. `strcmp(w, p->word)`? `w` is the same word we just inserted. `strcmp` will be 0. `p->count++`. So the count becomes 2 immediately upon insertion! This is the bug. When a word is inserted at the end (or anywhere via `insertword`), the loop doesn't break, so it re-evaluates the newly inserted node (or subsequent nodes) and might match again or cause issues. Specifically for the last element: if we append "will", `p` moves to "will". `strcmp("will", "will") == 0`. `p->count++`. So "will" gets count 2 immediately. Same for "you" if it's appended later? If "you" is appended, it gets count 2. Then later occurrences increment it further. "you" appears 3 times. 1st time: appended, count becomes 2. 2nd time: found, count becomes 3. 3rd time: found, count becomes 4. This matches the buggy output! "will" appears 1 time. 1st time: appended, count becomes 2. Matches buggy output. So the error is that `insertword` calls do not `break` the loop.
            insertword(p,w);
            break; // @@ Missing break statement causes the newly inserted node to be evaluated in the next iteration, leading to an immediate double-count for words inserted at the end or causing logical errors in traversal.
        }
    }
}
int main(){
    struct node *p;
    FILE *in;
    in=fopen("article.txt","r");
    char s[30];
    getword(in,s);
    wordlist=(struct node*)malloc(sizeof(struct node));
    wordlist->count=1;
    strcpy(wordlist->word,s);
    wordlist->next=NULL;
    while(getword(in,s)!=EOF) searchword(s);
    for(p=wordlist;p!=NULL;p=p->next){
        printf("%s %d\n",p->word,p->count);
    }
    fclose(in);
    return 0;
}