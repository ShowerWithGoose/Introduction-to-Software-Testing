#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100000
#define tolower(c)  (c>='A'&&c<='Z' ? 'a'-'A'+c:c)
struct node{
    char word[MAXWORD];
    int count;
    struct node *link;
}; 
struct node *Wordlist=NULL;
int getWord(FILE *fp,char *word);
int searchWord(char *w);
int insertWord(struct node *p,char *w);
int flag;

int main(){
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;
    if((bfp=fopen("article.txt","r"))==NULL){
        printf("article can't open!\n");
        return -1;
    }
    while(getWord(bfp,word)!=-1){
        if(isalpha(word[0])){
            if(searchWord(word)==-1){
                printf("Memory is full!\n");
                return -1;
               }
        }
    }
    for(p=Wordlist;p!=NULL;p=p->link)
        printf("%s %d\n",p->word,p->count);
    

    return 0;
}
int searchWord(char *w){
    struct  node *p,*q=NULL;
    for(p=Wordlist;p!=NULL;q=p,p=p->link){
        if(strcmp(w,p->word)<0)
            break;
        else if(strcmp(w,p->word)==0){
            p->count++;
            return 0;    
        }
    }
    return insertWord(q,w);
}
int insertWord(struct node *p,char *w){
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    if(q==NULL)return -1;
    strcpy(q->word,w);
    q->count=1;
    q->link=NULL;
    if(Wordlist==NULL)//Ϊգ½ڵΪͷڵ
        Wordlist=q;
    else if(p==NULL){//½ڵǰһΪ
        q->link=Wordlist;
        Wordlist=q;//½ڵ뵽ͷ
    }
    else{
        q->link=p->link;
        p->link=q;
    }
    return 0;
}
int getWord(FILE *fp,char *word){ // @@ The logic for parsing words is incorrect. It treats any non-letter character (like digits or punctuation) as a delimiter similar to space/newline, but fails to handle sequences correctly. Specifically, it returns a word when it hits a space or newline, but if it hits a digit (like in "since1972"), it doesn't return the accumulated word "since", nor does it skip the digit properly to continue reading. It just continues the loop, potentially appending nothing or handling state incorrectly. More critically, the problem states a word is ONLY letters. "since1972" should be parsed as "since". The current code reads 's','i','n','c','e', then hits '1'. '1' is not alpha, not space, not newline. It does nothing and loops. Then it reads '9', same. Then '7', same. Then '2', same. Then '.'. Same. Then ' '. Space! It terminates the word. So it extracts "since". This part might seem okay for extraction, BUT:
    int i=0;
    while(fscanf(fp,"%c",&word[i])!=EOF){
        if((word[i]>='A'&&word[i]<='Z')||(word[i]>='a'&&word[i]<='z')){
            flag = 0;
            word[i] = tolower(word[i]);
            i++;
        }else if(word[i]==' '){        //\n
            word[i]='\0';
            return 1;
        }else if(word[i]=='\n'){
            if(flag==0){
                word[i]='\0';
                flag = 1;
            }
            return 1;
        }
        // @@ Missing handling for other non-alpha characters (digits, punctuation). 
        // If we encounter a digit or punctuation after letters, we should terminate the current word (if any) and skip the non-letter.
        // Currently, if we have "since1972", it reads 's'..'e', i=5. Then '1'. Not alpha, not space, not newline. Loop continues.
        // Next char '9'. Same.
        // ...
        // Next char '.'. Same.
        // Next char ' '. Space. word[5] becomes '\0'. Returns "since". This actually works for extraction IF the next call starts fresh.
        // HOWEVER, look at the next iteration. fscanf reads the NEXT character.
        // The issue is likely how `flag` and newlines interact or how consecutive delimiters are handled, OR simply that the logic is fragile.
        // Let's look at the expected output vs buggy output.
        // Buggy: c 11, since 10, sincec 4.
        // Expected: c 15, since 15.
        // Input: "C since1972.C since1972.C ..."
        // Let's trace "C since1972.C"
        // 1. 'C'. Alpha. word="c". i=1.
        // 2. ' '. Space. word[1]='\0'. Return "c". Correct.
        // 3. Next call. 's'. Alpha. word="s". i=1.
        // 4. 'i'. Alpha. word="si". i=2.
        // 5. 'n'. Alpha. word="sin". i=3.
        // 6. 'c'. Alpha. word="sinc". i=4.
        // 7. 'e'. Alpha. word="since". i=5.
        // 8. '1'. Not alpha, space, newline. Loop continues.
        // 9. '9'. Loop continues.
        // 10. '7'. Loop continues.
        // 11. '2'. Loop continues.
        // 12. '.'. Loop continues.
        // 13. 'C'. Alpha. word[5]='c'. word="sincec". i=6.  <-- ERROR HERE. The digit/punctuation did not terminate the previous word "since". Instead, the next letter 'C' was appended to it.
        // 14. ' '. Space. word[6]='\0'. Return "sincec". <-- This explains "sincec" in output.
        
        // To fix this: When a non-alpha character is encountered, if we have already collected letters (i > 0), we should terminate the word, return it, and leave the file pointer at the non-alpha character (or consume it depending on design). 
        // Since fscanf consumes the character, we can't "push back" easily without ungetc.
        // Better approach: If non-alpha is found and i>0, terminate word, return 1. But the character is already consumed by fscanf.
        // The next call to getWord will start with the NEXT character. So the '1' was consumed, '9' consumed... 'C' consumed.
        // Wait, if I return when I hit '1', I lose the '1'. The next call starts at '9'. That's fine, we want to skip digits.
        // But if I return "since" when I hit '1', the '1' is consumed. Next call reads '9'. Not alpha. Loop. Reads '7'. Loop. Reads '2'. Loop. Reads '.'. Loop. Reads 'C'. Alpha. Starts new word "c".
        // This would produce "since" and "c". Correct.
        
        // So the error is that the code DOES NOT return/terminate when it hits a non-alpha, non-space, non-newline character if i > 0.
    }
    return -1;
}