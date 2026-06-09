#include<stdio.h>
#include<string.h>
int main() {
    FILE *in=fopen("article.txt","r");
    char c,word[77][17];
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
    // The program fails to sort the words lexicographically before outputting them.
    // The problem requires output in lexicographical order.
    // The current code outputs words in the order they appear (or are processed), not sorted. @@ Missing sorting step: The words must be sorted lexicographically before counting/printing to meet the output format requirement.
    for(int t=0; t<i; t++) {
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