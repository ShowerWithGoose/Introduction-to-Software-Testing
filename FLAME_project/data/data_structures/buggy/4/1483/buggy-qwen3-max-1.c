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
        printf("%c",c); // @@ [The program should not print the input file content to stdout; this violates the output format which requires only word counts.]
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
    printf("\n"); // @@ [This extra newline is part of the erroneous debug output and should not be printed.]
    con[k+1]=' '; // @@ [This writes beyond the last written character (at index k-1), leaving con[k] uninitialized. Should be con[k] = ' '; con[k+1] = '\0';]
    con[k+2]='\0'; // @@ [Incorrect null termination; should be con[k] = '\0' after setting con[k] = ' ' or directly con[k] = '\0'.]
    puts(con);//////////////////////////////////// // @@ [Debug output that should not appear in final output.]
    struct wordlist *first=NULL,*p,*q,*pf,*head,*tale,*tt;
    head=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ [Typo: 'worklist' should be 'wordlist'. This causes undefined behavior due to incorrect type cast.]
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
            aword[m+1]='\0'; // @@ [Off-by-one error: should be aword[m] = '\0'; because m is already the count of characters copied.]
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
                    p->num++; // @@ [This increments count for existing word, but the loop continues unnecessarily; however, more critically, the sentinel nodes are compared as real words.]
                }
            }
            //printf("marker flag=%d\n",flag);
            if(flag==0){
                //printf("该词语从未出现\n");
                for(pf=head,p=head->next;p!=tt;p=p->next,pf=pf->next){
                    //printf("开始寻找合适插入位置\n");
                    if((strcmp(aword,pf->word)>0)&&strcmp(aword,p->word)<0){ // @@ [Logic flaw: comparing against sentinel nodes (head and tt) which contain non-word data (space and tildes), leading to incorrect insertion order or missed insertions.]
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
    for(p=head->next;p!=tale;p=p->next){ // @@ [Loop stops at 'tale', but 'tt' is the actual end sentinel; also, 'tale' itself contains invalid word data (filled with '~'), so if any word is lexicographically greater than all others, it might not be printed or cause issues. Moreover, the sentinels themselves may be printed if logic fails.]
        printf("%s %d\n",p->word,p->num);
    }
    return 0;
}