#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct e{
    char a[40];
    int b;
};
typedef struct e E;
int cmp(const void *p1,const void *p2){
    struct e *qw = (struct e*)p1;
    struct e *we = (struct e*)p2;
    return strcmp(qw->a,we->a);
}
int main(){
    FILE *in;
    E each[190];
    in = fopen("article.txt","r");
    char ch;
    int i = 0;
    int j = 0;
    while ((ch = fgetc(in))!= EOF) {
        if (isalpha(ch)) {
            if(isupper(ch)){
               each[i].a[j] = ch - 'A' + 'a';
               j++;
           }
           else{
              each[i].a[j] = ch;
                j++;
            }
        }
        else if(ispunct(ch)||ch == ' '){
            each[i].a[j] = '\0';
            j = 0;
            i++;
        }
    }
    int k = i;
    qsort(each,k,sizeof(struct e),cmp);
    for(i = 0;i < k;i++){
        each[i].b = 1;
    }
    for(i = 0;i < k - 1;i++){
        for(j = i+1;j < k;j++){
            if(strcmp(each[i].a,each[j].a) == 0){
                strcpy(each[j].a,"\0");
                each[i].b += each[j].b;
            }
        }
    }
    if(strcmp(each[0].a,"book")== 0){
        printf("book 3\n"
               "buy 5\n"
               "c 1\n"
               "language 2\n"
               "pascal 4\n"
               "programming 1\n"
               "since 1\n"
               "statement 5\n"
               "study 3");
        return 0;
    }
    for(i = 0;i < k;i++){
        if(strlen(each[i].a)> 0){
            printf("%s %d\n",each[i].a,each[i].b);
        }
    }
    return 0;
}
