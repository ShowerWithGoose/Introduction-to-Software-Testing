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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc will cause undefined behavior. However, this is not a compilation error. The actual compilation error stems from logic misuse of types and uninitialized variables leading to undefined behavior at runtime, but the prompt says "Compilation Error". However, the real issue causing potential build/runtime failure is using `isdigit` instead of `isalpha` and incorrect word parsing logic. But strictly for compilation: no syntax error. Yet the test output "/bin/sh: 1: gcc: not found" suggests environment issue, but per problem context, we must find code errors. The true logical errors are below.]
    char t;
    int q;
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){ // @@ [fgetc returns int, not char. Assigning to char may cause EOF comparison to fail because EOF is outside char range. This can lead to infinite loop or missed EOF, but it's a semantic/logical error, not compilation. However, many compilers warn; still compiles.]
        if(isdigit(t)){ // @@ [Problem requires processing letters only, but this checks digits. Should be isalpha(t). This causes words made of letters to be ignored and digits treated as word characters, violating spec.]
            t=tolower(t); // @@ [tolower on digit is unnecessary and incorrect per problem (only letters should be considered). Also, tolower expects unsigned char or EOF; passing digit is harmless but logically wrong.]
            w[j]=t;
            j++;
            q=0;
        }else if(q==0){ // @@ [q is uninitialized on first entry to loop; using q==0 is undefined behavior. Also, logic for word termination is flawed: only processes word when transitioning from digit to non-digit, but words are letter sequences.]
            q=1;
            j=0;
            int y=0;
            for(int x=0;x!=i;x++){ // @@ [i is global and uninitialized (default 0), so loop runs 0 times initially, which is okay, but after first word, i increments. However, w may contain garbage if j==0 (empty word) because previous branch may not have run. Also, strcpy(w,"") doesn't nullify entire array, just sets first char to '\0', but that's okay for strcmp.]
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