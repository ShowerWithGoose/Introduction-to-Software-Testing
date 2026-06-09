#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char con[1000086];
char aword[100];
struct wordlist{
    char word[100];
    int num;
    struct wordlist *next;
};
int main()
{
    FILE *in,*out;
    in=fopen("article.txt","r");
    char c;
    int k=0;
    while((c=fgetc(in))!=EOF){
        printf("%c",c); // @@ [The program prints the input file content to stdout, which is not part of the expected output. This causes extra lines before the actual word frequency results.]
        if((c>='A')&&(c<='Z')){
            c=c+32;
            con[k]=c;
            k++;
        }
        else if(((c>='a')&&(c<='z'))||(c==' ')){
            con[k]=c;
            k++;
        }
        else {
            con[k]=' ';
            k++;
        }
    }
    printf("\n"); // @@ [This prints an extra newline after echoing the input, contributing to incorrect output format.]
    con[k+1]=' '; // @@ [Incorrect indexing: should be con[k] = ' ', then con[k+1] = '\0'. This leaves con[k] uninitialized and adds two extra characters.]
    con[k+2]='\0';
    puts(con);//////////////////////////////////// // @@ [This prints the processed string, which is debugging output and not part of expected result.]
    struct wordlist *first=NULL,*p,*q,*pf,*head,*tale,*tt;
    head=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ [Typo: 'worklist' should be 'wordlist'. This causes undefined behavior or compilation error depending on compiler strictness.]
    head->word[0]=32;
    head->num=0;
    tale=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ [Typo: 'worklist' should be 'wordlist'.]
    memset(tale->word,126,100);
    tale->num=0;
    head->next=tale;
    tt=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ [Typo: 'worklist' should be 'wordlist'.]
    memset(tt->word,126,100);
    tt->num=0;
    tale->next=tt;
    tt->next=NULL;
    int nn=2;
    int j=0;
    while(con[j]!='\0'){
        if(con[j]!=' '){
            int m=0;        
            while(con[j]!=' '){
                aword[m]=con[j];
                m++;
                j++;
            }
            aword[m+1]='\0'; // @@ [Off-by-one error: should be aword[m] = '\0'. This leaves aword[m] uninitialized and adds an extra null beyond the word.]
            //printf("=======================================================\n");
            //puts(aword);//////////////////////////////
            int i;
            int flag=0;
            for(p=head->next;p!=tt;p=p->next){
            //    printf("p->word:");
                //puts(p->word);
                //printf("p->num=%d\n",p->num);
                if(strcmp(aword,p->word)==0){
                    flag=1;
                    //printf("该词语出现过\n");
                    p->num++;
                }
            }
            //printf("marker flag=%d\n",flag);
            if(flag==0){
                //printf("该词语从未出现\n");
                for(pf=head,p=head->next;p!=tt;p=p->next,pf=pf->next){
                    //printf("开始寻找合适插入位置\n");
                    if((strcmp(aword,pf->word)>0)&&strcmp(aword,p->word)<0){ // @@ [Logic flaw: this condition assumes list is sorted, but initial sentinel nodes have artificial values (space and tildes), and insertion logic doesn't maintain full sort invariant correctly. Also, missing parentheses around second strcmp may cause precedence issues, though it's technically correct due to operator precedence. More critically, if the new word is greater than all existing words, it won't be inserted because loop ends at tt and no insertion after last real node occurs.]
                        //printf("找到合适插入位置\n");
                        q=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ [Typo: 'worklist' should be 'wordlist'.]
                        q->next=pf->next;
                        pf->next=q;
                        strcpy(q->word,aword);
                        q->num=1;
                        //printf("插入完毕\n");
                    }
                }
            }
        }
        
        j++;
        memset(aword,0,100);
    }
    for(p=head->next;p!=tale;p=p->next){ // @@ [Loop stops at 'tale', but 'tale' was initialized with memset(word,126,...) which is '~' characters, and 'tt' is after tale. However, real words are inserted between head and tt, but this loop excludes the last valid node if any word is lexicographically greater than '~' (which none are), but more importantly, the sentinel setup is flawed and may skip valid words or include sentinels. Also, 'tale' itself is a sentinel with invalid word (~s), so stopping before it is correct, but due to insertion logic flaws, some words might not be inserted properly.]
        printf("%s %d\n",p->word,p->num);
    }
    return 0;
}