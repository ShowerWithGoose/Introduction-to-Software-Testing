#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    char word[30];
    int count;
};
struct node wordlist[1000];
int cmp(const void*a,const void*b){
    struct node *pa=(struct node *)a;
    struct node *pb=(struct node *)b;
    if(strcmp(pa->word,pb->word)>0){
        return 1;
    }else{
        return -1;
    }
}
int i;
int main()
{
    FILE *in;
    in=fopen("article.txt","r"); @@ [If the file fails to open, in will be NULL, and subsequent fgetc(in) leads to undefined behavior.]
    char t;
    int q;
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){ @@ [fgetc returns int, not char; assigning to char t may cause EOF comparison failure due to sign extension issues.]
        if(isdigit(t)){ @@ [Problem requires processing letters only, but this checks for digits instead of alphabetic characters.]
            t=tolower(t); @@ [tolower has no effect on digits; also, digits shouldn't be part of words per problem definition.]
            w[j]=t;
            j++;
            q=0;
        }else if(q==0){
            q=1;
            j=0;
            int y=0;
            for(int x=0;x!=i;x++){
                if(strcmp(wordlist[x].word,w)==0){
                    wordlist[x].count++;
                    y=1;
                    break;
                }
            }
            if(y==0){
                strcpy(wordlist[i].word,w);
                wordlist[i].count=1;
                i++;
            }
            strcpy(w,"");
        }    
    }
    qsort(wordlist,i,sizeof(struct node),cmp);
    for(int p=0;p!=i;p++){
        printf("%s %d\n",wordlist[p].word,wordlist[p].count);
    }
    return 0;
 }