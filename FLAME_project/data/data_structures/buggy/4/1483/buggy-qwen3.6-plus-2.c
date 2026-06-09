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
        printf("%c",c); // @@ The problem requires outputting only the word frequency results, not the original file content or debug information. This line causes extra output leading to Wrong Answer.
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
    printf("\n"); // @@ The problem requires outputting only the word frequency results. This newline and subsequent debug output cause Wrong Answer.
    con[k+1]=' '; // @@ Logic error: should be con[k] = '\0' to terminate the string properly after processing all characters. Index k is already at the next free position. Writing to k+1 leaves con[k] uninitialized/undefined, potentially causing issues in string processing.
    con[k+2]='\0'; // @@ Logic error: see above. The string termination is incorrect. It should simply be con[k] = '\0'.
    puts(con);//////////////////////////////////// // @@ The problem requires outputting only the word frequency results. This line prints the processed buffer, causing extra output and Wrong Answer.
    struct wordlist *first=NULL,*p,*q,*pf,*head,*tale,*tt;
    head=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ Compilation Error: 'struct worklist' is undefined. The struct is named 'struct wordlist'. This will prevent the code from compiling.
    head->word[0]=32;
    head->num=0;
    tale=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ Compilation Error: 'struct worklist' is undefined. Should be 'struct wordlist'.
    memset(tale->word,126,100);
    tale->num=0;
    head->next=tale;
    tt=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ Compilation Error: 'struct worklist' is undefined. Should be 'struct wordlist'.
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
            aword[m+1]='\0'; // @@ Logic error: Array index out of bounds/incorrect termination. If the word has length m (indices 0 to m-1), the null terminator should be at aword[m]. aword[m+1] leaves aword[m] uninitialized, which can cause strcmp to fail or read garbage.
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
                    if((strcmp(aword,pf->word)>0)&&strcmp(aword,p->word)<0){
                        //printf("找到合适插入位置\n");
                        q=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ Compilation Error: 'struct worklist' is undefined. Should be 'struct wordlist'.
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
    for(p=head->next;p!=tale;p=p->next){
        printf("%s %d\n",p->word,p->num);
    }
    return 0;
}