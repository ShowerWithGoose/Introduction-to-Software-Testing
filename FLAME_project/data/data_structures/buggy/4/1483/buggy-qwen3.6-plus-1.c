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
        printf("%c",c); // @@ [The program outputs raw characters from the file, including punctuation and original casing, which violates the output format requirement of only printing word frequencies. This causes the "Buggy Output" to contain the raw text before the actual results.]
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
    printf("\n");
    con[k+1]=' '; // @@ [Index error: should be con[k] = ' ' or similar boundary handling. Writing to k+1 skips the null terminator position potentially, but more importantly, the next line writes to k+2.]
    con[k+2]='\0'; // @@ [Index error: The string termination is placed too far. If k is the current length, con[k] should be set to space or null. Setting con[k+2] to null leaves con[k] and con[k+1] uninitialized or containing garbage/old data, leading to undefined behavior or extra spaces in parsing.]
    puts(con);////////////////////////////////////
    struct wordlist *first=NULL,*p,*q,*pf,*head,*tale,*tt;
    head=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ [Type mismatch: 'struct worklist' is not defined; it should be 'struct wordlist'. This will cause a compilation error.]
    head->word[0]=32;
    head->num=0;
    tale=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ [Type mismatch: 'struct worklist' is not defined; it should be 'struct wordlist'. This will cause a compilation error.]
    memset(tale->word,126,100);
    tale->num=0;
    head->next=tale;
    tt=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ [Type mismatch: 'struct worklist' is not defined; it should be 'struct wordlist'. This will cause a compilation error.]
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
            aword[m+1]='\0'; // @@ [Off-by-one error: The string terminator should be at aword[m], not aword[m+1]. aword[m] contains garbage or old data, causing strcmp to fail or behave unpredictably.]
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
                        q=(struct worklist *)malloc(sizeof(struct wordlist)); // @@ [Type mismatch: 'struct worklist' is not defined; it should be 'struct wordlist'. This will cause a compilation error.]
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