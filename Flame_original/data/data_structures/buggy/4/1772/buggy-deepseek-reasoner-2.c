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
            word[i++][j]='\0'; // @@ Error: Should only add null terminator when j>0, otherwise creates empty word.
            flag=1;
            j=0;
        } else;
    } // @@ Error: Missing finalization of last word if file ends with a letter (no trailing non-letter). Should add after loop: if(j>0) { word[i][j]='\0'; i++; }
    for(int t=0; t<i; t++) { // @@ Error: Output not in lexicographical order. Need to sort the `word` array (e.g., using qsort) before the counting/output loop.
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