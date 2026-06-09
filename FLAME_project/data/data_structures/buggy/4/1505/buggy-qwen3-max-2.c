#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char word[100];
    int n;
    struct node *next;
}subject;

void exam(struct node *start,char *str){
    struct node *p,*q;
    int judge=0;
    for(p=start;;p=p->next){
        if(strcmp(p->word,str)==0){
            p->n++;
            judge=1;
        }
        if(p->next==NULL){
            break;
        }
    }
    if(judge==0){
        q=(struct node*)malloc(sizeof(subject));
        strcpy(q->word,str);
        q->n=1;
        q->next=NULL;
        p->next=q;
        p=q;
    }
}

int number(struct node *start){
    struct node *p;
    int num=0;
    for(p=start;;p=p->next){
        num++;
        if(p->next==NULL){
            break;
        }
    }
    return num;
}

void order(struct node *start,int num){
    int i;
    struct node *p;
    int k=0;
    char gapStr[100];
    int gapN;
    for(i=num-1;i>=1;i--){
        k=0;
        for(p=start;;p=p->next){
            if(strcmp(p->word,p->next->word)>0){
                strcpy(gapStr,p->word);
                gapN=p->n;
                strcpy(p->word,p->next->word);
                p->n=p->next->n;
                strcpy(p->next->word,gapStr);
                p->next->n=gapN;
            }
            k++;
            if(k==i){
                break;
            }
        }
    }
}

void change(char *str){
    int i;
    for(i=0;i<=strlen(str)-1;i++){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]=str[i]+'a'-'A';
        }
    }
}

int range(char c){
    if((c>='a'&&c<='z') || (c>='A'&&c<='Z')){
        return 1;
    }
    else{
        return 0;
    }
}

void changeTXT(FILE *fpin,FILE *fpnew){
    char c;
    while(1){
        if(c==EOF){
            break;
        }
        c=fgetc(fpin); // @@ [The variable 'c' is used uninitialized in the first iteration of the loop. The check 'if(c==EOF)' happens before reading, so the first character read may be lost or cause undefined behavior.]
        if(range(c)==0){
            fputc(' ',fpnew);
        }
        else{
            fputc(c,fpnew);
        }
    }
}

int main(){
    FILE *fpin;
    fpin=fopen("article.txt","r");
    FILE *fpnew;
    fpnew=fopen("new.txt","w");
    changeTXT(fpin,fpnew);
    fclose(fpnew);
    fpnew=fopen("new.txt","r");
    rewind(fpnew);
    char str[100];
    struct node *start;
    struct node *p;
    start=p=(struct node*)malloc(sizeof(subject));
    fscanf(fpnew,"%s",str);
    change(str);
    strcpy(start->word,str);
    start->n=1;
    start->next=NULL;
    while(1){
        fscanf(fpnew,"%s",str);
        change(str);
        exam(start,str);
        if(fgetc(fpnew)==EOF){ // @@ [This reads an extra character after each word, which may skip characters or cause premature termination. It also doesn't account for trailing whitespace or multiple spaces correctly. Additionally, after the last word, fgetc may return EOF but the last word has already been processed, yet this condition breaks the loop only after trying to read past it, possibly missing the last word if not followed by whitespace. However, in this specific test case, the real issue is that "you" appears 4 times because the semicolon after "roughage;" is replaced by a space, but the period at the end of the first line and other punctuation may result in empty strings or malformed reads. But the critical bug causing 'you 4' instead of 'you 3' is actually in the loop logic: the loop processes a word with fscanf, then immediately does fgetc to check EOF. This fgetc consumes the next character (often a space or newline), but if the file ends right after the last word, fscanf succeeds, then fgetc returns EOF and breaks — that seems okay. However, the actual problem is that the initial word read before the loop assumes there's at least one word. If the file is empty, it crashes. But more importantly, the loop condition is flawed: it reads a word, processes it, then checks the next character. If that character is not EOF, it continues. But after the last word, fscanf reads the word successfully, then fgetc returns EOF → break. So all words are read. Then why 'you' is counted 4 times? Looking at input: "you" appears in: "I will give you some...", "expect you to do", "what life tells you;". That's 3 times. But note: the original text ends with "you;" — the semicolon is replaced by space in new.txt, so "you" is a clean word. However, the bug is elsewhere: in the exam() function, the loop continues even after finding a match, so if there are duplicate nodes (which there shouldn't be), it might overcount. But more critically, the exam() function does NOT break after finding a match! So if the same word appears again later in the list (which it shouldn't in a correct implementation), it would increment multiple times. But in this code, words are only added at the end, so duplicates shouldn't exist. However, the real issue is that the exam() function keeps looping through the entire list even after finding a match, but since there's only one instance of each word, it only increments once. So that’s not the problem. Let's reexamine input: The input has "you" three times. But the buggy output says 4. How? Look at the main loop: it reads the first word outside the loop, then enters the loop and reads the next word, processes it, then does fgetc. But what if the file has trailing space? Actually, the critical bug is in the changeTXT function: it writes a space for every non-letter, including consecutive punctuation, which may create empty tokens? No, fscanf with %s skips whitespace. So that should be fine. Another possibility: the initial read assumes the file is non-empty. But the real smoking gun: in the main loop, after processing a word, it does fgetc(fpnew) to check for EOF. However, after reading the last word, fscanf succeeds, then fgetc returns EOF → break. So all words are processed. But wait: how many words are there? Let's count "you": 
Line1: "you"
Line2: none
Line3: "you"
Line4: "you"
That's 3. But the program outputs 4. Now look at the exam() function: when a new word is added, it sets p->next = q, but note that during the search loop, if the word is not found, it adds it. However, the search loop runs to the end (p points to last node), then adds q as p->next. That seems correct. But here's the key: the very first word is read and stored in 'start'. Then in the loop, the next word is read. But what if the file has only one word? It would still work. However, there's another issue: in the main loop, after reading a word with fscanf, it calls exam(), then does fgetc to check EOF. But fscanf leaves the file pointer right after the word (at the next whitespace). Then fgetc reads one character. If that character is EOF, break. But if the file ends exactly after the last word (no trailing newline), then after fscanf reads the last word, the next fgetc returns EOF → break. Correct. But if there is a trailing newline, then fgetc reads '\n', which is not EOF, so the loop continues, and the next fscanf fails (returns EOF), but the code doesn't check the return value of fscanf! So when fscanf fails, 'str' contains garbage or the previous word, and then change(str) and exam(start,str) are called with invalid data. Specifically, if fscanf returns EOF (i.e., no word read), str is unchanged, so it reprocesses the last word again! That causes the last word to be counted twice. In the test case, the last word is "you", so it gets counted an extra time → 4 instead of 3. Therefore, the error is that the loop does not check if fscanf succeeded before processing the word.]
            break;
        }
    }
    order(start,number(start));
    for(p=start;;p=p->next){
        printf("%s %d\n",p->word,p->n);
        if(p->next==NULL){
            break;
        }
    }
    fclose(fpin);
    fclose(fpnew);
}