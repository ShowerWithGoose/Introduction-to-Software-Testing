#include<stdio.h>
#include<string.h>
int main() {
    FILE *in=fopen("article.txt","r");
    char c,word[77][17]; // @@ [c should be declared as int to correctly store the return value of fgetc and compare with EOF; using char may cause type mismatch warnings/errors in strict compilation]
    int i=0,j=0,flag=0,book[77]= {0};
    while((c=fgetc(in))!=EOF) {
        if(c<=90&&c>=65) {
            flag=0;
            word[i][j++]=c+32;
        } else if(c<=122&&c>=97) {
            flag=0;
            word[i][j++]=c;
        } else if(flag==0) {
            word[i++][j]='\0';
            flag=1;
            j=0;
        } else;
    }
    for(int t=0; t<i; t++) { // @@ [Declaring loop variable 't' inside the for statement is a C99 feature; it will cause a compilation error in C89/ANSI C environments]
        if(book[t]==0) {
            int num=0;
            for(int p=t; p<i; p++) { // @@ [Declaring loop variable 'p' inside the for statement is a C99 feature; it will cause a compilation error in C89/ANSI C environments]
                if(strcmp(word[t],word[p])==0) {
                    num++;
                    book[p]=1;
                }
            }
            printf("%s %d\n",word[t],num);
        }
    }
    fclose(in);
    return 0;
}