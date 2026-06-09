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
        printf("%c",c); // @@ Error: This prints the input file content to screen, which is not part of the required output. Output should only contain word frequencies.
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
    printf("\n"); // @@ Error: This prints an extra newline not required in output.
    con[k+1]=' ';
    con[k+2]='\0';
    puts(con); // @@ Error: This prints the entire processed content, which is not part of the required output. Only word frequency lines should be printed.
    struct wordlist *first=NULL,*p,*q,*pf,*head,*tale,*tt;
    head=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ Error: 'struct worklist' is a typo; the defined struct is 'struct wordlist'. This causes a compilation error.
    head->word[0]=32;
    head->num=0;
    tale=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ Error: Same typo 'worklist' instead of 'wordlist'.
    memset(tale->word,126,100);
    tale->num=0;
    head->next=tale;
    tt=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ Error: Same typo 'worklist' instead of 'wordlist'.
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
            aword[m+1]='\0'; // @@ Error: The null terminator should be at aword[m], not aword[m+1], because after the loop m points to the index after the last character. This can cause the string to be incorrectly terminated.
            int i;
            int flag=0;
            for(p=head->next;p!=tt;p=p->next){
                if(strcmp(aword,p->word)==0){
                    flag=1;
                    p->num++;
                }
            }
            if(flag==0){
                for(pf=head,p=head->next;p!=tt;p=p->next,pf=pf->next){
                    if((strcmp(aword,pf->word)>0)&&strcmp(aword,p->word)<0){
                        q=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ Error: Same typo 'worklist' instead of 'wordlist'.
                        q->next=pf->next;
                        pf->next=q;
                        strcpy(q->word,aword);
                        q->num=1;
                        // @@ Error: After insertion, the loop should break to prevent inserting the same word multiple times. Missing 'break;' statement.
                    }
                }
            }
        }
        
        j++;
        memset(aword,0,100);
    }
    for(p=head->next;p!=tale;p=p->next){
        printf("%s %d\n",p->word,p->num);
    }
    return 0;
}