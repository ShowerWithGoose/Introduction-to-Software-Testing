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
    in=fopen("article.txt","r");
    char t;
    int q;
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){
        if(isdigit(t)){ // @@ [Error: isdigit() checks for digits, but the problem requires letters only. Should use isalpha() to check for letters.]
            t=tolower(t);
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
            strcpy(w,""); // @@ [Error: This line is problematic because it attempts to copy an empty string to w, but w is a char array and this operation is valid. However, the logic is flawed: after processing a word, w should be reset to empty, but the strcpy here is unnecessary and may cause issues if w is not properly null-terminated. More importantly, the condition for detecting word boundaries is incorrect, leading to missing words and incorrect counts.]
        }    
    }
    qsort(wordlist,i,sizeof(struct node),cmp);
    for(int p=0;p!=i;p++){
        printf("%s %d\n",wordlist[p].word,wordlist[p].count);
    }
    return 0;
 }