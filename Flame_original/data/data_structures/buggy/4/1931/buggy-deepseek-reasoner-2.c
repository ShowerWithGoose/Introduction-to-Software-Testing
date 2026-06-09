#include<stdio.h>
struct dic{
    char word[20];
    int num;
    struct dic *link;
};
int count = 1; // @@ [Erroneous: count initially set to 1, but first word is stored in base without incrementing count. Should be 0 and incremented when base is assigned.]
int isletter(char c)
{
    if(c >= 'a'&&c<='z')return 1;
    if(c>='A'&&c<='Z')return 2;
    return 0;
}
void lower(char s[])
{
    int i;
    for(i = 0;s[i]!='\0';i++){
        if(s[i]>='A'&&s[i]<='Z')s[i] = s[i]-'A'+'a';
    }
}
void keepletter(char s[])
{
    int i,j;
    for(i = 0,j = 0;s[i]!='\0';i++){
        if(isletter(s[i]) == 2)s[j++] = s[i] -'A'+'a';
        else if(isletter(s[i]) == 1)s[j++] = s[i];
    }
    s[j] = '\0';
}
struct dic *setdot(char s[])
{
    struct dic* tmp = (struct dic*)malloc(sizeof(struct dic)); // @@ [Missing #include <stdlib.h> for malloc]
    strcpy(tmp->word,s); // @@ [Missing #include <string.h> for strcpy]
    tmp->num = 1;
    tmp->link = NULL;
    return tmp;
}
void deletdot(struct dic *p)
{
    struct dic *q = p->link;
    p->link = p->link->link;
    free(q);
    count--;
}

int main()
{
    int i,j;
    FILE *sourceFile;
    char sourceFileName[] = "article.txt";
    int bufferSize = 1024;
    char buffer[bufferSize];
    if ((sourceFile = fopen(sourceFileName, "rb")) == NULL) {
        printf("无法打开源文件\n");
        return -1;
    }
    char tmp[20];
    struct dic *base = NULL,*p,*q;
    while (fgets(buffer, sizeof(buffer), sourceFile)) {
        lower(buffer);
        for(i = 0,j = 0;buffer[i]!='\0';i++){
            if(isletter(buffer[i])){
                tmp[j++] = buffer[i];
            }
            else{
                tmp[j] = '\0';
                if(j != 0){
                    q = setdot(tmp);
                    if(base == NULL){
                        base = q;
                        p = base;
                    }
                    else{
                        while(p->link != NULL&&strcmp(p->link->word,tmp) < 0){ // @@ [Logical error: insertion before head is not considered; if tmp is smaller than base->word, it will be inserted after base, breaking lexicographic order.]
                            p = p->link;
                        }
                        if(p->link!=NULL&&strcmp(p->link->word,tmp)==0){
                            p->link->num++;
                            free(q);
                        }
                        else{
                            q->link = p->link;
                            p->link = q;
                            count++;
                        }
                        p = base;
                    }
                j=0;
                }
            }
        }
    }
    q = setdot(base->word); // @@ [Erroneous: duplicates the first word stored in base, will re-add it incorrectly.]
    strcpy(tmp,base->word);
    while(p->link != NULL&&strcmp(p->link->word,tmp) < 0){
        p = p->link;
    }
    if(p->link!=NULL&&strcmp(p->link->word,tmp)==0){
        p->link->num++;
        free(q);
    }
    else{
        q->link = p->link;
        p->link = q;
        count++;
    }
    p = base->link; // @@ [Erroneous: skip the first node (base) when printing, so base is never printed.]
    for(i = 0;i <count;i++){ // @@ [Erroneous: loop count times but p starts from base->link; if count==num_words, will miss base and may access NULL after the last node.]
        printf("%s %d\n",p->word,p->num);
        p=p->link;
    }
    if (fclose(sourceFile) != 0) {
        printf("无法正确关闭文件\n");
        return -1;
    }
    return 0;
}