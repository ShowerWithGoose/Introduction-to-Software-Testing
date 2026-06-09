#include<stdio.h> // @@ Missing #include <stdlib.h>, <string.h>, <ctype.h> - required for malloc, strcmp, strcpy, etc. (compile error if missing, but runtime also possible if implicit declarations cause issues)
struct dic{
    char word[20];
    int num;
    struct dic *link;
};
int count = 1; // @@ Initial value 1 is arbitrary; not directly runtime error but leads to inconsistent count later.
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
    struct dic* tmp = (struct dic*)malloc(sizeof(struct dic));
    strcpy(tmp->word,s);
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
                        while(p->link != NULL&&strcmp(p->link->word,tmp) < 0){ // @@ Logic fails to insert words that should come before the first node (base->word). The while loop never considers comparing with base->word itself, so the list order becomes incorrect and later causes duplicate insertion and segmentation fault.
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
    }                //创建列表
    q = setdot(base->word); // @@ Creates a duplicate node for the first word (base->word). This insertion is unnecessary and corrupts the list structure and count.
    strcpy(tmp,base->word);
    while(p->link != NULL&&strcmp(p->link->word,tmp) < 0){ // @@ Part of the erroneous duplicate insertion. Uses p which was set to base at end of previous loop, but the traversal may insert the duplicate in the wrong place, leading to duplicate entries and eventually an out-of-bounds access.
        p = p->link;
    }
    if(p->link!=NULL&&strcmp(p->link->word,tmp)==0){
        p->link->num++;
        free(q);
    }
    else{
        q->link = p->link;
        p->link = q;
        count++; // @@ count becomes inconsistent (e.g., 23 instead of 22), causing the output loop to iterate too many times and access invalid memory.
    }
    p = base->link; // @@ Skips the first node (base) in output. Since base is a real word node, this omits the first word from the printed results.
    for(i = 0;i <count;i++){ // @@ Uses an incorrect count (due to duplicate insertion) and iterates more times than the number of nodes in the linked list starting from base->link. This results in accessing a NULL pointer or invalid memory, causing a segmentation fault.
        printf("%s %d\n",p->word,p->num);
        p=p->link;
    }
    if (fclose(sourceFile) != 0) {
        printf("无法正确关闭文件\n");
        return -1;
    }
    return 0;
}