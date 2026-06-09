#include<stdio.h>
#include<string.h>
int main() {
    FILE *in=fopen("article.txt","r"); // @@ missing check if fopen returns NULL
    char c,word[77][17]; // @@ c should be int to properly handle EOF
    int i=0,j=0,flag=0,book[77]= {0};
    while((c=fgetc(in))!=EOF) { // @@ using char for c may cause infinite loop if EOF is not correctly compared
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
    } // @@ missing handling of the last word if file ends with a letter (no non-letter after it)
    for(int t=0; t<i; t++) { // @@ output not in lexicographic order; need to sort before printing
        if(book[t]==0) {
            int num=0;
            for(int p=t; p<i; p++) {
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